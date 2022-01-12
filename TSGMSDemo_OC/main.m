//
//  main.m
//  TSGMSDemo_OC
//
//  Created by xiaobing.yao on 2022/01/12.
//  Copyright © 2022 Beijing ToSee Future Network Technology Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    NSString * appDelegateClassName;
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([AppDelegate class]);
    }
    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
}
