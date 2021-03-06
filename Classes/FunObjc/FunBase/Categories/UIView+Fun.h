//
//  UIView+Fun.h
//  ivyq
//
//  Created by Marcus Westin on 9/10/13.
//  Copyright (c) 2013 Flutterby Labs Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FunBase.h"

@interface UIView (Fun)

/* Lifecycle
 ***********/
// First time render
- (void)render;
// Clean up when removed from window
- (void)cleanup;
// Recursively call cleanup on all subviews.
// This gets called automatically on any FunViewController subview.
- (void)recursivelyCleanup;

/* Size
 ******/
- (CGFloat)height;
- (CGFloat)width;
- (CGSize)size;
- (void)setWidth:(CGFloat)width;
- (void)setHeight:(CGFloat)height;
- (void)setSize:(CGSize)size;
- (void)addWidth:(CGFloat)width height:(CGFloat)height;
- (void)containSubviews;
- (void)containLastViewVertically;
- (void)containSubviewsHorizontally;
- (void)containSubviewsVertically;
- (void)setHeightUp:(CGFloat)height;
- (void)addHeightUp:(CGFloat)addHeight;
- (void)addSize:(CGSize)size;

/* Position
 **********/
- (void)centerInSuperview;
- (void)centerVertically;
- (void)centerHorizontally;
- (void)moveByX:(CGFloat)x y:(CGFloat)y;
- (void)moveByY:(CGFloat)y;
- (void)moveByX:(CGFloat)x;
- (void)moveToX:(CGFloat)x y:(CGFloat)y;
- (void)moveToX:(CGFloat)x;
- (void)moveToY:(CGFloat)y;
- (void)moveToPosition:(CGPoint)origin;
- (void)moveByVector:(CGVector)vector;
- (CGPoint)topRightCorner;
- (CGPoint)topLeftCorner;
- (CGPoint)bottomLeftCorner;
- (CGPoint)bottomRightCorner;
- (CGFloat)x;
- (CGFloat)y;
- (CGFloat)x2;
- (CGFloat)y2;
- (CGFloat)centerX;
- (CGFloat)centerY;
- (CGRect)centerSquare:(CGFloat)size;
- (void)setCenterX:(CGFloat)x;
- (void)setCenterY:(CGFloat)y;
- (void)setX:(CGFloat)x;
- (void)setY:(CGFloat)y;
- (void)setX2:(CGFloat)x2;
- (void)setY2:(CGFloat)y2;
- (CGRect)frameInWindow;
- (CGRect)frameInView:(UIView*)view;

/* Borders, Shadows, Insets & Blurs
 **********************************/
- (void)setOutsetShadowColor:(UIColor*)color radius:(CGFloat)radius spread:(CGFloat)spread x:(CGFloat)offsetX y:(CGFloat)offsetY;
- (void)setInsetShadowColor:(UIColor*)color radius:(CGFloat)radius spread:(CGFloat)spread x:(CGFloat)offsetX y:(CGFloat)offsetY;
- (void)setOutsetShadowColor:(UIColor*)color radius:(CGFloat)radius;
- (void)setInsetShadowColor:(UIColor*)color radius:(CGFloat)radius;
- (void)setBorderColor:(UIColor*)color width:(CGFloat)width;
- (void)setGradientColors:(NSArray*)colors;
- (void)blur;

/* View hierarchy
 ****************/
- (instancetype)empty;
- (void)appendTo:(UIView*)superview;
- (void)prependTo:(UIView*)superview;
- (UIView*)firstSubview;
- (UIView*)lastSubview;
- (void)removeAndClean;

/* Screenshot
 ************/
typedef void(^GhostCallback)(UIView* ghostView);
- (UIImage*)captureToImage;
- (UIImage*)captureToImageWithScale:(CGFloat)scale;
- (NSData*)captureToPngData;
- (NSData*)captureToJpgData:(CGFloat)compressionQuality;
- (UIView*)ghost;
- (void)ghostWithDuration:(NSTimeInterval)duration animation:(GhostCallback)animationCallback;
- (void)ghostWithDuration:(NSTimeInterval)duration animation:(GhostCallback)animationCallback completion:(GhostCallback)completionCallback;
- (void)ghostWithDuration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options animations:(GhostCallback)animationCallback;
- (void)ghostWithDuration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options animations:(GhostCallback)animationCallback completion:(GhostCallback)completionCallback;

/* Animations
 ************/
+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options animations:(void (^)(void))animations;
- (void)rotate:(NSTimeInterval)duration;
- (void)stopRotating;
@end
