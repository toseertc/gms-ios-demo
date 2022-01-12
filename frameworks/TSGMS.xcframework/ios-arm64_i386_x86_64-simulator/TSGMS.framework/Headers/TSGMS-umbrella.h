#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "TSGMSChannel.h"
#import "TSGMSInvitationKit.h"
#import "TSGMSKit.h"
#import "TSChannelMemberCount.h"
#import "TSEnumerates.h"
#import "TSGMSAttribute.h"
#import "TSGMSChannelAttributeOptions.h"
#import "TSGMSEnvConfig.h"
#import "TSGMSMember.h"
#import "TSGMSMessage.h"
#import "TSGMSOptions.h"
#import "TSGMSPeerOnlineStatus.h"
#import "TSGMSResult.h"
#import "TSGMSSendMessageOptions.h"
#import "TSGMSUserAttributes.h"

FOUNDATION_EXPORT double TSGMSVersionNumber;
FOUNDATION_EXPORT const unsigned char TSGMSVersionString[];

