---
title: TSGMSInvitationKit
description: "认真通信 GMS - iOS 呼叫邀请 API 参考文档"
---
## Invitation
### sendInvitation
| 参数       | 描述                                                              |
| ---------- | ----------------------------------------------------------------- |
| invitation | [TSGMSInvitation](#) 实例                        |
| completion | [TSGMSInvitationSendBlock](#tsgmsinvitationsendblock)，错误码 [TSGMSInvitationApiCallErrorCode](./TSGMSEnum.md/#tsgmsinvitationapicallerrorcode) |

### cancelInvitation
| 参数       | 描述                                                                |
| ---------- | ------------------------------------------------------------------- |
| invitation | [TSGMSInvitation](#) 实例                          |
| completion | [TSGMSInvitationCancelBlock]()，错误码 [TSGMSInvitationApiCallErrorCode](./TSGMSEnum.md/#) |

### acceptInvitation
| 参数       | 描述                                                                |
| ---------- | ------------------------------------------------------------------- |
| invitation | [TSGMSInvitation](#) 实例                          |
| completion | [TSGMSInvitationAcceptBlock]()，错误码 [TSGMSInvitationApiCallErrorCode](./TSGMSEnum.md/#) |

### refuseInvitation
| 参数       | 描述                                                                |
| ---------- | ------------------------------------------------------------------- |
| invitation | [TSGMSInvitation](#) 实例                          |
| completion | [TSGMSInvitationRefuseBlock]()，错误码 [TSGMSInvitationApiCallErrorCode](./TSGMSEnum.md/#) |

## TSGMSInvitationDelegate

### invitationFailed
```objectivec
- (void)gmsInvitationKit:(TSGMSInvitationKit *_Nonnull)invitationKit invitationFailed:(TSGMSInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [TSGMSInvitationKit](#) 实例 |
| invitation    | [TSGMSInvitation](./TSGMSModel.md/#tsgmsinvitation) 实例 |

### invitationArrived
```objectivec
- (void)gmsInvitationKit:(TSGMSInvitationKit *_Nonnull)invitationKit invitationArrived:(TSGMSInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [TSGMSInvitationKit](#) 实例 |
| invitation    | [TSGMSInvitation](./TSGMSModel.md/#tsgmsinvitation) 实例    |

### invitationCanceled
```objectivec
- (void)gmsInvitationKit:(TSGMSInvitationKit *_Nonnull)invitationKit invitationCanceled:(TSGMSInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [TSGMSInvitationKit](#) 实例 |
| invitation    | [TSGMSInvitation](./TSGMSModel.md/#tsgmsinvitation) 实例    |

### invitationAccept
```objectivec
- (void)gmsInvitationKit:(TSGMSInvitationKit *_Nonnull)invitationKit invitationAccept:(TSGMSInvitation *_Nonnull)invitation;
```
| 参数          | 描述                    |
| ------------- | ----------------------- |
| invitationKit | [TSGMSInvitationKit](#) 实例 |
| invitation    | [TSGMSInvitation](./TSGMSModel.md/#tsgmsinvitation) 实例    |

### invitationRefused
```objectivec
- (void)gmsInvitationKit:(TSGMSInvitationKit *_Nonnull)invitationKit invitationRefused:(TSGMSInvitation *_Nonnull)invitation;
```
| 参数          | 描述                                            |
| ------------- | ----------------------------------------------- |
| invitationKit | [TSGMSInvitationKit](#)实例 |
| invitation    | [TSGMSInvitation](./TSGMSModel.md/#tsgmsinvitation) 实例 |

## Block
### TSGMSInvitationSendBlock
```objectivec
typedef void (^TSGMSInvitationSendBlock)(TSGMSInvitationApiCallErrorCode errorCode);
```
### TSGMSInvitationAcceptBlock
```objectivec
typedef void (^TSGMSInvitationAcceptBlock)(TSGMSInvitationApiCallErrorCode errorCode);
```
### TSGMSInvitationRefuseBlock
```objectivec
typedef void (^TSGMSInvitationRefuseBlock)(TSGMSInvitationApiCallErrorCode errorCode);
```
### TSGMSInvitationCancelBlock
```objectivec
typedef void (^TSGMSInvitationCancelBlock)(TSGMSInvitationApiCallErrorCode errorCode);
```
