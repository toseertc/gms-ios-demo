//
//  NSDate+Util.m
//  TSGMSDemo_OC
//
//  Created by xiaobing.yao on 2022/01/12.
//  Copyright © 2022 Beijing ToSee Future Network Technology Co., Ltd. All rights reserved.
//

#import "NSDate+Util.h"

@implementation NSDate (Util)

///in millisecond
+ (int64_t)currentTimeStamp {
    NSDate *date = [NSDate date];
    return (int64_t)(date.timeIntervalSince1970 * 1000);
}

@end
