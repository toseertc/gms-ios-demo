---
title: TSGMSEnum
description: "认真通信 GMS - iOS API 参考文档"
---

## Login
### TSGMSConnectionState
```objectivec
typedef NS_ENUM(NSInteger, TSGMSConnectionState) {
    TSGMSConnectionStateDisconnected = 1, //断开连接
    TSGMSConnectionStateConnecting = 2,   //正在连接
    TSGMSConnectionStateConnected = 3,    //已连接
    TSGMSConnectionStateReconnecting = 4, //已断开，正在重连
    TSGMSConnectionStateAborted = 5,      //被踢出，终止
};
```

### TSGMSConnectionChangeReason
```objectivec
typedef NS_ENUM(NSInteger, TSGMSConnectionChangeReason) {
    TSGMSConnectionChangeReasonLogin = 1,          //sdk 正在登录
    TSGMSConnectionChangeReasonLoginSuccess = 2,   //sdk 已经登录
    TSGMSConnectionChangeReasonLoginFailure = 3,   //登录失败
    TSGMSConnectionChangeReasonLoginTimeout = 4,   //登录超时
    TSGMSConnectionChangeReasonInterrupted = 5,    //已登录，由于网络原因，断开连接了
    TSGMSConnectionChangeReasonLogout = 6,         //调用了logout
    TSGMSConnectionChangeReasonBannedByServer = 7, //登录被禁止
    TSGMSConnectionChangeReasonRemoteLogin = 8,    //远端登录，本地被踢出
};
```
### TSGMSLoginErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSLoginErrorCode) {
    TSGMSLoginErrorOk = 0,                    //登录成功
    TSGMSLoginErrorUnknown = 1,               //登录失败，原因未知
    TSGMSLoginErrorRejected = 2,              //登录被服务器拒绝
    TSGMSLoginErrorInvalidArgument = 3,       //参数错误
    TSGMSLoginErrorInvalidAppId = 4,          //App ID 无效
    TSGMSLoginErrorInvalidToken = 5,          //Token 无效
    TSGMSLoginErrorTokenExpired = 6,          //Token 已过期，登录被拒绝
    TSGMSLoginErrorNotAuthorized = 7,         //登录未经授权
    TSGMSLoginErrorAlreadyLogin = 8,          //用户已登录，或正在登录系统，或未调用 logoutWithCompletion 方法退出
    TSGMSLoginErrorTimeout = 9,               //登录超时。目前的超时设置为 6 秒。
    TSGMSLoginErrorLoginTooOften = 10,        //登录过于频繁。方法 loginByToken 的调用频率超过 2 次／秒的上限
};
```
### TSGMSLogoutErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSLogoutErrorCode ) {
    TSGMSLogoutErrorOk = 0,                    //登出成功
    TSGMSLogoutErrorNotLoggedIn = 102,         //未登录
};
```
### TSGMSRenewTokenErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSRenewTokenErrorCode) {
    TSGMSRenewTokenErrorOk = 0,                //更新 Token 成功
    TSGMSRenewTokenErrorFailure = 1,           //更新 Token 失败
    TSGMSRenewTokenErrorInvalidArgument = 2,   //无效参数
    TSGMSRenewTokenErrorRejected = 3,          //预留错误码
    TSGMSRenewTokenErrorTooOften = 4,          //方法调用过于频繁。超过 2 次／秒上限
    TSGMSRenewTokenErrorTokenExpired = 5,      //输入 Token 已过期
    TSGMSRenewTokenErrorInvalidToken = 6,      //输入 Token 无效
    TSGMSRenewTokenErrorNotLoggedIn = 102,     //更新 Token 前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```

## Channel
### TSGMSJoinChannelErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSJoinChannelErrorCode) {
    TSGMSJoinChannelErrorOk = 0,               //用户成功加入频道
    TSGMSJoinChannelErrorFailure = 1,          //用户加入频道失败
    TSGMSJoinChannelErrorRejected = 2,         //预留错误码
    TSGMSJoinChannelErrorInvalidArgument = 3,  //用户无法加入频道。因为参数无效
    TSGMSJoinChannelErrorTimeout = 4,          //用户加入频道超时。当前的超时设置为 5 秒。
    TSGMSJoinChannelErrorExceedLimit = 5,      //同时加入的频道数超过 20 上限。
    TSGMSJoinChannelErrorAlreadyJoined = 6,    //用户正在加入频道或已成功加入频道。
    TSGMSJoinChannelErrorTooOften = 7,         //方法调用超过 50 次每 3 秒的上限
    TSGMSJoinChannelErrorNotLoggedIn = 102,    //用户加入频道前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```
### TSGMSLeaveChannelErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSLeaveChannelErrorCode) {
    TSGMSLeaveChannelErrorOk = 0,              //用户离开频道成功
    TSGMSLeaveChannelErrorFailure = 1,         //用户离开频道失败
    TSGMSLeaveChannelErrorRejected = 2,        //预留错误码
    TSGMSLeaveChannelErrorNotInChannel = 3,    //用户不在频道内
    TSGMSLeaveChannelErrorNotLoggedIn = 102,   //未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```
### TSGMSChannelMemberCountErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSChannelMemberCountErrorCode) {
    TSGMSChannelMemberCountErrorOk = 0,               //获取指定频道成员人数成功
    TSGMSChannelMemberCountErrorFailure = 1,          //通用未知错误
    TSGMSChannelMemberCountErrorInvalidArgument = 2,  //频道 ID 无效
    TSGMSChannelMemberCountErrorTooOften = 3,         //方法调用过于频繁。超过每秒 1 次的限制
    TSGMSChannelMemberCountErrorTimeout = 4,          //服务器响应超时。当前的当前的超时设定为 5 秒
    TSGMSChannelMemberCountErrorExceedLimit = 5,      //查询频道数超过 32 条上限
    TSGMSChannelMemberCountErrorNotLoggedIn = 102,    //本次操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```
### TSGMSGetMembersErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSGetMembersErrorCode) {
    TSGMSGetMembersErrorOk = 0,               //频道成员列表获取成功
    TSGMSGetMembersErrorFailure = 1,          //频道成员列表获取失败
    TSGMSGetMembersErrorRejected = 2,         //预留错误码
    TSGMSGetMembersErrorTimeout = 3,          //获取频道内成员列表超时。当前的超时设置为 5 秒
    TSGMSGetMembersErrorTooOften = 4,         //方法调用频率超过 5 次每 2 秒的上限
    TSGMSGetMembersErrorNotInChannel = 5,     //用户不在频道内
    TSGMSGetMembersErrorNotLoggedIn = 102,    //获取频道成员列表前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```
### TSGMSSendChannelMessageErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSSendChannelMessageErrorCode) {
    TSGMSSendChannelMessageErrorOk = 0,               //服务端已接收到频道消息
    TSGMSSendChannelMessageErrorFailure = 1,          //频道消息发送失败
    TSGMSSendChannelMessageErrorTimeout = 2,          //服务器未收到频道消息或者 SDK 未在 10 秒内收到服务器响应
    TSGMSSendChannelMessageTooOften = 3,              //发送消息（点对点消息和频道消息一并计算在内）超过 60 次／秒的上限
    TSGMSSendChannelMessageInvalidMessage = 4,        //消息为 null 或超出 32 KB 的长度限制
    TSGMSSendChannelMessageErrorNotInChannel = 5,     //不在频道内
    TSGMSSendChannelMessageNotLoggedIn = 102,         //用户未登录
};
```
## User
### TSGMSProcessAttributeErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSProcessAttributeErrorCode) {
    TSGMSAttributeOperationErrorOk = 0,                //操作成功
    TSGMSAttributeOperationErrorFailure = 2,           //操作失败
    TSGMSAttributeOperationErrorInvalidArgument = 3,   //无效参数
    TSGMSAttributeOperationErrorSizeOverflow = 4,      //用户属性或频道属性超过上限
    TSGMSAttributeOperationErrorTooOften = 5,          //方法调用频率超过限制
    TSGMSAttributeOperationErrorUserNotFound = 6,      //未找到指定用户
    TSGMSAttributeOperationErrorTimeout = 7,           //属性操作超时。当前的超时设定为 5 秒
    TSGMSAttributeOperationErrorNotLoggedIn = 102,     //执行用户属性操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```

### TSGMSQueryPeersOnlineErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSProcessAttributeErrorCode) {
    TSGMSAttributeOperationErrorOk = 0,                //操作成功
    TSGMSAttributeOperationErrorFailure = 2,           //操作失败
    TSGMSAttributeOperationErrorInvalidArgument = 3,   //无效参数
    TSGMSAttributeOperationErrorSizeOverflow = 4,      //用户属性或频道属性超过上限
    TSGMSAttributeOperationErrorTooOften = 5,          //方法调用频率超过限制
    TSGMSAttributeOperationErrorUserNotFound = 6,      //未找到指定用户
    TSGMSAttributeOperationErrorTimeout = 7,           //属性操作超时。当前的超时设定为 5 秒
    TSGMSAttributeOperationErrorNotLoggedIn = 102,     //执行用户属性操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```

### TSGMSPeerSubscriptionStatusErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSPeerSubscriptionStatusErrorCode) {
    TSGMSPeerSubscriptionStatusErrorOk = 0,                //方法调用成功，或订阅退订操作成功
    TSGMSPeerSubscriptionStatusErrorFailure = 1,           //通用未知错误。订阅或退订操作失败
    TSGMSPeerSubscriptionStatusErrorInvalidArgument = 2,   //无效的输入参数
    TSGMSPeerSubscriptionStatusErrorRejected = 3,          //预留错误码
    TSGMSPeerSubscriptionStatusErrorTimeout = 4,           //服务器响应超时
    TSGMSPeerSubscriptionStatusErrorTooOften = 5,          //方法调用过于频繁
    TSGMSPeerSubscriptionStatusErrorOverflow = 6,          //订阅人数超过 512 人的上限
    TSGMSPeerSubscriptionStatusErrorNotLoggedIn = 102,     //本次操作前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```

### TSGMSPeerSubscriptionOptions
```objectivec
typedef NS_ENUM(NSInteger, TSGMSPeerSubscriptionOptions) {
    TSGMSPeerSubscriptionOnlineStatus = 0, //用户在线状态
};
```

### TSGMSSendPeerMessageErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSSendPeerMessageErrorCode) {
    TSGMSSendPeerMessageErrorOk = 0,               //对端已接收到点对点消息
    TSGMSSendPeerMessageErrorFailure = 1,          //点对点消息发送失败
    TSGMSSendPeerMessageErrorTimeout = 2,          //点对点消息发送超时
    TSGMSSendPeerMessageErrorPeerUnreachable = 3,  //接收者处于离线状态，无法接收点对点消息
    TSGMSSendPeerMessageErrorCachedByServer = 4,   //服务器已经缓存这条消息并将在用户上线后重新发送
    TSGMSSendPeerMessageErrorTooOften = 5,         //发送消息（点对点消息和频道消息一并计算在内）超过 60 次／秒的上限
    TSGMSSendPeerMessageErrorInvalidUserId = 6,    //用户 ID 无效
    TSGMSSendPeerMessageErrorInvalidMessage = 7,   //消息为 null 或超出 32 KB 的长度限制
    TSGMSSendPeerMessageErrorNotLoggedIn = 102,    //发送点对点消息前未调用 loginByToken 方法或者 loginByToken 方法调用未成功
};
```
### TSGMSInvitationApiCallErrorCode
```objectivec
typedef NS_ENUM(NSInteger, TSGMSInvitationApiCallErrorCode) {
    TSGMSInvitationApiCallErrorOk = 0,              //呼叫邀请相关 API 调用成功
    TSGMSInvitationApiCallErrorFailure = 1,         //呼叫邀请相关 API 调用失败：未知错误
    TSGMSInvitationApiCallErrorInvalidArgument = 2, //呼叫邀请相关 API 调用失败：参数错误
    TSGMSInvitationApiCallErrorInvalidState = 3,    //呼叫邀请相关 API 调用失败：状态错误
    TSGMSInvitationApiCallErrorPeerOffline = 4,     //呼叫邀请相关 API 调用失败：用户不在线
    TSGMSInvitationApiCallErrorWrongIdentity = 5,   //呼叫邀请相关 API 调用失败：非法身份调用
    TSGMSInvitationApiCallErrorNotLoggedIn = 102,   //呼叫邀请相关 API 调用失败：未登录
};
```
### TSGMSInvitationState
```objectivec
typedef NS_ENUM(NSInteger, TSGMSInvitationState) {
    TSGMSInvitationStateIdle = 0,     //初始状态
    TSGMSInvitationStateFailure = 1,  //呼叫失败
    TSGMSInvitationStateArrived = 2,  //呼叫到达
    TSGMSInvitationStateCanceled = 3, //呼叫被取消
    TSGMSInvitationStateAccepted = 4, //呼叫被接受
    TSGMSInvitationStateRefused = 5,  //呼叫被拒绝
};
```
## Log
### TSGMSLogFilter
```objectivec
typedef NS_ENUM(NSInteger, TSGMSLogFilter) {
    TSGMSLogFilterOff = 0,             //关闭
    TSGMSLogFilterInfo = 1 << 0,       //普通
    TSGMSLogFilterWarn = 1 << 1,       //警告
    TSGMSLogFilterError = 1 << 2,      //错误
    TSGMSLogFilterCritical = 1 << 3,   //严重
    TSGMSLogFilterMask = 0x1111,       //所有
};
```
