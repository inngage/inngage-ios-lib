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

@property NSString * inngageAppToken;
@property NSString * inngageApiEndpoint;
@property BOOL  defineLogs;


-(void)handlePushRegistration:(NSData *)deviceToken;

-(void)handlePushRegistration:(NSData *)deviceToken identifier:(NSString *)identifier;

-(void)handlePushRegistration:(NSData *)deviceToken customField:(NSDictionary *)customField;

-(void)handlePushRegistration:(NSData *)deviceToken identifier:(NSString *)identifier customField:(NSDictionary *)customField;

-(void)handlePushRegisterForRemoteNotifications:(UIUserNotificationSettings *)notificationSettings;

-(void)handlePushRegistrationFailure:(NSError *)error;

-(void)handlePushReceived:(NSDictionary *)userInfo messageAlert:(BOOL)messageAlert;

-(void)handleUpdateLocations:(CLLocationManager *)locations;

-(void)openWebView:(NSString *)url;

+ (instancetype)sharedInstance;

- (void)startMonitoringBackgroundLocation;
- (void)restartMonitoringBackgroundLocation;


@end
