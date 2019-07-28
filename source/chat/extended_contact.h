/*

chat/extended_contact.h

*/

#ifndef CHAT_EXTENDED_CONTACT_H
#define CHAT_EXTENDED_CONTACT_H

#include <string>
#include <chat/contact.h>

namespace chat {

class contact;

class extended_contact : public contact
{
public:

	using contact::contact;
	extended_contact(int):contact("1", "2"){}
	extended_contact() = default;

	void test(std::string, std::shared_ptr<contact>, std::shared_ptr<extended_contact>) {}

// msvc bug
#ifndef _MSC_VER
	using contact::protected_func;
	using contact::id;
#endif

};

class extended_contact2 : public extended_contact
{
public:

	void test() {}

};

class extended_contact3 : public contact
{
public:

	void test() {}

};

} // namespace chat

#endif // CHAT_EXTENDED_CONTACT_H
