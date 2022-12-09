//
//  TSGMSChannel.h
//  TS-GMS
//
//  Created by 钟凡 on 2020/7/15.
//

#import <Foundation/Foundation.h>
#import "TSGMSMessage.h"
#import "TSGMSMember.h"
#import "TSGMSSendMessageOptions.h"
#import "TSEnumerates.h"

@class TSGMSChannel;
@class TSGMSAttribute;

NS_ASSUME_NONNULL_BEGIN

typedef void (^TSGMSJoinChannelBlock)(TSGMSJoinChannelErrorCode errorCode);
typedef void (^TSGMSLeaveChannelBlock)(TSGMSLeaveChannelErrorCode errorCode);
typedef void (^TSGMSGetMembersBlock)(NSArray<TSGMSMember *> *_Nullable members, TSGMSGetMembersErrorCode errorCode);
typedef void (^TSGMSSendChannelMessageBlock)(TSGMSSendChannelMessageErrorCode errorCode);


@protocol TSGMSChannelDelegate <NSObject>
@optional

/**
 Occurs when a user joins the channel.
 
 When a remote user calls the [joinWithCompletion]([TSGMSChannel joinWithCompletion:]) method and successfully joins the channel, the local user receives this callback.
 
 **NOTE**
 
 This callback is disabled when the number of the channel members exceeds 512.
 
 @param channel The channel that the user joins. See TSGMSChannel.
 @param member The user joining the channel. See TSGMSMember.
 */
- (void)channel:(TSGMSChannel *)channel memberJoined:(TSGMSMember *)member;

/**
 Occurs when a channel member leaves the channel.
 
 When a remote channel member calls the [leaveWithCompletion]([TSGMSChannel leaveWithCompletion:]) method and successfully leaves the channel, the local user receives this callback.
 
 **NOTE**
 
 This callback is disabled when the number of the channel members exceeds 512.
 
 @param channel The channel that the user leaves. See TSGMSChannel.
 @param member The channel member that leaves the channel. See TSGMSMember.
 */
- (void)channel:(TSGMSChannel *)channel memberLeft:(TSGMSMember *)member;


- (void)channel:(TSGMSChannel *)channel memberLeft:(TSGMSMember *)member reason:(TSGMSMemberLeaveChannelReason)reason;

/**
 Occurs when receiving a channel message.
 
 When a remote channel member calls the [sendMessage]([TSGMSChannel sendMessage:completion:]) method and successfully sends out a channel message, the local user receives this callback.
 
 @param channel The channel, to which the local user belongs. See TSGMSChannel.
 @param message The received channel message. See TSGMSMessage. Ensure that you check the `type` property when receiving the message instance: If the message type is `TSGMSMessageTypeRaw`, you need to downcast the received instance from TSGMSMessage to TSGMSRawMessage. See TSGMSMessageType.
 @param member The message sender. See TSGMSMember.
 */
- (void)channel:(TSGMSChannel *)channel messageReceived:(TSGMSMessage *)message fromMember:(TSGMSMember * _Nonnull)member;

/**
 Occurs when channel attributes are updated, and returns all attributes of the channel.
 
 **NOTE**
 
 This callback is enabled only when the user, who updates the attributes of the channel, sets [enableNotificationToChannelMembers]([TSGMSChannelAttributeOptions enableNotificationToChannelMembers]) as YES. Also note that this flag is valid only within the current channel attribute method call.
 
 @param channel The channel, to which the local user belongs. See TSGMSChannel.
 @param attributes An array of TSGMSChannelAttribute. See TSGMSChannelAttribute.
 */
- (void)channel:(TSGMSChannel *)channel attributeUpdate:(NSArray< TSGMSAttribute *> *)attributes;

/**
 Occurs when the number of the channel members changes, and returns the new number.
 
 **NOTE**
 
 - When the number of channel members &le; 512, the SDK returns this callback when the number changes and at a MAXIMUM speed of once per second.
 - When the number of channel members exceeds 512, the SDK returns this callback when the number changes and at a MAXIMUM speed of once every three seconds.
 - You will receive this callback when successfully joining an RTM channel, so Agore recommends implementing this callback to receive timely updates on the number of the channel members.
 
 @param channel The channel, to which the local user belongs. See TSGMSChannel.
 @param count Member count of this channel.
 */
- (void)channel:(TSGMSChannel *)channel memberCount:(int)count;

@end


@class TSGMSSocketManager;

@interface TSGMSChannel : NSObject

@property (nonatomic, weak, nullable) id<TSGMSChannelDelegate> delegate;
@property (nonatomic, copy) NSString *channelId;

- (void)joinWithCompletion:(TSGMSJoinChannelBlock)completionBlock;

- (void)leaveWithCompletion:(TSGMSLeaveChannelBlock)completionBlock;

- (void)sendMessage:(TSGMSMessage *)message options:(TSGMSSendMessageOptions *)options completion:(TSGMSSendChannelMessageBlock)completionBlock;

- (void)getMembersWithCompletion:(TSGMSGetMembersBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
