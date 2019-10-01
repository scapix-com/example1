/*

chat/folder/element.h

*/

#ifndef CHAT_FOLDER_ELEMENT_H
#define CHAT_FOLDER_ELEMENT_H

#include <chat/folder/abstruct_element.h>
#include <chat/contact.h>

namespace chat::folder {

class element : public abstruct_element
{
public:

	void func1() override {}
	void func4(std::shared_ptr<contact>) {}

};

} // namespace chat::folder

#endif // CHAT_FOLDER_ELEMENT_H
