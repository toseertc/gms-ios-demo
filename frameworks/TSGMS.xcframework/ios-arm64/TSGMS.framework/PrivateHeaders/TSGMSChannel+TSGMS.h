//
//  TSGMSChannel+TSGMS.h
//  TSGMS
//
//  Created by yxibng on 2021/6/28.
//

#import "TSGMSChannel.h"
@import SocketIO;

NS_ASSUME_NONNULL_BEGIN
@class TSGMSChannel;
@protocol TSGMSChannelStateDelegate <NSObject>
- (void)onJoinChannel:(TSGMSChannel *)channel;
- (void)onLeaveChannel:(TSGMSChannel *)channel;
@end

@interface TSGMSChannel ()

//是否已经加入频道
@property (nonatomic, assign) BOOL joined;
//是否已经被销毁
@property (nonatomic, assign) BOOL destroyed;

@property (nonatomic, weak) TSGMSStateManager *stateManager;
@property (nonatomic, weak) SocketIOClient *socket;

- (void)onMemberJoined:(TSGMSMember *)member;
- (void)onMemberLeft:(TSGMSMember *)member resaon:(TSGMSMemberLeaveChannelReason)reason;
- (void)onChannelMessageReceived:(NSString *)ChannelId message:(TSGMSMessage *)message fromMember:(TSGMSMember *)member;

@property (nonatomic, weak) id<TSGMSChannelStateDelegate>stateDelegate;


@end
NS_ASSUME_NONNULL_END
