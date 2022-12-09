//
//  TSGMSUserAttributes.h
//  TSGMS
//
//  Created by yxibng on 2021/5/31.
//

#import <Foundation/Foundation.h>
#import "TSGMSAttribute.h"
#import "TSEnumerates.h"

NS_ASSUME_NONNULL_BEGIN


@interface TSGMSAttributeWithState: TSGMSAttribute
/// 属性是否被移除
@property (nonatomic, assign) BOOL deleted;
@end


@interface TSGMSUserAttributes : NSObject

@property (nonatomic, copy) NSString *userId;
@property (nonatomic, strong) NSArray<TSGMSAttributeWithState *> * attributes;

- (instancetype)initWithUserId:(NSString *)userId;
- (void)configAttributes:(NSDictionary *)attributes;
@end

NS_ASSUME_NONNULL_END
