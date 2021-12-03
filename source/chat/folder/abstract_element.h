/*

chat/folder/abstract_element.h

*/

#ifndef CHAT_FOLDER_ABSTRACT_ELEMENT_H
#define CHAT_FOLDER_ABSTRACT_ELEMENT_H

#include <string>
#include <vector>
#include <memory>
#include <scapix/bridge/object.h>

namespace chat::folder {

class abstract_element : public scapix::bridge::object<abstract_element>
{
public:

	virtual ~abstract_element() = default;

	virtual std::vector<std::string> func1(std::vector<std::string> s) = 0;
	virtual std::vector<std::string> func2(std::vector<std::string> s) final { s.push_back("abstract_element::func2"); return func1(s); }
	virtual std::string func3(std::string, int, std::shared_ptr<abstract_element>) const & noexcept { return {}; }
	void func4() {}

};

class abstract_element2 : public scapix::bridge::object<abstract_element2>
{
public:

	virtual ~abstract_element2() = default;

	virtual void func1() const noexcept(true) = 0;
	virtual void func1(int) const noexcept(true) = 0;
	virtual void func2() { func1(); }
	virtual std::string func3(std::string&&, int, std::shared_ptr<abstract_element>) const noexcept { return {}; }
	void func4() && {}

};

class abstract_element3 final : public scapix::bridge::object<abstract_element3>
{
public:

	virtual void func1() {}

};

class abstract_element4 : public abstract_element
{
public:

	std::vector<std::string> func1(std::vector<std::string> s) override { s.push_back("abstract_element4::func1"); return s; }

};

} // namespace chat::folder

class abstract_element5 : public chat::folder::abstract_element
{
public:

	std::vector<std::string> func1(std::vector<std::string> s) override { s.push_back("abstract_element5::func1"); return s; }

};

#endif // CHAT_FOLDER_ABSTRACT_ELEMENT_H
