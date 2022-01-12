//
//  TSViewController.m
//  TSGMSDemo_OC
//
//  Created by xiaobing.yao on 2022/01/12.
//  Copyright © 2022 Beijing ToSee Future Network Technology Co., Ltd. All rights reserved.
//

#import "TSViewController.h"
#import <TSGMS/TSGMSKit.h>
#import "TSTableViewCell.h"
#import "NSString+Util.h"


@interface TSViewController () <TSGMSDelegate, UITableViewDelegate, UITableViewDataSource, TSGMSChannelDelegate>

@property (nonatomic, strong) TSGMSKit *tsGMSKit;
@property (nonatomic, strong) TSGMSChannel *gmsChannel;

@property (nonatomic, strong) NSMutableArray *channelMessages;
@property (nonatomic, strong) NSMutableArray *peerMessages;
@property (weak, nonatomic) IBOutlet UITableView *channelTableView;
@property (weak, nonatomic) IBOutlet UITableView *peerTableView;
@property (weak, nonatomic) IBOutlet UITextField *uidTextField;
@property (weak, nonatomic) IBOutlet UIButton *connectButton;
@property (weak, nonatomic) IBOutlet UIButton *disconnectButton;
@property (weak, nonatomic) IBOutlet UITextField *channelIdtextField;
@property (weak, nonatomic) IBOutlet UIButton *joinButton;
@property (weak, nonatomic) IBOutlet UIButton *leaveButton;
@property (weak, nonatomic) IBOutlet UITextField *messageTextField;
@property (weak, nonatomic) IBOutlet UITextField *peerIdTextField;
@property (weak, nonatomic) IBOutlet UISegmentedControl *segmented;
@property (weak, nonatomic) IBOutlet UIButton *sendButton;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *inputContainerBottom;

@end


