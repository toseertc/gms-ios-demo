---
title: TSGMSChannel
description: 认真通信 GMS - iOS 频道 API 参考文档。
---

## delegate
```objectivec
@property (nonatomic, weak, nullable) id<TSGMSChannelDelegate> delegate;
```
## channelId
```objectivec
@property (nonatomic, copy) NSString *channelId;
```

## joinWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [TSGMSJoinChannelBlock](#tsgmsjoinchannelblock)， 错误码[TSGMSJoinChannelErrorCode](./TSGMSEnum.md/#tsgmsjoinchannelerrorcode) |

## leaveWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [TSGMSLeaveChannelBlock](#tsgmsleavechannelblock)， 错误码[TSGMSLeaveChannelErrorCode](./TSGMSEnum.md/#tsgmsleavechannelerrorcode) |

## sendMessage
|  参数   | 描述  |
|  ----  | ----  |
| message  | [TSGMSMessage](./TSGMSModel.md/#tsgmsmessage) 可以发送文字和二进制 [TSGMSRawMessage](./TSGMSModel.md/#tsgmsrawmessage) 消息 |
| options  | [TSGMSSendMessageOptions](./TSGMSModel.md/#tsgmssendmessageoptions) 一些设置，如是否服务器缓存 |
| completionBlock  | [TSGMSSendChannelMessageBlock](#tsgmssendchannelmessageblock)， 错误码[TSGMSSendChannelMessageErrorCode](./TSGMSEnum.md/#tsgmsgetmemberserrorcode) |

## getMembersWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [TSGMSGetMembersBlock](#tsgmsgetmembersblock)， 错误码[TSGMSGetMembersErrorCode](./TSGMSEnum.md/#tsgmsgetmemberserrorcode) |

# TSGMSChannelDelegate

## memberJoined
```objectivec
- (void)channel:(TSGMSChannel * _Nonnull)channel memberJoined:(TSGMSMember * _Nonnull)member;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [TSGMSChannel](#)加入的频道 |
| member  | [TSGMSMember](./TSGMSModel.md/#tsgmsmember)加入的用户 |

## memberLeft
```objectivec
- (void)channel:(TSGMSChannel * _Nonnull)channel memberLeft:(TSGMSMember * _Nonnull)member;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [TSGMSChannel](#)离开的频道 |
| member  | [TSGMSMember](./TSGMSModel.md/#tsgmsmember)离开的用户 |

## messageReceived
```objectivec
- (void)channel:(TSGMSChannel * _Nonnull)channel messageReceived:(TSGMSMessage * _Nonnull)message fromMember:(TSGMSMember * _Nonnull)member;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [TSGMSChannel](#)当前频道 |
| message  | [TSGMSMessage](./TSGMSModel.md/#tsgmsmessage)收到的消息 |
| member  | [TSGMSMember](./TSGMSModel.md/#tsgmsmember)发送消息的用户 |

## attributeUpdate
```objectivec
- (void)channel:(TSGMSChannel * _Nonnull)channel attributeUpdate:(NSArray< TSGMSAttribute *> * _Nonnull)attributes;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [TSGMSChannel](#)当前频道 |
| attributes  | [TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute)频道属性 |

## memberCount
```objectivec
- (void)channel:(TSGMSChannel * _Nonnull)channel memberCount:(int)count;
```
|  参数   | 描述  |
|  ----  | ----  |
| channel  | [TSGMSChannel](#)当前频道 |
| count  | 频道人数 |


## Block
### TSGMSJoinChannelBlock
```objectivec
typedef void (^TSGMSJoinChannelBlock)(TSGMSJoinChannelErrorCode errorCode);
```
### TSGMSLeaveChannelBlock
```objectivec
typedef void (^TSGMSLeaveChannelBlock)(TSGMSLeaveChannelErrorCode errorCode);
```
### TSGMSGetMembersBlock
```objectivec
typedef void (^TSGMSGetMembersBlock)(NSArray< TSGMSMember *> * _Nullable members, TSGMSGetMembersErrorCode errorCode);
```
### TSGMSSendChannelMessageBlock
```objectivec
typedef void (^TSGMSSendChannelMessageBlock)(TSGMSSendChannelMessageErrorCode errorCode);
```
