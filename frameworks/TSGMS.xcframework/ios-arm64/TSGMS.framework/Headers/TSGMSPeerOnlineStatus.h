//
//  TSGMSPeerOnlineStatus.h
//  TS-GMS
//
//  Created by yxibng on 2020/5/15.
//

#import <Foundation/Foundation.h>
#import "TSEnumerates.h"

NS_ASSUME_NONNULL_BEGIN


@interface TSGMSPeerOnlineStatus : NSObject

@property (nonatomic, copy, nonnull) NSString *peerId;
@property (nonatomic, assign) BOOL isOnline;

@end

NS_ASSUME_NONNULL_END
