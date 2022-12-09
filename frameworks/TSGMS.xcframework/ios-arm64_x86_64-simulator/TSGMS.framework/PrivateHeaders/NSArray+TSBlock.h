//
//  NSArray+TSBlock.h
//  TSGMS
//
//  Created by yxibng on 2021/6/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (TSBlock)
- (NSArray *)ts_map:(id (^)(id obj))block;
@end

NS_ASSUME_NONNULL_END
