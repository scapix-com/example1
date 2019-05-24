/*

chat/extended_contact.h

*/

#ifndef CHAT_EXTENDED_CONTACT_H
#define CHAT_EXTENDED_CONTACT_H

#include <string>
#include <chat/contact.h>

namespace chat {

class extended_contact : public contact
{
public:

	void test(std::string, std::shared_ptr<contact>, std::shared_ptr<extended_contact>) {}

};

} // namespace chat

#endif // CHAT_EXTENDED_CONTACT_H
