/*

chat/folder/abstruct_element.h

*/

#ifndef CHAT_FOLDER_ABSTRUCT_ELEMENT_H
#define CHAT_FOLDER_ABSTRUCT_ELEMENT_H

#include <scapix/bridge/object.h>

namespace chat::folder {

class abstruct_element : public scapix::bridge::object<abstruct_element>
{
public:

	virtual ~abstruct_element() {}

	virtual void func1() = 0;
	virtual void func2() {}
	void func3() {}

};

} // namespace chat::folder

#endif // CHAT_FOLDER_ABSTRUCT_ELEMENT_H
