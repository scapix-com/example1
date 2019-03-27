/*

chat/platform/windows/device.h

*/

#ifndef CHAT_PLATFORM_WINDOWS_DEVICE_H
#define CHAT_PLATFORM_WINDOWS_DEVICE_H

#include <string>

namespace chat::platform {
inline namespace windows {

class device
{
public:

    std::string name() const
    {
        return "windows";
    }

};

} // inline namespace windows
} // namespace chat::platform

#endif // CHAT_PLATFORM_WINDOWS_DEVICE_H
