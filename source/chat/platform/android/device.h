/*

chat/platform/android/device.h

*/

#ifndef CHAT_PLATFORM_ANDROID_DEVICE_H
#define CHAT_PLATFORM_ANDROID_DEVICE_H

#include <string>

namespace chat::platform {
inline namespace android {

class device
{
public:

    std::string name() const;

};

} // inline namespace android
} // namespace chat::platform

#endif // CHAT_PLATFORM_ANDROID_DEVICE_H
