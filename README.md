# Eye-Protector

- This is a program that targets on Microsoft Windows to protect your eyes.
## Build
### Build with Visual Studio
[Download Visual Studio](https://amazingkenneth.github.io/docs/posts/tutorial/2022-02-19-install_CppCompiler.html#microsoft-visual-c)

See the [Documents](https://docs.microsoft.com/zh-cn/cpp/build/get-started-linux-cmake) for installation and configuration.
## Install
[Open the Latest Release](https://github.com/Amazingkenneth/Eye-Protector/releases/latest)

Put `Eye-Protector-<version>.exe` in your StartUp folder: `C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp`.

If setting the StartUp option needs the system administrator privileges, try typing `taskschd.msc` in `Win + R` pop-up window.

Put both "img-light.png" and "img-dark.png" into your `%USERPROFILE%\Pictures\Saved Pictures\` folder.

## Usages
Just simpily run the `Eye-Protector-<version>.exe`.

This program will make notificaions for 25 seconds every 20 minutes after you logged in.

## Further Details
For more details, please search for [20-20-20 Eye Protection Rules](https://bing.com/search?q=20-20-20+Eye+Protection+Rules).
  
![image](https://amazingkenneth.github.io/images/TipsToEaseEyeStrain.jpeg)
![image](https://amazingkenneth.github.io/images/HowToEaseYourEyes.jpeg)

## Thanks To
- [WinToast](https://github.com/mohabouje/WinToast), for containing the notification.