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





