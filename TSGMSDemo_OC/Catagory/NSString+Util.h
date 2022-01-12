//
//  NSString+Util.h
//  TSGMSDemo_OC
//
//  Created by xiaobing.yao on 2022/01/12.
//  Copyright © 2022 Beijing ToSee Future Network Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Util)

- (NSString *)md5Value;
- (BOOL)match:(NSString *)regex;

@end

NS_ASSUME_NONNULL_END
