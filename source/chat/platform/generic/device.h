/*

chat/platform/generic/device.h

*/

#ifndef CHAT_PLATFORM_GENERIC_DEVICE_H
#define CHAT_PLATFORM_GENERIC_DEVICE_H

#include <string>

namespace chat::platform {
inline namespace generic {

class device
{
public:

    std::string name() const
    {
        return "generic";
    }

};

} // inline namespace generic
} // namespace chat::platform

#endif // CHAT_PLATFORM_GENERIC_DEVICE_H
