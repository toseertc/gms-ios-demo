---
title: TSGMSKit
description: "认真通信 GMS - iOS API 参考文档"
---
## Login
### initWithAppId
|  参数   | 描述  |
|  ----  | ----  |
| appId  | 应用id |
| delegate  | [TSGMSDelegate](#tsgmsdelegate) 接收事件 |

### loginByToken
|  参数   | 描述  |
|  ----  | ----  |
| token  | 校验身份用token |
| timeStamp  | 时间戳 毫秒 |
| userId  | 用户id |
| completion  | [TSGMSLoginBlock](#tsgmsloginblock)，错误码 [TSGMSLoginErrorCode](./TSGMSEnum.md/#tsgmsloginerrorcode)。 |

### logoutWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [TSGMSLogoutBlock](#tsgmslogoutblock)，错误码 [TSGMSLogoutErrorCode](./TSGMSEnum.md/#tsgmslogouterrorcode)。 |

### renewToken
|  参数   | 描述  |
|  ----  | ----  |
| token  | 新的token |
| timeStamp  | 时间戳 毫秒 |
| completionBlock  | [TSGMSRenewTokenBlock](#tsgmsrenewtokenblock)，错误码 [TSGMSRenewTokenErrorCode](./TSGMSEnum.md/#tsgmsrenewtokenerrorcode) 。|

### createChannelWithId
|  参数   | 描述  |
|  ----  | ----  |
| channelId | channelId 必须为不超过 64 字节的字符串，不能为空、nil，或设为 "null" |
| delegate  | 接收channel的相关通知 |
| return  | [TSGMSChannel](./TSGMSChannel.md) channel实例 |

### destroyChannelWithId
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |


### getChannelMemberCount
|  参数   | 描述  |
|  ----  | ----  |
| channelIds  | channelId数组 |
| completionBlock  | [RZChannelMemberCountBlock](#rzchannelmembercountblock)，结果 [RZChannelMemberCount](./TSGMSModel.md/#RZChannelMemberCount) 数组，错误码 [TSGMSChannelMemberCountErrorCode](./TSGMSEnum.md/#tsgmschannelmembercounterrorcode) 。|

## Channel
### setChannel
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute)数组 |
| options  | TSGMSChannelAttributeOptions |
| completionBlock  | [TSGMSSetChannelAttributesBlock](#tsgmssetchannelattributesblock)，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode)。 |

### addOrUpdateChannel
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute)数组 |
| options  | [TSGMSChannelAttributeOptions](./TSGMSModel.md/#tsgmschannelattributeoptions) |
| completionBlock  | [TSGMSAddOrUpdateChannelAttributesBlock](#tsgmsaddorupdatechannelattributesblock)，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode) 。|

### deleteChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute) 数组 |
| attributeKeys  | 字符串数组 |
| options  | [TSGMSChannelAttributeOptions](./TSGMSModel.md/#tsgmschannelattributeoptions) |
| completionBlock  | [TSGMSDeleteChannelAttributesBlock](#tsgmsdeletechannelattributesblock)，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode) 。|

### clearChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributes  | [TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute) 数组 |
| options  | [TSGMSChannelAttributeOptions](./TSGMSModel.md/#tsgmschannelattributeoptions) |
| completionBlock  | [TSGMSClearChannelAttributesBlock](#tsgmsclearchannelattributesblock)，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode)。 |

### getChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| completionBlock  | [TSGMSGetChannelAttributesBlock](#tsgmsgetchannelattributesblock)，结果 [TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute) 数组，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode)。 |

### getChannelAttributes
|  参数   | 描述  |
|  ----  | ----  |
| channelId  | 创建channel时的id |
| attributeKeys  | 字符串数组 |
| completionBlock  | [TSGMSGetChannelAttributesBlock](#tsgmsgetchannelattributesblock)，结果 [TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute) 数组，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode)。 |

## User

### setLocalUserAttributes
|  参数   | 描述  |
|  ----  | ----  |
| attributes  | [TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute) 数组 |
| completionBlock  | [TSGMSSetLocalUserAttributesBlock](#tsgmssetlocaluserattributesblock)，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode)。 |

### addOrUpdateLocalUserAttributes
|  参数   | 描述  |
|  ----  | ----  |
| attributes  | [TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute) 数组 |
| completionBlock  | [TSGMSAddOrUpdateLocalUserAttributesBlock](#tsgmsaddorupdatelocaluserattributesblock)，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode)。 |

### deleteLocalUserAttributesByKeys
|  参数   | 描述  |
|  ----  | ----  |
| attributeKeys  | 字符串数组 |
| completionBlock  | [TSGMSDeleteLocalUserAttributesBlock](#tsgmsdeletelocaluserattributesblock)，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode)。 |

### clearLocalUserAttributesWithCompletion
|  参数   | 描述  |
|  ----  | ----  |
| completionBlock  | [TSGMSClearLocalUserAttributesBlock](#tsgmsclearlocaluserattributesblock)，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode)。 |

### getUserAttributes
|  参数   | 描述  |
|  ----  | ----  |
| userId  | 用户的id |
| completionBlock  | [TSGMSGetUserAttributesBlock](#tsgmsgetuserattributesblock)，结果[TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute)数组，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode)。 |


### getUserAttributesByKeys
|  参数   | 描述  |
|  ----  | ----  |
| userId  | 用户的id |
| attributeKeys  | 指定的属性key数组 |
| completionBlock  | [TSGMSGetUserAttributesBlock](#tsgmsgetuserattributesblock)，结果[TSGMSAttribute](./TSGMSModel.md/#tsgmsattribute)数组，错误码 [TSGMSProcessAttributeErrorCode](./TSGMSEnum.md/#tsgmsprocessattributeerrorcode)。 |

### subscribePeersOnlineStatus
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [TSGMSSubscriptionRequestBlock](#tsgmssubscriptionrequestblock)，错误码 [TSGMSPeerSubscriptionStatusErrorCode](./TSGMSEnum.md/#tsgmspeersubscriptionstatuserrorcode) 。|

### unsubscribePeersOnlineStatus
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [TSGMSSubscriptionRequestBlock](#tsgmssubscriptionrequestblock)，错误码 [TSGMSPeerSubscriptionStatusErrorCode](./TSGMSEnum.md/#tsgmspeersubscriptionstatuserrorcode)。 |

### queryPeersOnlineStatus
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [TSGMSQueryPeersOnlineBlock](#tsgmsquerypeersonlineblock)，结果[TSGMSPeerOnlineStatus](./TSGMSModel.md/#TSGMSPeerOnlineStatus)数组，错误码 [TSGMSQueryPeersOnlineErrorCode](./TSGMSEnum.md/#tsgmsquerypeersonlineerrorcode)。 |

### queryPeersBySubscriptionOption
|  参数   | 描述  |
|  ----  | ----  |
| peerIds  | 用户的id数组 |
| completionBlock  | [TSGMSSubscriptionRequestBlock](#tsgmssubscriptionrequestblock)，结果userId数组，错误码 [TSGMSPeerSubscriptionStatusErrorCode](./TSGMSEnum.md/#tsgmspeersubscriptionstatuserrorcode)。 |

## Invitation

### getGMSInvitationKit
|  参数   | 描述  |
|  ----  | ----  |
| return  | [TSGMSInvitationKit](./TSGMSInvitationKit.md) 实例 |

## Message

### sendMessage
发送点对点消息
|  参数   | 描述  |
|  ----  | ----  |
| message  | [TSGMSMessage](./TSGMSModel.md/#tsgmsmessage) 文本消息或者二进制消息 |
| peerId  | 接收消息用户的id |
| options  | [TSGMSSendMessageOptions](./TSGMSModel.md/#tsgmssendmessageoptions) 是否发生离线消息 |
| completionBlock  | [TSGMSSendPeerMessageBlock](#tsgmssendpeermessageblock)，错误码 [TSGMSSendPeerMessageErrorCode](./TSGMSEnum.md/#tsgmssendpeermessageerrorcode)。 |

## Other

### setLogFile
|  参数   | 描述  |
|  ----  | ----  |
| logFile  | 本地日志路径，不设置默认存储在`~Library/Caches/rz_gms.log` |

### setLogFilters
|  参数   | 描述  |
|  ----  | ----  |
| filter  | 控制台打印日志级别 [TSGMSLogFilter](./TSGMSEnum.md/#tsgmslogfilter) |

### getSDKVersion
|  参数   | 描述  |
|  ----  | ----  |
| return  | sdk的版本信息，包名，版本，编译数字等信息 |

## TSGMSDelegate

### connectionStateChanged
连接状态变化通知
```objectivec
- (void)tsGMSKit:(TSGMSKit *)kit connectionStateChanged:(TSGMSConnectionState)state reason:(TSGMSConnectionChangeReason)reason;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [TSGMSKit](#) 实例 |
| state  | [TSGMSConnectionState](./TSGMSEnum.md/#tsgmsconnectionstate) 状态 |
| reason  | [TSGMSConnectionChangeReason](./TSGMSEnum.md/#tsgmsconnectionchangereason) 产生这个状态的原因 |

### peersOnlineStatusChanged
用户状态变化通知
```objectivec
- (void)tsGMSKit:(TSGMSKit *)kit peersOnlineStatusChanged:(NSArray<TSGMSPeerOnlineStatus *> *_Nonnull)onlineStatus;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [TSGMSKit](#) 实例 |
| onlineStatus  | [TSGMSPeerOnlineStatus](./TSGMSModel.md/#tsgmspeeronlinestatus) 数组，在线用户的状态 |

### messageReceived
收到点对点消息
```objectivec
- (void)tsGMSKit:(TSGMSKit *)kit messageReceived:(TSGMSMessage *_Nonnull)message fromPeer:(NSString *_Nonnull)peerId;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [TSGMSKit](#) 实例 |
| message  | [TSGMSMessage](./TSGMSModel.md/#tsgmsmessage) 点对点消息 |
| peerId  | 用户id |

### invitationReceived
收到呼叫邀请
```objectivec
- (void)tsGMSKit:(TSGMSKit *)kit invitationReceived:(TSGMSInvitation *_Nonnull)invitation fromPeer:(NSString *_Nonnull)peerId;
```
|  参数   | 描述  |
|  ----  | ----  |
| kit  | [TSGMSKit](#) 实例 |
| invitation  | [TSGMSInvitation](./TSGMSModel.md/#tsgmsinvitation) 邀请实例 |
| peerId  | 用户id |


## Block
### TSGMSLoginBlock
```objectivec
typedef void (^TSGMSLoginBlock)(TSGMSLoginErrorCode errorCode);
```

### TSGMSLogoutBlock
```objectivec
typedef void (^TSGMSLogoutBlock)(TSGMSLogoutErrorCode errorCode);
```
### TSGMSSendPeerMessageBlock
```objectivec
typedef void (^TSGMSSendPeerMessageBlock)(TSGMSSendPeerMessageErrorCode errorCode);
```
### RZChannelMemberCountBlock
```objectivec
typedef void (^RZChannelMemberCountBlock)(NSArray<RZChannelMemberCount *> * _Nullable channelMemberCounts, TSGMSChannelMemberCountErrorCode errorCode);
```
### TSGMSQueryPeersOnlineBlock
```objectivec
typedef void (^TSGMSQueryPeersOnlineBlock)(NSArray<TSGMSPeerOnlineStatus *>  * _Nullable peerOnlineStatus, TSGMSQueryPeersOnlineErrorCode errorCode);
```
### TSGMSQueryPeersBySubscriptionOptionBlock
```objectivec
typedef void (^TSGMSQueryPeersBySubscriptionOptionBlock)(NSArray<NSString *> * _Nullable peers, TSGMSPeerSubscriptionStatusErrorCode errorCode);
```
### TSGMSSetChannelAttributesBlock
```objectivec
typedef void (^TSGMSSetChannelAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);
```
### TSGMSAddOrUpdateChannelAttributesBlock
```objectivec
typedef void (^TSGMSAddOrUpdateChannelAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);
```
### TSGMSDeleteChannelAttributesBlock
```objectivec
typedef void (^TSGMSDeleteChannelAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);
```
### TSGMSClearChannelAttributesBlock
```objectivec
typedef void (^TSGMSClearChannelAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);
```

### TSGMSGetChannelAttributesBlock
```objectivec
typedef void (^TSGMSGetChannelAttributesBlock)(NSArray< TSGMSAttribute *> * _Nullable attributes, TSGMSProcessAttributeErrorCode errorCode);
```

### TSGMSSetLocalUserAttributesBlock
```objectivec
typedef void (^TSGMSSetLocalUserAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);
```

### TSGMSAddOrUpdateLocalUserAttributesBlock
```objectivec
typedef void (^TSGMSAddOrUpdateLocalUserAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);
```

### TSGMSDeleteLocalUserAttributesBlock
```objectivec
typedef void (^TSGMSDeleteLocalUserAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);
```

### TSGMSClearLocalUserAttributesBlock
```objectivec
typedef void (^TSGMSClearLocalUserAttributesBlock)(TSGMSProcessAttributeErrorCode errorCode);
```

### TSGMSGetUserAttributesBlock
```objectivec
typedef void (^TSGMSGetUserAttributesBlock)(NSArray< TSGMSAttribute *> * _Nullable attributes, NSString * userId, TSGMSProcessAttributeErrorCode errorCode);
```

### TSGMSRenewTokenBlock
```objectivec
typedef void (^TSGMSRenewTokenBlock)(NSString *token, TSGMSRenewTokenErrorCode errorCode);
```

### TSGMSSubscriptionRequestBlock
```objectivec
typedef void (^TSGMSSubscriptionRequestBlock)(TSGMSPeerSubscriptionStatusErrorCode errorCode);
```
