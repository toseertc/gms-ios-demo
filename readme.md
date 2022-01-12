## Requirements

- iOS 9.0+

## Installation

### CocoaPods

[CocoaPods](https://cocoapods.org) 是iOS的一个依赖管理工具。使用它我们可以很方便的集成sdk, 在你的 `Podfile` 中添加这些配置:

```ruby
pod 'TSGMS'
```

## 使用
### demo运行
在有`podfile`的目录下，打开命令行，执行`pod install`。然后打开`.xcworkspace`。

### sdk 包含以下功能：
- [sdk使用](./docs/feature-sdk.md) 
- [用户的一些操作](./docs/feature-user.md) 
- [channel使用](./docs/feature-channel.md) 
- [呼叫邀请使用](./docs/feature-invitation.md) 

### SDK 包含以下模块：
- [`GMSClient`](./docs/TSGMSKit.md) sdk 实例
- [`GMSChannel`](./docs/TSGMSChannel.md) 频道实例
- [`GMSInvitationManager`](./docs/TSGMSInvitationKit.md) 邀请管理器
- [数据模型](./docs/TSGMSModel.md) 
- [错误码和状态码](./docs/TSGMSEnum.md)

## FAQ
- `Unable to find a pod with name, author, summary, or description matching "TSGMS"`
打开命令行工具，执行以下命令`rm -rf ~/Library/Caches/CocoaPods` `pod repo update`。

- 登录遇到了问题
请填写正确的appid和token。
```objc
TSGMSKit *tsGMSKit = [[TSGMSKit alloc] initWithAppId:@"appid" delegate:self];
[tsGMSKit loginByToken:token timeStamp:ts userId:uid completion:completion];
```

- 如何计算token

token 计算参考demo

## 注意事项