@implementation TSViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    _channelMessages = [NSMutableArray array];
    _peerMessages = [NSMutableArray array];
    
    _channelTableView.delegate = self;
    _channelTableView.dataSource = self;
    [_channelTableView registerNib:[UINib nibWithNibName:@"TSTableViewCell" bundle:nil] forCellReuseIdentifier:@"TSTableViewCell"];

    _peerTableView.delegate = self;
    _peerTableView.dataSource = self;
    [_peerTableView registerNib:[UINib nibWithNibName:@"TSTableViewCell" bundle:nil] forCellReuseIdentifier:@"TSTableViewCell"];

    //换成你自己的appid
    NSString *appId = @"appId";
    _tsGMSKit = [[TSGMSKit alloc] initWithAppId:appId delegate:self];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyBoardChange:) name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyBoardChange:) name:UIKeyboardWillHideNotification object:nil];
}
-(void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)onClickConnect:(id)sender
{
    NSString *uid = self.uidTextField.text;
    if (!uid.length) {
        return;
    }
    
    NSDate *date = [NSDate date];
    int64_t ts = (int64_t)(date.timeIntervalSince1970 * 1000);
    //换成自己的appId
    NSString *appId = @"appId";
    //换成自己的appKey
    NSString *appKey = @"appKey";
    //计算token
    NSString *tokenStr = [NSString stringWithFormat:@"appId=%@&timestamp=%lld&userId=%@%@", appId, ts, uid, appKey];
    NSString *token = [tokenStr md5Value];
    [self.tsGMSKit loginByToken:token timeStamp:ts userId:uid completion:^(TSGMSLoginErrorCode errorCode) {
        if (errorCode == TSGMSLoginErrorOk) {
            self.connectButton.backgroundColor = [UIColor colorWithRed:1 green:0 blue:0 alpha:0.5];
        }
    }];
}
- (IBAction)onClickDisconnect:(id)sender
{
    __weak typeof(self) weakSelf = self;
    [self.tsGMSKit logoutWithCompletion:^(TSGMSLogoutErrorCode errorCode) {
        if (errorCode == TSGMSLogoutErrorOk) {
            weakSelf.connectButton.backgroundColor = UIColor.whiteColor;
            weakSelf.joinButton.backgroundColor = UIColor.whiteColor;
            weakSelf.gmsChannel = nil;
            [weakSelf.peerMessages removeAllObjects];
            [weakSelf.peerTableView reloadData];
        }
    }];
}
- (IBAction)onClickJoin:(id)sender
{
    NSString *channel = self.channelIdtextField.text;
    if (!channel.length) {
        return;
    }
    if (_gmsChannel == nil) {
        _gmsChannel = [self.tsGMSKit createChannelWithId:channel delegate:self];
    }
    __weak typeof(self) weakSelf = self;
    [_gmsChannel joinWithCompletion:^(TSGMSJoinChannelErrorCode errorCode) {
        if (errorCode == TSGMSJoinChannelErrorOk) {
            weakSelf.joinButton.backgroundColor = [UIColor colorWithRed:1 green:0 blue:0 alpha:0.5];
        }
    }];
}
- (IBAction)onClickLeave:(id)sender
{
    __weak typeof(self) weakSelf = self;
    [_gmsChannel leaveWithCompletion:^(TSGMSLeaveChannelErrorCode errorCode) {
        if (errorCode == TSGMSLeaveChannelErrorOk) {
            weakSelf.joinButton.backgroundColor = UIColor.whiteColor;
            [weakSelf.channelMessages removeAllObjects];
            [weakSelf.channelTableView reloadData];
        }
    }];
}
- (IBAction)onClickSend:(id)sender
{
    NSString *text = _messageTextField.text;
    
    TSGMSMessage *message = [[TSGMSMessage alloc] initWithText:text];
    
    if (_segmented.selectedSegmentIndex == 0) {
        [self sendPeerMessage:message];
    }else {
        [self sendChannelMessage:message];
    }
    
}
- (void)keyBoardChange:(NSNotification *)no {
    if (no.name == UIKeyboardWillShowNotification) {
        CGRect rect = [no.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
        _inputContainerBottom.constant = rect.size.height;
    }
    if (no.name == UIKeyboardWillHideNotification) {
        _inputContainerBottom.constant = 0;
    }
}
- (void)sendPeerMessage:(TSGMSMessage *)message
{
    NSString *peerId = _peerIdTextField.text;
    TSGMSSendMessageOptions *options = [[TSGMSSendMessageOptions alloc] init];
    options.enableOfflineMessaging = true;
    [self.tsGMSKit sendMessage:message toPeer:peerId sendMessageOptions:options completion:^(TSGMSSendPeerMessageErrorCode errorCode) {
        
    }];
}
- (void)sendChannelMessage:(TSGMSMessage *)message
{
    TSGMSSendMessageOptions *options = [[TSGMSSendMessageOptions alloc] init];
    options.enableOfflineMessaging = true;
    [_gmsChannel sendMessage:message options:options completion:^(TSGMSSendChannelMessageErrorCode errorCode) {
        
    }];
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if (tableView == _channelTableView) {
        return self.channelMessages.count;
    }else {
        return self.peerMessages.count;
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    TSTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"TSTableViewCell"];
    NSDictionary *dict;
    if (tableView == _channelTableView) {
        dict = _channelMessages[indexPath.row];
    }else {
        dict = _peerMessages[indexPath.row];
    }
    cell.nameLabel.text = dict[@"name"];
    cell.valueLabel.text = dict[@"value"];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 44;
}
#pragma mark - TSGMSKit
- (void)tsGMSKit:(TSGMSKit *)kit messageReceived:(TSGMSMessage *)message fromPeer:(NSString *)peerId {
    NSDictionary *dict = @{
        @"name":peerId,
        @"value":message.text,
    };
    [self.peerMessages insertObject:dict atIndex:0];
    NSIndexPath *index = [NSIndexPath indexPathForRow:0 inSection:0];
    [self.peerTableView insertRowsAtIndexPaths:@[index] withRowAnimation:UITableViewRowAnimationBottom];
}
#pragma mark - TSGMSChannel
- (void)channel:(TSGMSChannel *)channel messageReceived:(TSGMSMessage *)message fromMember:(TSGMSMember *)member {
    NSDictionary *dict = @{
        @"name":member.userId,
        @"value":message.text,
    };
    [self.channelMessages insertObject:dict atIndex:0];
    NSIndexPath *index = [NSIndexPath indexPathForRow:0 inSection:0];
    [self.channelTableView insertRowsAtIndexPaths:@[index] withRowAnimation:UITableViewRowAnimationBottom];
}
- (void)channel:(TSGMSChannel *)channel memberJoined:(TSGMSMember *)member {
    NSDictionary *dict = @{
        @"name":member.userId,
        @"value":@"加入频道",
    };
    [self.channelMessages insertObject:dict atIndex:0];
    NSIndexPath *index = [NSIndexPath indexPathForRow:0 inSection:0];
    [self.channelTableView insertRowsAtIndexPaths:@[index] withRowAnimation:UITableViewRowAnimationBottom];
}
- (void)channel:(TSGMSChannel *)channel memberLeft:(TSGMSMember *)member {
    NSDictionary *dict = @{
        @"name":member.userId,
        @"value":@"离开频道",
    };
    [self.channelMessages insertObject:dict atIndex:0];
    NSIndexPath *index = [NSIndexPath indexPathForRow:0 inSection:0];
    [self.channelTableView insertRowsAtIndexPaths:@[index] withRowAnimation:UITableViewRowAnimationBottom];
}

@end
