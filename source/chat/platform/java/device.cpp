/*

chat/platform/java/device.cpp

*/

#include <chat/platform/java/device.h>
#include <scapix/java_api/java/lang/System.h>

namespace chat::platform {
inline namespace java {

using namespace scapix::java_api;
namespace java = scapix::java_api::java; // because of conflict with current namespace

std::string device::name() const
{
    return java::lang::System::getProperty("java.version");
}

} // inline namespace java
} // namespace chat::platform
