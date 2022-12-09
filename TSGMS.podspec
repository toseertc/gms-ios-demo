#
#  Be sure to run `pod spec lint TS1VNSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "TSGMS"
  s.version      = "2.2.0"
  s.summary      = "TSGMS"
  s.description  = "TSGMS 的实时消息服务，cocoapods线上版本"

  s.homepage     = "https://github.com/toseertc/gms-ios-demo.git"
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright (C) 2022 TSGMS, Inc. All rights reserved.
      LICENSE
  }
  s.platform     = :ios
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.swift_versions = '5.0'
  s.ios.deployment_target = '11.0'
  s.author       = { "xiaobing" => "xiaobing.yao@duobei.com" }
  s.source       = { :git => "https://github.com/toseertc/gms-ios-demo.git", :tag => "#{s.version}" }
  s.vendored_frameworks  = "frameworks/TSGMS.xcframework", "frameworks/SocketIO.xcframework", "frameworks/Starscream.xcframework"
  
end
