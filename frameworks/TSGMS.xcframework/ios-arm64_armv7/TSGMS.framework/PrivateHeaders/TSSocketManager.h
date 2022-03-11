//
//  TSSocketManager.h
//  TSGMS
//
//  Created by yxb on 2022/3/1.
//

#import <Foundation/Foundation.h>
@import SocketIO;

NS_ASSUME_NONNULL_BEGIN

@class TSSocketManager;

@protocol TSSocketMessageDelegate <NSObject>

//断开连接回调
- (void)socketManager:(TSSocketManager *)socketManager onDisconnect:(NSArray *)params;
//断开连接原因回调
- (void)socketManager:(TSSocketManager *)socketManager onDisconnectReason:(NSArray *)params;
//登录成功消息
- (void)socketManager:(TSSocketManager *)socketManager onLoginSuccess:(NSArray *)params;
//收到频道属性变更
- (void)socketManager:(TSSocketManager *)socketManager onChannelAttributesUpdated:(NSArray *)params;
//收到用户在线状态变更
- (void)socketManager:(TSSocketManager *)socketManager onPeersOnlineStatusChanged:(NSArray *)params;
//收到用户属性变更的消息
- (void)socketManager:(TSSocketManager *)socketManager onPeersUserAttributesChanged:(NSArray *)params;
//收到点对点消息
- (void)socketManager:(TSSocketManager *)socketManager onMessageToPeerReceived:(NSArray *)params;
//收到呼叫邀请
- (void)socketManager:(TSSocketManager *)socketManager onInvitationNotify:(NSArray *)params;
//频道人数改变
- (void)socketManager:(TSSocketManager *)socketManager onChannelMemberCount:(NSArray *)params;
//用户加入频道
- (void)socketManager:(TSSocketManager *)socketManager onMemberJoined:(NSArray *)params;
//用户离开频道
- (void)socketManager:(TSSocketManager *)socketManager onMemberLeft:(NSArray *)params;
//收到频道消息
- (void)socketManager:(TSSocketManager *)socketManager onChannelMessageReceived:(NSArray *)params;

@end



@protocol TSSocketManagerDelegate <NSObject>

- (void)socketManager:(TSSocketManager *)socketManager onConnectTimeout:(NSArray *)params;
- (void)socketManager:(TSSocketManager *)socketManager onSocketChange:(SocketIOClient *)socket;

@end





@interface TSSocketManager : NSObject

@property (nonatomic, weak) id<TSSocketMessageDelegate> messageDelegate;
@property (nonatomic, weak) id<TSSocketManagerDelegate> delegate;

@property (nonatomic, weak, readonly) SocketIOClient *socket;
@property (nonatomic, copy, readonly) NSString *url;
@property (nonatomic, copy, readonly) NSDictionary *config;

- (SocketIOClient *)createSocketWithUrl:(NSString *)url config:(NSDictionary *)config;

- (void)connect;
- (void)disconnect;
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
