//
//  EmailAddresses.h
//  Dogo-iOS
//
//  Created by Marcus Westin on 6/28/13.
//  Copyright (c) 2013 Flutterby Labs Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EmailAddresses : NSObject

+ (NSString*)normalize:(NSString*)email;

@end
