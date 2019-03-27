/*

chat/platform/apple/device.h

*/

#ifndef CHAT_PLATFORM_APPLE_DEVICE_H
#define CHAT_PLATFORM_APPLE_DEVICE_H

#include <string>

namespace chat::platform {
inline namespace apple {

class device
{
public:

    std::string name() const;

};

} // inline namespace apple
} // namespace chat::platform

#endif // CHAT_PLATFORM_APPLE_DEVICE_H
