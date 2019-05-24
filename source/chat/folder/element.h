/*

chat/folder/element.h

*/

#ifndef CHAT_FOLDER_ELEMENT_H
#define CHAT_FOLDER_ELEMENT_H

#include <scapix/bridge/object.h>
#include <chat/contact.h>

namespace chat::folder {

class element : public scapix::bridge::object<element>
{
public:

	void func1(std::string id, std::string password) {}
	void func2(std::shared_ptr<contact>) {}
	std::shared_ptr<contact> func3() { return {}; }

};

} // namespace chat::folder

#endif // CHAT_FOLDER_ELEMENT_H
