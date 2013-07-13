//
//  Events.m
//  Dogo-iOS
//
//  Created by Marcus Westin on 6/26/13.
//  Copyright (c) 2013 Flutterby Labs Inc. All rights reserved.
//

#import "Events.h"

@implementation Events

static NSMutableDictionary* signals;
static NSInteger unique = 1;
static NSString* RefKey = @"Ref";
static NSString* CbKey = @"Cb";

+ (void)setup {
    signals = [NSMutableDictionary dictionary];
}

+ (EventsRef)on:(NSString *)signal callback:(EventCallback)callback {
    id ref = num(unique += 1);
    [self on:signal ref:ref callback:callback];
    return ref;
}

+ (EventsRef)on:(NSString *)signal ref:(EventsRef)ref callback:(EventCallback)callback {
    if (!signals[signal]) {
        signals[signal] = [NSMutableArray array];
    }
    [signals[signal] addObject:@{RefKey:ref, CbKey:callback}];
    return ref;
}

+ (void)off:(NSString *)signal ref:(EventsRef)ref {
    NSMutableArray* callbacks = signals[signal];
    for (NSDictionary* obj in callbacks) {
        if (obj[RefKey] == ref) {
            [callbacks removeObject:obj];
            break;
        }
    }
}

+ (void)emit:(NSString *)signal {
    [Events emit:signal info:nil];
}

+ (void)emit:(NSString *)signal info:(id)info {
    NSLog(@"Emit %@ %@", signal, info);
    NSArray* callbacks = [signals[signal] copy];
    for (NSDictionary* obj in callbacks) {
        EventCallback callback = obj[CbKey];
        callback(info);
    }
}
@end
