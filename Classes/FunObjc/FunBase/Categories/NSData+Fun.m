//
//  NSData+Fun.m
//  Dogo-iOS
//
//  Created by Marcus Westin on 6/27/13.
//  Copyright (c) 2013 Flutterby Labs Inc. All rights reserved.
//

#import "NSData+Fun.h"
#import "JSON.h"
#import "NSDate-Utilities.h"

@implementation NSData (Fun)

- (NSString *)toString {
    return [[NSString alloc] initWithData:self encoding:NSUTF8StringEncoding];
}

@end
