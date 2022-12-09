//
//  TSGMSSendMessageOptions.h
//  TS-GMS
//
//  Created by yxibng on 2020/5/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TSGMSSendMessageOptions : NSObject
/**
 是否设置为离线消息。
 YES: 将该消息设为离线消息。
 NO: （默认）不将该消息设为离线消息。
 本设置仅适用于点对点消息，不适用于频道消息。
 */
@property (nonatomic, assign) BOOL enableOfflineMessaging;
///预留字段
@property (nonatomic, assign) BOOL enableHistoricalMessaging;

@end

NS_ASSUME_NONNULL_END
