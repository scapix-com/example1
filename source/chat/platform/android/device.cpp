/*

chat/platform/android/device.cpp

*/

#include <chat/platform/android/device.h>
#include <scapix/java_api/android/os/Build.h>

namespace chat::platform {
inline namespace android {

using namespace scapix::java_api;
namespace android = scapix::java_api::android; // because of conflict with current namespace

std::string device::name() const
{
    return android::os::Build::MODEL_();
}

} // inline namespace android
} // namespace chat::platform
