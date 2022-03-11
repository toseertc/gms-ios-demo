//
//  TSGMSDebugInfo.h
//  TSGMS
//
//  Created by yxibng on 2021/4/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TSGMSTavernSocket : NSObject
/// web端服务器地址
@property (nonatomic, copy) NSString *apiServer;
/// 当前连接的websocket服务器地址
@property (nonatomic, copy, nullable) NSString *tavernServer;
/// 当前 socket.io 实例的 id 值
@property (nonatomic, copy, nullable) NSString *connectionId;

@property (nonatomic, copy, nullable) NSArray *tavernServers;

@end


@interface TSGMSLoginArguments : NSObject
/// 户login时传入的userId值
@property (nonatomic, copy) NSString *userId;
/// 用户login时传入的token值
@property (nonatomic, copy) NSString *token;
/// 用户login时传入的timestamp值
@property (nonatomic, assign) NSTimeInterval timestamp;
@end

@interface TSGMSDebugInfo : NSObject

@property (nonatomic, copy, readonly) NSString *sdkVersion;
@property (nonatomic, strong, readonly) TSGMSTavernSocket *tavernSocket;
@property (nonatomic, strong, readonly) TSGMSLoginArguments *loginArguments;


- (void)getApiServer:(NSString *)apiServer;

//更新当前使用的tavern server
- (void)updateTavernServer:(NSString *)tavernServer;
//获得tavern server列表
- (void)getTavernServers:(NSArray *)tavernServers;

- (void)getConnectionId:(NSString *)connectionId;

- (void)loginWithToken:(NSString *)token userId:(NSString *)userId timestamp:(NSTimeInterval)timestamp;
- (void)logout;

- (NSDictionary *)toJsonModel;


@end

NS_ASSUME_NONNULL_END
