//
//  TSGMSStateHelper.h
//  TSGMS
//
//  Created by yxibng on 2021/6/22.
//

#import <Foundation/Foundation.h>
#import "TSGMSAttribute.h"
#import "TSGMSChannel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TSGMSChannelManager: NSObject
- (void)onJoinChannel:(TSGMSChannel *)channel;
- (void)onLeaveChannel:(TSGMSChannel *)channel;
- (void)logout;

//当前加入的频道
@property (nonatomic, strong, readonly) NSArray <TSGMSChannel *> *channels;

@end


#pragma mark -
@class TSGMSOnlinePeersManager;
@protocol TSGMSOnlinePeersManagerDelegate <NSObject>
- (void)onlinePeersManager:(TSGMSOnlinePeersManager *)manager onChangeOfStatus:(NSDictionary *)statusDic;
@end
@interface TSGMSOnlinePeersManager : NSObject
@property (nonatomic, weak) id<TSGMSOnlinePeersManagerDelegate>delegate;
- (void)onPeersOnlineStatusChanged:(NSDictionary *)statusDic;
- (void)unsubscribeOnlineStatusOf:(NSArray<NSString *> *)peerIds;
- (void)logout;
@end


@interface TSGMSLoginParams : NSObject

- (NSDictionary *)generateSocketConfig;

- (void)loginWithToken:(NSString *)token
                 appId:(NSString *)appId
                userId:(NSString *)userId
             timestamp:(int64_t)timestamp;


- (void)renewToken:(NSString *)token
         timestamp:(int64_t)timestamp;

- (void)logout;

@end
#pragma mark -
@interface TSGMSLocalUserAttributes : NSObject

@property (nonatomic, copy, readonly) NSDictionary *userAttributes;
@property (nonatomic, copy, readonly) NSArray<TSGMSAttribute *> *gmsAttributes;

- (void)setLocalUserAttributes:(NSDictionary *)attributes;
- (void)addOrUpdateLocalUserAttributes:(NSDictionary *)attributes;
- (void)deleteLocalUserAttributesByKeys:(NSArray<NSString *> *)keys;
- (void)clearLocalUserAttributes;
- (void)logout;

@end



@interface TSGMSStateHelper : NSObject

@property (nonatomic, copy, readonly) NSSet<NSString *> *subscribedOnlineStatusPeerIds;
@property (nonatomic, copy, readonly) NSSet<NSString *> *subscribedAttributesPeerIds;

@property (nonatomic, strong, readonly) TSGMSLoginParams *loginParams;
@property (nonatomic, strong, readonly) TSGMSLocalUserAttributes *localUserAttributes;
@property (nonatomic, strong, readonly) TSGMSOnlinePeersManager *onlinePeersManager;
@property (nonatomic, strong, readonly) TSGMSChannelManager *channelManager;


- (void)subscribeOnlineStatusOf:(NSArray<NSString *> *)peerIds;
- (void)unsubscribeOnlineStatusOf:(NSArray<NSString *> *)peerIds;

- (void)subscribeAttributesOf:(NSArray<NSString *> *)peerIds;
- (void)unsubscribeAttributesOf:(NSArray<NSString *> *)peerIds;

- (void)logout;

@end

NS_ASSUME_NONNULL_END
