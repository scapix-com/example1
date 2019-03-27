/*

chat/platform/apple/device.mm

*/

#include <chat/platform/apple/device.h>
#include <scapix/link/objc/convert.h>

namespace chat::platform {
inline namespace apple {

using namespace scapix::link::objc;

std::string device::name() const
{
//  auto arguments = convert_cpp<std::vector<std::string>>([[NSProcessInfo processInfo] arguments]);
//  auto environment = convert_cpp<std::map<std::string, std::string>>([[NSProcessInfo processInfo] environment]);
    return convert_cpp<std::string>([[NSProcessInfo processInfo] operatingSystemVersionString]);
}

} // inline namespace apple
} // namespace chat::platform
