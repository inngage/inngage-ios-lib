//
//  NotificationViewController.m
//  Extension
//
//  Created by TQI on 30/10/17.
//  Copyright © 2017 Luis Teodoro. All rights reserved.
//

#import "NotificationViewController.h"
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>
#import "InngageAnimatedGIF.h"

@interface NotificationViewController () <UNNotificationContentExtension>

@property IBOutlet UILabel *label;

@end

@implementation NotificationViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any required interface initialization here.
}

- (void)didReceiveNotification:(UNNotification *)notification {
    
    if (notification.request.content.userInfo[@"otherCustomURL"]) {
        
        NSString *urlstring = notification.request.content.userInfo[@"otherCustomURL"];
        NSURL *url = [NSURL URLWithString:urlstring];
        
        UIImageView *  imageView = [[UIImageView alloc]init];
        imageView.image = [InngageAnimatedGIF animatedImageWithAnimatedGIFURL:url];
        
        imageView.frame = self.view.frame;
        [self.view addSubview:imageView];
    }
    
}

@end
