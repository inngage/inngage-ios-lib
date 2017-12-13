//
//  PushNotificationManager.h
//  PushNotificationManager
//
//  Created by Luis Teodoro on 20/10/17.
//  Copyright © 2017 Luis Teodoro. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <sys/sysctl.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>


#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

@interface PushNotificationManager :NSObject<NSURLSessionDataDelegate>

/*CLLocationAccuracy -> The accuracy of a coordinate value, measured in meters.
 default:kCLLocationAccuracyBestType
*/
typedef NS_ENUM(NSInteger,  CLLocationAccuracyType) {
    kCLLocationAccuracyBestForNavigationType,
    kCLLocationAccuracyBestType,
    kCLLocationAccuracyNearestTenMetersType,
    kCLLocationAccuracyHundredMetersType,
    kCLLocationAccuracyKilometerType,
    kCLLocationAccuracyThreeKilometersType
};

@property NSString * inngageAppToken;

-(void)handlePushRegistration:(NSData *)deviceToken;

-(void)handlePushRegistration:(NSData *)deviceToken identifier:(NSString *)identifier;

-(void)handlePushRegistration:(NSData *)deviceToken customField:(NSDictionary *)customField;

-(void)handlePushRegistration:(NSData *)deviceToken identifier:(NSString *)identifier customField:(NSDictionary *)customField;

-(void)handlePushRegisterForRemoteNotifications:(UIUserNotificationSettings *)notificationSettings;

-(void)handlePushRegistrationFailure:(NSError *)error;

-(void)handlePushReceived:(NSDictionary *)userInfo;

-(void)handleUpdateLocations:(CLLocationManager *)locations;

-(void)openWebView:(NSString *)url;

- (void)startUpdatingLocation:(int)meters locationAccuracyType:(CLLocationAccuracyType )locationAccuracyType ;

+ (instancetype)sharedInstance;




@end
