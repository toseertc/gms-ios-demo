//
//  TSGMSInvitationKit.h
//  TS-GMS
//
//  Created by 钟凡 on 2020/6/22.
//

#import <Foundation/Foundation.h>
#import "TSEnumerates.h"

@import SocketIO;

@class TSGMSSocketManager;
@class TSGMSInvitationKit;
@class TSGMSInvitation;

NS_ASSUME_NONNULL_BEGIN

typedef void (^TSGMSInvitationSendBlock)(TSGMSInvitationApiCallErrorCode errorCode);
typedef void (^TSGMSInvitationAcceptBlock)(TSGMSInvitationApiCallErrorCode errorCode);
typedef void (^TSGMSInvitationRefuseBlock)(TSGMSInvitationApiCallErrorCode errorCode);
typedef void (^TSGMSInvitationCancelBlock)(TSGMSInvitationApiCallErrorCode errorCode);

@protocol TSGMSInvitationDelegate <NSObject>

@optional

- (void)gmsInvitationKit:(TSGMSInvitationKit *)invitationKit invitationFailed:(TSGMSInvitation *)invitation errorCode:(TSGMSInvitationErrorCode)errorCode;
/**
 返回给被叫的回调：收到新的呼叫邀请。
 */
- (void)gmsInvitationKit:(TSGMSInvitationKit *)invitationKit invitationArrived:(TSGMSInvitation *)invitation;
/**
 返回给被叫的回调：主叫取消了呼叫邀请。
 */
- (void)gmsInvitationKit:(TSGMSInvitationKit *)invitationKit invitationCanceled:(TSGMSInvitation *)invitation;
/**
 返回给主叫的回调：被叫已接受呼叫邀请。
 */
- (void)gmsInvitationKit:(TSGMSInvitationKit *)invitationKit invitationAccept:(TSGMSInvitation *)invitation;
/**
 返回给主叫的回调：呼叫邀请过程失败。
 */
- (void)gmsInvitationKit:(TSGMSInvitationKit *)invitationKit invitationRefused:(TSGMSInvitation *)invitation;

@end


@interface TSGMSInvitation: NSObject

/**
 User ID of the Invitationer.
 */
@property (nonatomic, copy) NSString *inviter;
/**
 User ID of the Invitationee.
 */
@property (nonatomic, copy) NSString *invitee;

/**
 The Invitation invitation content set by the Invitationer.
 */
@property (nonatomic, copy, nullable) NSString *requestInfo;
/**
 The Invitation invitation content set by the Invitationee.
 */
@property (nonatomic, copy, nullable) NSString *responseInfo;

/**
 The state of the outgoing Invitation invitation. See TSGMSInvitationState.
 */
@property (nonatomic, assign) TSGMSInvitationState state;

- (instancetype)initWithInviter:(NSString *)inviter invitee:(NSString *)invitee;

@end


@interface TSGMSInvitationKit : NSObject

@property (nonatomic, weak) id<TSGMSInvitationDelegate> delegate;

- (void)sendInvitation:(TSGMSInvitation *)invitation completion:(TSGMSInvitationSendBlock)completion;
- (void)cancelInvitation:(TSGMSInvitation *)invitation completion:(TSGMSInvitationCancelBlock)completion;

- (void)acceptInvitation:(TSGMSInvitation *)invitation completion:(TSGMSInvitationAcceptBlock)completion;
- (void)refuseInvitation:(TSGMSInvitation *)invitation completion:(TSGMSInvitationRefuseBlock)completion;

@end

NS_ASSUME_NONNULL_END
