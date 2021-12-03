/*

chat/folder/element.h

*/

#ifndef CHAT_FOLDER_ELEMENT_H
#define CHAT_FOLDER_ELEMENT_H

#include <chat/folder/abstract_element.h>
#include <chat/contact.h>

namespace chat::folder {

class element : public abstract_element
{
public:

	std::vector<std::string> func1(std::vector<std::string> s) override { s.push_back("element::func1"); return s; }
	void func4(std::shared_ptr<contact>) {}

};

} // namespace chat::folder

#endif // CHAT_FOLDER_ELEMENT_H
