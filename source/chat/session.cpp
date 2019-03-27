/*

chat/session.cpp

*/

#include <chat/session.h>

namespace chat {

void session::add_contact(std::shared_ptr<contact> contact)
{
    contacts_.push_back(contact);
}

void session::remove_contact(std::shared_ptr<contact> contact)
{
}

std::string session::send_message(std::string message)
{
    return {};
}

void session::close()
{
}

void session::sample()
{
}

} // namespace chat
