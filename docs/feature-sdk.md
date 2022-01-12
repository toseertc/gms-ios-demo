---
title: sdk 使用
---
## 创建 [TSGMSKit](./TSGMSKit.md) 实例
```objectivec
//换成你自己的appid
TSGMSKit *tsGMSKit = [[TSGMSKit alloc] initWithAppId:@"123" delegate:self];
```

## 创建 [TSGMSChannel](./TSGMSChannel.md) 实例
```objectivec
TSGMSChannel *gmsChannel = [self.tsGMSKit createChannelWithId:@"channelId" delegate:self];
```

## 销毁 [TSGMSChannel](./TSGMSChannel.md) 实例
```objectivec
- (BOOL)destroyChannelWithId:(NSString *)channelId;
```

## 获取 [TSGMSInvitationKit](./TSGMSInvitationKit.md) 实例
```objectivec
- (TSGMSInvitationKit *)getGMSInvitationKit;
```

## 登录
```objectivec
NSString *token = @"token"; //换成自己的token
NSDate *date = [NSDate date];
int64_t ts = (int64_t)(date.timeIntervalSince1970 * 1000);
[self.tsGMSKit loginByToken:token timeStamp:ts userId:uid completion:^(TSGMSLoginErrorCode errorCode) {
    if (errorCode == TSGMSLoginErrorOk) {
        
    }
}];
```

## 登出
```objectivec
[self.tsGMSKit logoutWithCompletion:^(TSGMSLogoutErrorCode errorCode) {
    if (errorCode == TSGMSLogoutErrorOk) {
    }
}];
```

## 更新token
```objectivec
- (void)renewToken:(NSString *)token timeStamp:(NSTimeInterval)timeStamp completion:(TSGMSRenewTokenBlock)completionBlock;
```
