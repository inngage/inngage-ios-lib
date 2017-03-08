

A biblioteca possui dois arquivos:

* `libPushNotificationManager.a`: é o binário da biblioteca.

* `PushNotificationManager.h`:é a claase header,  a partir de onde serão realizada as chamadas.

Para instalar, copie os arquivos para o seu projeto no Xcode.

* **
## **1 - Configuração do info.plist** ##

Adicionar a liberação para segurança de tráfego de dados

```html

<key>InngageAppToken</key>
<string>Token Usuário</string>
<key>InngageApiEndpoint</key>
<string>https://apid.inngage.com.br/v1</string>
<key>LSRequiresIPhoneOS</key>
<true/>
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
    <key>NSExceptionDomains</key>
    <dict>
        <key>www.inngage.me</key>
        <string></string>
    </dict>
</dict>

```

* **
## **2 - Create Bridging Header** ##

* Adicione um novo arquivo ao Xcode (File> New> File), selecione " Source " e clique em " Header File ".

* Nome do arquivo "YourProjectName-Bridging-Header.h"

Targets -> Build Settingns -> Objective-C Bridging Header

Adicionar na raiz do projeto :YourProjectName-Bridging-Header.h

* Na classe "YourProjectName-Bridging-Header.h" importar o Header da Lib 

```objective-c
#import "PushNotificationManager.h"


```

* **
## **3 - Configurações do projeto** ##

Targets -> Build Settingns -> Objective-C Bridging Header 

Adicionar :

* YourProjectName-Bridging-Header.h




