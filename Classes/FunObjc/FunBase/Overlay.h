//
//  Overlay.h
//  Dogo-iOS
//
//  Created by Marcus Westin on 6/28/13.
//  Copyright (c) 2013 Flutterby Labs Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIControl+Fun.h"

@interface Overlay : NSObject

+ (UIWindow*)show;
+ (UIWindow*)showMessage:(NSString*)message;
+ (UIWindow*)showWithTapHandler:(TapHandler)tapHandler;
+ (void)hide;

@end
