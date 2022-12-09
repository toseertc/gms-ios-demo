//
//  TSGMSDefines.h
//  TSGMS
//
//  Created by yxibng on 2021/6/25.
//

#ifndef TSGMSDefines_h
#define TSGMSDefines_h

#if __has_feature(objc_generics)
#   define __GENERICS(class, ...)      class<__VA_ARGS__>
#   define __GENERICS_TYPE(type)       type
#else
#   define __GENERICS(class, ...)      class
#   define __GENERICS_TYPE(type)       id
#endif




#endif /* TSGMSDefines_h */
