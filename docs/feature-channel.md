---
title: channel 使用
---

通过[sdk](./feature-sdk.md)创建频道

## 加入频道
```objectivec
[_gmsChannel joinWithCompletion:^(TSGMSJoinChannelErrorCode errorCode) {
    if (errorCode == TSGMSJoinChannelErrorOk) {
        
    }
}];
```

## 离开频道
```objectivec
[_gmsChannel leaveWithCompletion:^(TSGMSLeaveChannelErrorCode errorCode) {
    if (errorCode == TSGMSLeaveChannelErrorOk) {
        
    }
}];
```

## 发送频道消息
```objectivec
TSGMSSendMessageOptions *options = [[TSGMSSendMessageOptions alloc] init];
options.enableOfflineMessaging = true;
[_gmsChannel sendMessage:message options:options completion:^(TSGMSSendChannelMessageErrorCode errorCode) {
    if (errorCode == TSGMSSendChannelMessageErrorOk) {

    }
}];
```

## 获取频道成员列表
```objectivec
[_gmsChannel getMembersWithCompletion:^(NSArray<TSGMSMember *> * _Nullable members, TSGMSGetMembersErrorCode errorCode) {
    if (errorCode == TSGMSGetMembersErrorOk && members) {

    }
}];
```
