//
//  NSDictionary+TSBlock.h
//  TSGMS
//
//  Created by yxibng on 2021/6/25.
//

#import <Foundation/Foundation.h>
#import "TSGMSDefines.h"
NS_ASSUME_NONNULL_BEGIN

@interface __GENERICS(NSDictionary, KeyType, ObjectType) (TSBlock)
- (void)ts_each:(void (^)(KeyType key, ObjectType obj))block;
- (NSArray<id> *)ts_map:(id (^)(id key, id obj))block;
@end

NS_ASSUME_NONNULL_END
