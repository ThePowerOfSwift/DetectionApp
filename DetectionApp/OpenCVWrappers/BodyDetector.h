//
//  BodyDetector.h
//  DetectionApp
//
//  Created by Anton Bal' on 1/17/19.
//  Copyright © 2019 Anton Bal'. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BodyObject.h"
#import <CoreVideo/CoreVideo.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, BodyDetectorType) {
    BodyDetectorTypeUpperBody              = 1 << 0,
    BodyDetectorTypeLowerBody              = 1 << 1,
    BodyDetectorTypeFullBody               = 1 << 2,
    BodyDetectorTypeFace                   = 1 << 3
};

typedef void (^CompletedBlock)(BodyObject* __nullable);

@interface BodyDetector: NSObject

- (instancetype)initWithType:(BodyDetectorType)type;

- (UIImage*) detectAndDrawImage:(UIImage*) img;

- (void) detectImageRef:(CVImageBufferRef) pixelBuffer size:(CGSize) size scale:(NSInteger) scale completed:(CompletedBlock)block;

#ifdef __cplusplus
- (cv::Mat) detect:(cv::Mat) image;
- (cv::Mat) detectAndDraw:(cv::Mat) img scale:(CGFloat) scale;
#endif

@end

NS_ASSUME_NONNULL_END
