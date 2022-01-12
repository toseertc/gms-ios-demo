---
title: 呼叫邀请使用
---
通过[sdk](./feature-sdk.md)获取呼叫邀请实例

## 发起呼叫邀请
```objectivec
TSGMSInvitation *invitation = [[TSGMSInvitation alloc] initWithInviter:@"fromUserId" invitee:@"toUserId"];
[_invitationKit sendInvitation:invitation completion:^(TSGMSInvitationApiCallErrorCode errorCode) {

}];
```

收到呼叫邀请后会通过[_invitationKit](./TSGMSInvitationKit.md)的[delegate](./TSGMSInvitationKit.md/#rzgmsinvitationdelegate)通知给你。
## 取消呼叫邀请
```objectivec
[_invitationKit cancelInvitation:invitation completion:^(TSGMSInvitationApiCallErrorCode errorCode) {

}];
```

## 接受呼叫邀请
```objectivec
[_invitationKit acceptInvitation:invitation completion:^(TSGMSInvitationApiCallErrorCode errorCode) {

}];
```

## 拒绝呼叫邀请
```objectivec
[_invitationKit refuseInvitation:invitation completion:^(TSGMSInvitationApiCallErrorCode errorCode) {

}];
```
