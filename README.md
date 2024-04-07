# LxWatch-ESP32-BLE-ANCS
> ANCS of iPhone by using ESP32 BLE
## 1. HardWare
*ESP32-Pico-D4*  
*iPhone12(IOS 16.3.1)*  
Confident in being compatible with the majority of models/versions of iPhone/ios.
## 2. Characters
1. Based on LOW-POWER development  
2. The ESP chip achieves BIDIRECTIONAL AUTOMATIC connection with the iPhone  
3. Filtering of different message types  
4. It **CAN** run for my iPhone  
... ...
## 3. Methods
The main program is in a file named 'LXANCS.cpp', including the header file for 'LXANCS.h'. 

**FIRST**：After running the 'lx_ancs_begin()' function in 'LXANCS.cpp', the ESP chip starts broadcasting.  
**SECOND**：From now on, you can then **SEARCH** and **CONNECT** using your iPhone Bluetooth.  
**FINALLY**：Once the connection is successful, it will continuously return received messages in real-time, allowing you to perform your custom operations in the 'onNotificationArrived()' function.  

>Make sure your iPhone has the "*Share Messages*" setting enabled.  
## Acknowledgements
Thanks for the significant contribution made by the 'ESP32-ANCS-Notifications' project.  
>https://github.com/Smartphone-Companions/ESP32-ANCS-Notifications.  
>Our project has only made minor adjustments for slight incompatibilities.  

If you encounter any **UNKNOWN** issues using other ANCS methods, you can **TRY** the code provided by this project.

