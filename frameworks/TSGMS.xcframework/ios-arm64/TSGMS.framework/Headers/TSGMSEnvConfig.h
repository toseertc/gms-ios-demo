//
//  TSGMSEnvConfig.h
//  TSGMS
//
//  Created by yxibng on 2021/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TSGMSEnvConfig : NSObject

/**
 api 服务器域名或者ip地址 例如：
 http://www.tetet.com:8080
 http://192.168.1.1
 */
@property (copy, nonatomic, nullable) NSString *apiServer;
/**
 日志上报服务器地址
 */
@property (copy, nonatomic, nullable) NSString *logServer;

@end

NS_ASSUME_NONNULL_END
