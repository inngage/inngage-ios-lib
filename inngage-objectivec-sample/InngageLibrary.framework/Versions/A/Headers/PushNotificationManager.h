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

-(void)handlePushRegistration:(NSData *)deviceToken;

-(void)handlePushRegistration:(NSData *)deviceToken identifier:(NSString *)identifier;

-(void)handlePushRegistration:(NSData *)deviceToken customField:(NSDictionary *)customField;

-(void)handlePushRegistration:(NSData *)deviceToken identifier:(NSString *)identifier customField:(NSDictionary *)customField;

-(void)handlePushRegisterForRemoteNotifications:(UIUserNotificationSettings *)notificationSettings;

-(void)handlePushRegistrationFailure:(NSError *)error;

-(void)handlePushReceived:(NSDictionary *)userInfo;

-(void)handleUpdateLocations:(CLLocationManager *)locations;

+ (instancetype)sharedInstance;

@property NSString * inngageAppToken;

-(void)openWebView:(NSString *)url;

- (void)startUpdatingLocation:(int)meters locationAccuracyType:(CLLocationAccuracyType )locationAccuracyType ;

@end
