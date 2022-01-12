//
//  NSString+Util.m
//  TSGMSDemo_OC
//
//  Created by xiaobing.yao on 2022/01/12.
//  Copyright © 2022 Beijing ToSee Future Network Technology Co., Ltd. All rights reserved.
//

#import "NSString+Util.h"
#import <CommonCrypto/CommonCrypto.h>


@implementation NSString (Util)

- (NSString *)md5Value
{
    const char *original_str = [self UTF8String];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(original_str, (uint32_t)strlen(original_str), result);
    NSMutableString *hash = [NSMutableString string];
    for (int i = 0; i < 16; i++) {
        [hash appendFormat:@"%02X", result[i]];
    }
    return [hash lowercaseString];
}
- (BOOL)match:(NSString *)regex {
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [predicate evaluateWithObject:self];
}
@end
