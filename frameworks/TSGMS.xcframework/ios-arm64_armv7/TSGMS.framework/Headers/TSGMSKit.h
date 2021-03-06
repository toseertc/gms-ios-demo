//
//  TSGMSKit.h
//  TS-GMS
//
//  Created by yxibng on 2020/5/6.
//

#import "TSChannelMemberCount.h"
#import "TSEnumerates.h"
#import "TSGMSAttribute.h"
#import "TSGMSUserAttributes.h"
#import "TSGMSChannel.h"
#import "TSGMSChannelAttributeOptions.h"
#import "TSGMSInvitationKit.h"
#import "TSGMSMember.h"
#import "TSGMSMessage.h"
#import "TSGMSPeerOnlineStatus.h"
#import "TSGMSSendMessageOptions.h"
#import "TSGMSOptions.h"

#import <Foundation/Foundation.h>

@class TSGMSKit;

NS_ASSUME_NONNULL_BEGIN

typedef void (^TSGMSLoginBlock)(TSGMSLoginErrorCode errorCode);
typedef void (^TSGMSLogoutBlock)(TSGMSLogoutErrorCode errorCode);
typedef void (^TSGMSSendPeerMessageBlock)(TSGMSSendPeerMessageErrorCode errorCode);
typedef void (^TSChannelMemberCountBlock)(NSArray<TSChannelMemberCount *> *_Nullable channelMemberCounts, TSGMSChannelMemberCountErrorCode errorCode);
typedef void (^TSGMSQueryPeersOnlineBlock)(NSArray<TSGMSPeerOnlineStatus *> *_Nullable peerOnlineStatus, TSGMSQueryPeersOnlineErrorCode errorCode);
typedef void (^TSGMSQueryPeersBySubscriptionOptionBlock)(NSArray<NSString *> *_Nullable peers, TSGMSPeerSubscriptionStatusErrorCode errorCode);

#pragma mark - channel attributes -
/**
 Returns the result of the [setLocalUserAttributes]([TSGMSKit setChannel:Attributes:Options:completion:]) <p><li><i>errorCode:</i> See TSGMSProcessAttributeErrorCode.
 */
typedef void (^TSGMSSetChannelAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);
/**
 Returns the result of the [addOrUpdateChannelAttributes]([TSGMSKit addOrUpdateChannel:Attributes:Options:completion:]) method call. <p><li><i>errorCode:</i> See TSGMSProcessAttributeErrorCode.
 */
typedef void (^TSGMSAddOrUpdateChannelAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);
/**
 Returns the result of the [deleteChannelAttributesByKeys]([TSGMSKit deleteChannel:AttributesByKeys:Options:completion:]) method call. <p><li><i>errorCode:</i> TSGMSProcessAttributeErrorCode.
 */
typedef void (^TSGMSDeleteChannelAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [clearChannelAttributesWithCompletion]([TSGMSKit clearChannel:Options:AttributesWithCompletion:]) method call. <p><li><i>errorCode:</i> See TSGMSProcessAttributeErrorCode.
 */
typedef void (^TSGMSClearChannelAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [getChannelAttributes]([TSGMSKit getChannelAllAttributes:completion:]) or the [getChannelAttributesByKeys]([TSGMSKit getChannelAttributes:ByKeys:completion:]) method call. <p><li><i>attributes:</i> An array of TSGMSChannelAttibute. See TSGMSChannelAttibute. <p><li><i>errorCode:</i> See TSGMSProcessAttributeErrorCode.
 */
typedef void (^TSGMSGetChannelAttributesBlock)(NSArray<TSGMSAttribute *> *_Nullable attributes, TSGMSProcessAttributeErrorCode errorCode);

#pragma mark - user attributes -
/**
 Returns the result of the [setLocalUserAttributes]([TSGMSKit setLocalUserAttributes:completion:]) <p><li><i>errorCode:</i> See TSGMSProcessAttributeErrorCode.
 */
typedef void (^TSGMSSetLocalUserAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [addOrUpdateLocalUserAttributes]([TSGMSKit addOrUpdateLocalUserAttributes:completion:]) method call. <p><li><i>errorCode:</i> See TSGMSProcessAttributeErrorCode.
 */
typedef void (^TSGMSAddOrUpdateLocalUserAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [deleteLocalUserAttributesByKeys]([TSGMSKit deleteLocalUserAttributesByKeys:completion:]) method call. <p><li><i>errorCode:</i> TSGMSProcessAttributeErrorCode.
 */
typedef void (^TSGMSDeleteLocalUserAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [clearLocalUserAttributesWithCompletion]([TSGMSKit clearLocalUserAttributesWithCompletion:]) method call. <p><li><i>errorCode:</i> See TSGMSProcessAttributeErrorCode.
 */
typedef void (^TSGMSClearLocalUserAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);

/**
 Returns the result of the [getUserAttributes]([TSGMSKit getUserAllAttributes:completion:]) or the [getUserAttributesByKeys]([TSGMSKit getUserAttributes:ByKeys:completion:]) method call. <p><li><i>attributes:</i> An array of RtmAttibutes. See TSGMSAttribute. <p><li><i>userId:</i> The User ID of the specified user. <p><li><i>errorCode:</i> See TSGMSProcessAttributeErrorCode.
 */
typedef void (^TSGMSGetUserAttributesBlock)(NSArray<TSGMSAttribute *> *_Nullable attributes, NSString *userId, TSGMSProcessAttributeErrorCode errorCode);

typedef void(^TSGMSBatchFetchPeersUserAttributesBlock) (NSArray<TSGMSUserAttributes *> *_Nullable peersUserAttributes,
                                                        TSGMSQueryPeersOnlineErrorCode errorCode);

/**
 Returns the result of the [renewToken]([TSGMSKit renewToken:completion:]) method call. <p><li><i>token</i> Your new Token. <li><i>errorCode:</i> See TSGMSRenewTokenErrorCode.
 */
typedef void (^TSGMSRenewTokenBlock)(NSString *token, TSGMSRenewTokenErrorCode errorCode);

#pragma mark - onlin status -
/**
 Returns the result of the [subscribePeersOnlineStatus]([TSGMSKit subscribePeersOnlineStatus:completion:]) or [unsubscribePeersOnlineStatus]([TSGMSKit unsubscribePeersOnlineStatus:completion:]) method call. <p><i>errorCode:</i> See TSGMSPeerSubscriptionStatusErrorCode.
 */
typedef void (^TSGMSSubscriptionRequestBlock)(TSGMSPeerSubscriptionStatusErrorCode errorCode);

#pragma mark -

@protocol TSGMSDelegate <NSObject>
@optional

- (void)tsGMSKit:(TSGMSKit *)kit connectionStateChanged:(TSGMSConnectionState)state reason:(TSGMSConnectionChangeReason)reason;
- (void)tsGMSKit:(TSGMSKit *)kit peersOnlineStatusChanged:(NSArray<TSGMSPeerOnlineStatus *> *)onlineStatus;
///?????????????????????
- (void)tsGMSKit:(TSGMSKit *)kit messageReceived:(TSGMSMessage *)message fromPeer:(NSString *)peerId;
///token????????????????????????????????????
- (void)tsGMSKitTokenDidExpire:(TSGMSKit *)kit;


/// ???????????? subscribePeersUserAttribes: ????????????????????????????????????
/// @param kit TSGMSKit ??????
/// @param peersUserAttributes  ?????????????????????TSGMSUserAttributes ??????
- (void)tsGMSKit:(TSGMSKit *)kit peersUserAttributesChanged:(NSArray<TSGMSUserAttributes*>*)peersUserAttributes;

@end

@interface TSGMSKit : NSObject

@property (nonatomic, weak) id<TSGMSDelegate> delegate;


/// ?????? TSGMSKit ??????
/// @param appId ??????id
/// @param delegate ??????sdk????????? TSGMSDelegate ????????????
- (instancetype)initWithAppId:(NSString *)appId delegate:(id<TSGMSDelegate> _Nullable)delegate;

/// ?????? TSGMSKit ??????, ???????????????????????????
/// @param appId ??????id
/// @param delegate ??????sdk????????? TSGMSDelegate ????????????
/// @param options ??????options.envConfig.apiServer????????????api????????????????????????sdk???????????????????????????????????????????????????????????????ip???????????????
/// ??????????????? options.envConfig.apiServer ????????????sdk???????????????????????????????????????????????????????????? nil???
- (instancetype _Nullable)initWithAppId:(NSString *)appId delegate:(id<TSGMSDelegate> _Nullable)delegate options:(TSGMSOptions *_Nullable)options;

#pragma mark - login


/// ??????????????????
/// @param token ??????token
/// @param timeStamp ????????????????????????
/// @param userId ????????????ID
/// @param completionBlock ????????????
- (void)loginByToken:(NSString *)token timeStamp:(int64_t)timeStamp userId:(NSString *)userId completion:(TSGMSLoginBlock)completionBlock;
- (void)logoutWithCompletion:(TSGMSLogoutBlock)completionBlock;
- (void)renewToken:(NSString *)token timeStamp:(int64_t)timeStamp completion:(TSGMSRenewTokenBlock)completionBlock;

#pragma mark - channel
- (TSGMSChannel *_Nullable)createChannelWithId:(NSString *)channelId delegate:(id<TSGMSChannelDelegate> _Nullable)delegate;
- (BOOL)destroyChannelWithId:(NSString *)channelId;
- (void)getChannelMemberCount:(NSArray<NSString *> *)channelIds completion:(TSChannelMemberCountBlock)completionBlock;

#pragma mark - channel attributes
- (void)setChannel:(NSString *)channelId attributes:(NSArray<TSGMSAttribute *> *_Nullable)attributes options:(TSGMSChannelAttributeOptions *)options completion:(TSGMSSetChannelAttributesBlock)completionBlock;
- (void)addOrUpdateChannel:(NSString *)channelId attributes:(NSArray<TSGMSAttribute *> *_Nullable)attributes options:(TSGMSChannelAttributeOptions *)options completion:(TSGMSAddOrUpdateChannelAttributesBlock)completionBlock;
- (void)deleteChannelAttributes:(NSString *)channelId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys options:(TSGMSChannelAttributeOptions *)options completion:(TSGMSDeleteChannelAttributesBlock)completionBlock;
- (void)clearChannelAttributes:(NSString *)channelId options:(TSGMSChannelAttributeOptions *)options completion:(TSGMSClearChannelAttributesBlock)completionBlock;
- (void)getChannelAttributes:(NSString *)channelId completion:(TSGMSGetChannelAttributesBlock)completionBlock;
- (void)getChannelAttributes:(NSString *)channelId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(TSGMSGetChannelAttributesBlock)completionBlock;

#pragma mark - user attributes
- (void)setLocalUserAttributes:(NSArray<TSGMSAttribute *> *_Nullable)attributes completion:(TSGMSSetLocalUserAttributesBlock)completionBlock;
- (void)addOrUpdateLocalUserAttributes:(NSArray<TSGMSAttribute *> *_Nullable)attributes completion:(TSGMSAddOrUpdateLocalUserAttributesBlock)completionBlock;
- (void)deleteLocalUserAttributesByKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(TSGMSDeleteLocalUserAttributesBlock)completionBlock;
- (void)clearLocalUserAttributesWithCompletion:(TSGMSClearLocalUserAttributesBlock)completionBlock;
- (void)getUserAttributes:(NSString *)userId byKeys:(NSArray<NSString *> *_Nullable)attributeKeys completion:(TSGMSGetUserAttributesBlock)completionBlock;
- (void)getUserAttributes:(NSString *)userId completion:(TSGMSGetUserAttributesBlock)completionBlock;


/// ????????????????????????UserAttributes??????
/// @param peerIds ??????ID??????
/// @param completionBlock  ????????????
- (void)subscribePeersUserAttribes:(NSArray<NSString *> *)peerIds completion:(TSGMSSubscriptionRequestBlock)completionBlock;

/// ??????????????????????????????UserAttributes??????
/// @param peerIds ??????ID??????
/// @param completionBlock  ????????????
- (void)unsubscribePeersUserAttribes:(NSArray<NSString *> *)peerIds completion:(TSGMSSubscriptionRequestBlock)completionBlock;


/// ??????????????????????????????
/// @param peerIds ??????ID??????
/// @param completionBlock ????????????
- (void)getPeersUserAttributes:(NSArray<NSString *> *)peerIds completion:(TSGMSBatchFetchPeersUserAttributesBlock)completionBlock;

/// ??????keys??? ????????????????????????
/// @param peerIds ??????ID??????
/// @param attributeKeys ????????????????????????key
/// @param completionBlock ????????????
- (void)getPeersUserAttributes:(NSArray<NSString *> *)peerIds
                        byKeys:(NSArray<NSString *> *_Nullable)attributeKeys
                    completion:(TSGMSBatchFetchPeersUserAttributesBlock)completionBlock;

#pragma mark - online status -
- (void)subscribePeersOnlineStatus:(NSArray<NSString *> *)peerIds completion:(TSGMSSubscriptionRequestBlock)completionBlock;
- (void)unsubscribePeersOnlineStatus:(NSArray<NSString *> *)peerIds completion:(TSGMSSubscriptionRequestBlock)completionBlock;
- (void)queryPeersOnlineStatus:(NSArray<NSString *> *)peerIds completion:(TSGMSQueryPeersOnlineBlock)completionBlock;
- (void)queryPeersBySubscriptionOption:(TSGMSPeerSubscriptionOptions)option completion:(TSGMSQueryPeersBySubscriptionOptionBlock)completionBlock;

#pragma mark - ??????????????????
///???????????????????????????????????????????????????
- (TSGMSInvitationKit *)getGMSInvitationKit;

#pragma mark - ???????????????
- (void)sendMessage:(TSGMSMessage *)message
             toPeer:(NSString *)peerId
 sendMessageOptions:(TSGMSSendMessageOptions *)options
         completion:(TSGMSSendPeerMessageBlock)completionBlock;

#pragma mark - ??????
- (int)setParameters:(NSString *)parameters;
- (void)setLogFile:(NSString *)logFile;
- (void)setLogFilters:(TSGMSLogFilter)filter;
+ (NSString *)getSDKVersion;

///??????sdk?????????????????????????????????????????????????????????
- (NSDictionary *)getDebugInfo;

@end

NS_ASSUME_NONNULL_END
