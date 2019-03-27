/*

chat/platform/java/device.h

*/

#ifndef CHAT_PLATFORM_JAVA_DEVICE_H
#define CHAT_PLATFORM_JAVA_DEVICE_H

#include <string>

namespace chat::platform {
inline namespace java {

class device
{
public:

    std::string name() const;

};

} // inline namespace java
} // namespace chat::platform

#endif // CHAT_PLATFORM_JAVA_DEVICE_H
