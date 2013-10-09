//
//  JSON.h
//  Dogo-iOS
//
//  Created by Marcus Westin on 6/27/13.
//  Copyright (c) 2013 Flutterby Labs Inc. All rights reserved.
//

#import "FunBase.h"

@interface JSON : FunBase

+ (NSString*)stringify:(id)obj;
+ (NSData*)serialize:(id)obj;
+ (id)parseString:(NSString*)string;
+ (id)parseData:(NSData*)data;

@end
