//
//  TSGMSMember.h
//  TS-GMS
//
//  Created by yxibng on 2020/5/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface TSGMSMember : NSObject

@property (nonatomic, copy, nonnull) NSString *userId;
@property (nonatomic, copy, nonnull) NSString *channelId;

///批量初始化方法有待改进
+ (NSArray<TSGMSMember *> *)membersFromArray:(NSArray *)array;

@end

NS_ASSUME_NONNULL_END
