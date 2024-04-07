#include "LXANCS.h"
#include "esp32notifications.h"
#include "ancs_notification_queue.h"

BLENotifications notifications;

void onBLEStateChanged(BLENotifications::State state)
{
    switch (state)
    {
    case BLENotifications::StateConnected:
        Serial.println("StateConnected - connected to a phone or tablet");
        
        break;

    case BLENotifications::StateDisconnected:
        Serial.println("StateDisconnected - disconnected from a phone or tablet");
        /* We need to startAdvertising on disconnection, otherwise the ESP 32 will now be invisible.
        IMO it would make sense to put this in the library to happen automatically, but some people in the Espressif forums
        were requesting that they would like manual control over re-advertising.*/
        break;
    }
}

// A notification arrived from the mobile device, ie a social media notification or incoming call.
// parameters:
//  - notification: an Arduino-friendly structure containing notification information. Do not keep a
//                  pointer to this data - it will be destroyed after this function.
//  - rawNotificationData: a pointer to the underlying data. It contains the same information, but is
//                         not beginner-friendly. For advanced use-cases.
void onNotificationArrived(const ArduinoNotification *notification, const Notification *rawNotificationData)
{
    Serial.println("Got notification: ");
    Serial.println(notification->title);                                                      // The title, ie name of who sent the message
    Serial.println(notification->message);                                                    // The detail, ie "be home for dinner at 7".
    Serial.println(notification->type);                                                       // Which app sent it
    Serial.println(notifications.getNotificationCategoryDescription(notification->category)); // ie "social media"
    Serial.println(notification->categoryCount);                                              // How may other notifications are there from this app (ie badge number)
    uint8_t type;

    /* Replace below with your Code when notification is coming, here is A DEMO*/
    if (notification->title.equals("QQ"))
    { //! QQ
        type = 1;
    }
    else if (notification->type.equals("com.tencent.xin"))
    { //! wechat
        type = 2;
    }
    
    vTaskDelay(200 / portTICK_PERIOD_MS);

    if (type == 1)
    {
        uint8_t index = notification->message.indexOf(":");
        String words = notification->message.substring(index+1, notification->message.length()); // 信息
        if (words.length() > 22)
        { //! overlength deal
            words = words.substring(0, 22) + "...";
        }
        //ui_message_show(type, notification->message.substring(0, index+1).c_str(), words.c_str());
    }
    if (type == 2)
    {
        String words = notification->message;
        if (words.length() > 22)
        { //! overlength deal
            words = words.substring(0, 22) + "...";
        }
        //ui_message_show(type, notification->title.c_str(), words.c_str());
    }
}

// A notification was cleared
void onNotificationRemoved(const ArduinoNotification *notification, const Notification *rawNotificationData)
{
    Serial.print("Removed notification: ");
    Serial.println(notification->title);
    Serial.println(notification->message);
    Serial.println(notification->type);
    /* Replace below with your Code when notification is removed, here is A DEMO*/
    //ui_message_clear();
}

void lx_ancs_begin()
{
    Serial.begin(115200);
    while (!Serial)
    {
        delay(10);
    }
    Serial.println("ESP32-ANCS-Notifications Example");
    Serial.println("------------------------------------------");

    // Set up the BLENotification library
    notifications.begin("LxWatch");
    notifications.setConnectionStateChangedCallback(onBLEStateChanged);
    notifications.setNotificationCallback(onNotificationArrived);
    notifications.setRemovedCallback(onNotificationRemoved);
}

void lx_ancs_end()
{
    notifications.stop();
}
