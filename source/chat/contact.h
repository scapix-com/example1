/*

chat/contact.h

*/

#ifndef CHAT_CONTACT_H
#define CHAT_CONTACT_H

#include <string>
#include <functional>
#include <scapix/bridge/object.h>
#include <chat/platform/device.h>

namespace chat {

/*
class contact_events : public scapix::bridge::interface<contact_events>
{
public:

	virtual void name_changed() = 0;
	virtual void id_changed() = 0;

};
*/

class contact;

class contact : public scapix::bridge::object<contact>
{
public:

	contact() {}
//	contact(int, float) {}
	contact(const std::string& id, const std::string& name) : id_(id), name_(name) {}

    std::string device_name() const { return platform::device().name(); }

    const std::string& id() { return id_; }
	void id(const std::string& id) { id_ = id; }
//	void id2(std::string&& id) { id_ = std::move(id); }

	const std::string& name() { return name_; }
	void name(const std::string& name) { name_ = name; }
//	void name2(std::string&& name) { name_ = std::move(name); }

//	std::shared_ptr<std::string> name2() { return name2_; }
	std::string* name22() { return name2_.get(); }
	void name3(std::string*) {}

//	void register_event_handler(std::shared_ptr<contact_events> handler) {}
	void register_on_name_change(std::function<void(std::string)> handler) {}

protected:

	void protected_func(){}
	void protected_func(int){}

private:

	std::string id_;
	std::string name_;
	std::shared_ptr<std::string> name2_;

};

} // namespace chat

#endif // CHAT_CONTACT_H
