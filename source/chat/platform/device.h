/*

chat/platform/device.h

*/

#ifndef CHAT_PLATFORM_DEVICE_H
#define CHAT_PLATFORM_DEVICE_H

#include <chat/platform/config.h>
#include CHAT_PLATFORM_INCLUDE(device.h)

namespace chat::platform {

#ifdef __cpp_concepts

template<typename T>
concept bool Device = requires(const T a, T b)
{
    { a.name() } -> std::string;
};

static_assert(Device<device>);

#endif // __cpp_concepts

} // namespace chat::platform

#endif // CHAT_PLATFORM_DEVICE_H
