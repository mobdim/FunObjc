//
//  Audio.h
//  ivyq
//
//  Created by Marcus Westin on 10/8/13.
//  Copyright (c) 2013 Flutterby Labs Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AudioGraph.h"
#import "FunObjc.h"

typedef float Pitch; // pitch=[-1,1]
typedef void(^AudioPlaybackProgressCallback)(BOOL stopped, float progress);

@interface AudioPlayer : AVAudioPlayer <AVAudioPlayerDelegate>
- (void)setProgress:(float)progress;
- (void)setPlaybackProgressCallback:(AudioPlaybackProgressCallback)progressCallback;
- (void)setPlaybackCompleteCallback:(Block)completeCallback;
@end
typedef void(^AudioPlayerCallback)(AudioPlayer* player);

@interface AudioEffects : NSObject
@property Pitch pitch;
+ (instancetype)withPitch:(Pitch)pitch;
@end

@interface Audio : NSObject
+ (BOOL)recordFromMicrophoneToFile:(NSString*)path;
+ (void)stopRecordingFromMicrophone:(Block)callback;
+ (BOOL)playToSpeakerFromFile:(NSString*)path;
+ (BOOL)playToSpeakerFromFile:(NSString*)path effects:(AudioEffects*)effects;
+ (float)readFromFile:(NSString*)fromPath toFile:(NSString*)toPath;
+ (float)readFromFile:(NSString*)fromPath toFile:(NSString*)toPath effects:(AudioEffects*)effects;
+ (NSTimeInterval)getDurationForFile:(NSString*)path;

+ (void)loadUrl:(NSString *)url callback:(AudioPlayerCallback)callback;

+ (void)setSessionToPlayback;
@end
