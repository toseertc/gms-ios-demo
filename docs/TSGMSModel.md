---
title: TSGMSModel
description: 认真通信 GMS - iOS 数据模型 API 参考文档。
---

## TSGMSInvitation
```objectivec

```
### initWithInviter
| 参数    | 描述       |
| ------- | ---------- |
| inviter | 邀请者id   |
| invitee | 被邀请者id |

## TSGMSMessage
```objectivec
@property (nonatomic, assign, readonly) TSGMSMessageType type;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, assign) long long serverReceivedTs;
@property (nonatomic, assign, readonly) BOOL isOfflineMessage;
```
### initWithText
| 参数    | 描述       |
| ------- | ---------- |
| text | 文本 |

## TSGMSRawMessage
```objectivec
@property (nonatomic, nonnull) NSData *rawData;
```
### initWithRawData
| 参数    | 描述       |
| ------- | ---------- |
| data | 二进制数据 |

## TSGMSPeerOnlineStatus
```objectivec
@property (nonatomic, copy, nonnull) NSString *peerId;
@property (nonatomic, assign) BOOL isOnline;
```

## TSGMSSendMessageOptions
```objectivec
/**
是否设置为离线消息。
YES: 将该消息设为离线消息。
NO: （默认）不将该消息设为离线消息。
本设置仅适用于点对点消息，不适用于频道消息。
*/
@property (nonatomic, assign) BOOL enableOfflineMessaging;
///预留字段
@property (nonatomic, assign) BOOL enableHistoricalMessaging;
```

## TSGMSAttribute
```objectivec
@property (nonatomic, copy, nonnull) NSString *key;
@property (nonatomic, copy, nonnull) NSString *value;
```

## TSGMSMember
```objectivec
@property (nonatomic, copy, nonnull) NSString *userId;
@property (nonatomic, copy, nonnull) NSString *channelId;
```
### membersFromArray
| 参数    | 描述       |
| ------- | ---------- |
| array | 字典数组 |
