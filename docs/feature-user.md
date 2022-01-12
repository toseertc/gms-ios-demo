---
title: 用户的一些操作
---

## 查询用户属性
```objc
[self.gmsKit getUserAttributes:self.userId completion:^(NSArray<TSGMSAttribute *> * _Nullable attributes, NSString * _Nonnull userId, TSGMSProcessAttributeErrorCode errorCode) {
    if (errorCode == TSGMSProcessAttributeErrorOk && attributes) {
        
    }
}];
```

## 设置用户属性
```objc
TSGMSAttribute *att1 = [[TSGMSAttribute alloc] init];
att1.key = @"color";
att1.value = @"red";

TSGMSAttribute *att2 = [[TSGMSAttribute alloc] init];
att2.key = @"time";
att2.value = @"2020-05-14";

NSArray *attributes = @[att1, att2];

[self.gmsKit setLocalUserAttributes:attributes completion:^(TSGMSProcessAttributeErrorCode errorCode) {
    
}];
```

## 查询用户状态
查询之前先要订阅
```objc
[self.gmsKit queryPeersOnlineStatus:@[@"123"] completion:^(NSArray<TSGMSPeerOnlineStatus *> *_Nonnull peerOnlineStatus, TSGMSQueryPeersOnlineErrorCode errorCode) {
    
}];
```

## 订阅用户状态
```objc
[self.gmsKit subscribePeersOnlineStatus:@[@"123"] completion:^(TSGMSPeerSubscriptionStatusErrorCode errorCode) {

}];
```

## 取消订阅用户状态
```objc
[self.gmsKit unsubscribePeersOnlineStatus:peers completion:^(TSGMSPeerSubscriptionStatusErrorCode errorCode) {

}];
```

## 发送点对点消息
发送文本消息
```objc
TSGMSMessage *message = [[TSGMSMessage alloc] initWithText:@"message_123"];
TSGMSSendMessageOptions *options = [[TSGMSSendMessageOptions alloc] init];
options.enableOfflineMessaging = true;
[self.gmsKit sendMessage:message toPeer:@"123" sendMessageOptions:options completion:^(TSGMSSendPeerMessageErrorCode errorCode) {

}];
```
发送二进制消息
```
NSData *data = [@"rawMessage_123" dataUsingEncoding:NSUTF8StringEncoding];
TSGMSRawMessage *message = [[TSGMSRawMessage alloc] initWithRawData:data];
TSGMSSendMessageOptions *options = [[TSGMSSendMessageOptions alloc] init];
options.enableOfflineMessaging = true;
[self.gmsKit sendMessage:message toPeer:@"123" sendMessageOptions:options completion:^(TSGMSSendPeerMessageErrorCode errorCode) {

}];
```

## 接受点对点消息
需要从[TSGMSKit](./TSGMSKit.md)的delegate中获取到。
```objc
- (void)tsGMSKit:(TSGMSKit *)kit messageReceived:(TSGMSMessage *)message fromPeer:(NSString *)peerId {
    NSLog(@"---peerId: %@, message: %@", peerId, message.text);
}
```
暂时不支持接收二进制消息。
