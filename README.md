## **Inngage iOS Lib** ##

A biblioteca possui dois arquivos:

-  `InngageLibrary-Resources.bundle`: possui os arquivos de imagens utilizadas pela biblioteca;

-  `InngageLibrary.framework`: é o binário da biblioteca, a partir de onde serão realizada as chamadas.

Para instalar, copie os dois arquivos para raiz do seu projeto e adicione os dois arquivos ao projeto no Xcode.

### <a name="configuração"></a>Configuração

**Configuração do info.plist**

Adicionar a liberação para segurança de tráfego de dados

```html
<key>NSAppTransportSecurity</key>
<dict>
<key>NSAllowsArbitraryLoads</key>
<true/>
</dict>
<key>NSCameraUsageDescription</key>
<string>Camera usage description</string>
```

Adicionar a liberação para atualização da localização em Background

```html
<key>UIBackgroundModes</key>
<array>
<string>fetch</string>
<string>location</string>
</array>
```

Adicionar a liberação para acesso GPS (item específico para Geolocalização)

```html
<key>NSLocationWhenInUseUsageDescription</key>
<string>This application requires location services to work</string>
<key>NSLocationAlwaysUsageDescription</key>
<string>This application requires location services to work</string>
<key>NSLocationAlwaysAndWhenInUseUsageDescription</key>
<string>This application requires location services to work</string>
```


**Adicionar os frameworks padrões**

No projeto faça a importação do Framework:

Targets -> General ->Linked Frameworks and Libraries -> Add Other

Adicionar:
-  `InngageLibrary.framework`

Targets -> General -> Build Phases -> Copy Bundle Resources

Adicionar:
-  `InngageLibrary-Resources.bundle`

**Configurações do projeto**

Targets -> Build Settingns -> Header Search Paths

Adicionar :
- $(PROJECT_DIR)/InngageLibrary.framework/Headers

Targets -> Build Settingns -> Other Linker Flags

Adicionar:
- -lc++
- -ObjC
- -all_load

Targets -> Capabilities 

Habilitar Push Notification

**Configurações AppDelegate**

Importar a classe PushNotificationManager e criar as propriedades

```objective-c
#import "PushNotificationManager.h"

@property PushNotificationManager * manager;
@property NSDictionary * userInfoDict;
```

Adicionar as configurações do método  didFinishLaunchingWithOptions

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)])
    {
        [[UIApplication sharedApplication] registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:
        (UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil]];
    }

    self.manager = [PushNotificationManager sharedInstance ];

    //token inngage
    self.manager.inngageAppToken = @"XXXXXXXXXXXXXXXXXXXXXXXXXXXX";

    //endpoint inngage 
    self.manager.inngageApiEndpoint = @"https://apid.inngage.com.br/v1";

    //habilitar logs
    self.manager.defineLogs = YES;

    self.userInfoDict = [launchOptions objectForKey:UIApplicationLaunchOptionsRemoteNotificationKey];

    //Utilizar essas configurações somente se for enviar localização do usuário
    NSLog(@"UIApplicationLaunchOptionsLocationKey : %@" , [launchOptions objectForKey:UIApplicationLaunchOptionsLocationKey]);

    if ([launchOptions objectForKey:UIApplicationLaunchOptionsLocationKey]) {
        [self.manager startMonitoringBackgroundLocation];
    }

    return YES;
}

```

Adicionar as configurações para recebimento do push

```objective-c

- (void)application:(UIApplication *)application didRegisterUserNotificationSettings: (UIUserNotificationSettings
*)notificationSettings
{
    [application registerForRemoteNotifications];

    [self.manager handlePushRegisterForRemoteNotifications:notificationSettings];
}

- (void)application:(UIApplication *)application
didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {

    NSString * deviceTokenString = [[[[deviceToken description]
    stringByReplacingOccurrencesOfString: @"<" withString: @""]
    stringByReplacingOccurrencesOfString: @">" withString: @""]
    stringByReplacingOccurrencesOfString: @" " withString: @""];

    NSLog(@"The generated device token string is : %@",deviceTokenString);

    NSDictionary *jsonBody = @{ @"Phone":@"xxxxxxxx",
    @"Nome":@"xxxxxxxxx",
    @"Email":@"xxxxxxxx",
    };

    [self.manager handlePushRegistration:deviceToken identifier:@"12345678900" customField:jsonBody];

        if (self.userInfoDict != nil)
        {
            // messageAlert libera alertas dos push no app
            [self.manager handlePushReceived:self.userInfoDict messageAlert:YES];
        }
}

- (void)application:(UIApplication *)application
didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    NSLog(@"Registration for remote notification failed with error: %@", error.localizedDescription);

    [self.manager handlePushRegistrationFailure:error];

}

- (void)application:(UIApplication *)application
didReceiveRemoteNotification:(NSDictionary *)userInfo {

    // messageAlert libera alertas dos push no app
    [self.manager handlePushReceived:userInfo messageAlert:YES];

}

```

Utilizar essas configurações somente se for enviar localização do usuário

```objective-c

- (void)applicationDidEnterBackground:(UIApplication *)application {

    [self.manager restartMonitoringBackgroundLocation];

}

- (void)applicationDidBecomeActive:(UIApplication *)application {

    [self.manager startMonitoringBackgroundLocation];

}

```

## **Inngage iOS Rich Notification** ##

**Notification Content Extension**

No projeto faça a importação do Framework:

File -> New -> Target -> iOS > Notification Content Extension

![Imagem 1](/extension.png)

Clique em Next para continuar com a instalação.

![Imagem 2](/finish.png)

Preencha os campos necessários e clique em Finish.

![Imagem 3](/activate.png)

Ativar a Extension scheme para o target do projeto.

**Configuração do info.plist**

Adicionar a configuração para Rich Notificações:

```html
<key>NSExtension</key>
<dict>
<key>NSExtensionAttributes</key>
<dict>
<key>UNNotificationExtensionDefaultContentHidden</key>
<false/>
<key>UNNotificationExtensionCategory</key>
<string>br.com.inngage.Custom-Notification-Interface.notification</string>
<key>UNNotificationExtensionInitialContentSizeRatio</key>
<real>1</real>
</dict>
<key>NSExtensionMainStoryboard</key>
<string>MainInterface</string>
<key>NSExtensionPointIdentifier</key>
<string>com.apple.usernotifications.content-extension</string>
</dict>
```

**UNNotificationExtensionCategory**

Especifica o identificador de uma categoria declarada pelo aplicativo usando a classe UNNotificationCategory. Esse identificador é o utilizado para os Push Inngage.

**NSExtensionPointIdentifier**

Chaves e valores que descrevem uma extensão de aplicativo.

**UNNotificationExtensionDefaultContentHidden**

Quando configurado para SIM, o sistema exibe apenas o controlador de visualização personalizado na interface de notificação. Quando configurado para NO, o sistema exibe o conteúdo de notificação padrão, além do conteúdo do seu controlador de visualização.


**MainInterface.storyboard**

Para criar a interface personalizada, abra seu  arquivo MainInterface.storyboard . Em primeiro lugar, selecione o controlador de visualização e no inspetor de atributos , altere sua altura para ser igual à sua largura.

![Imagem 4](/MainInterface.png)

**Configurações NotificationViewController**

Importar a classe InngageAnimatedGIF.h

```objective-c
#import "InngageAnimatedGIF.h"
```

No método padrão criado na classe NotificationViewController adicionar as configurações para gerar o Rich Notification

```objective-c
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
```
**Inngage**

© 2015-2017 | Inngage - Engajamento de Usuários | Todos os direitos reservados.




