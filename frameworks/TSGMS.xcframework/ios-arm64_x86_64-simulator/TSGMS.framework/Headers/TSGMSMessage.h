//
//  TSGMSMessage.h
//  TS-GMS
//
//  Created by 钟凡 on 2020/7/15.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    TSGMSMessageTypeUndefined = 0,
    TSGMSMessageTypeText = 1,
    TSGMSMessageTypeRaw = 2,
} TSGMSMessageType;

NS_ASSUME_NONNULL_BEGIN

@interface TSGMSMessage : NSObject

@property (nonatomic, assign, readonly) TSGMSMessageType type;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, assign) long long serverReceivedTs;
@property (nonatomic, assign, readonly) BOOL isOfflineMessage;

- (instancetype _Nonnull)initWithText:(NSString *_Nonnull)text;

@end


@interface TSGMSRawMessage : TSGMSMessage

@property (nonatomic, nonnull) NSData *rawData;

- (instancetype _Nonnull)initWithRawData:(NSData *_Nonnull)data;

@end

NS_ASSUME_NONNULL_END
