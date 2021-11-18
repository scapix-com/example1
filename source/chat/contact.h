/*

chat/contact.h

*/

#ifndef CHAT_CONTACT_H
#define CHAT_CONTACT_H

#include <string>
#include <vector>
#include <functional>
#include <scapix/bridge/object.h>
#include <chat/platform/device.h>

namespace chat {

// Implement this interface in bridged languages, to receive events from C++.
// Overriding C++ virtual functions in bridged languages currently supported only by Python and JavaScript bridge, support for other languages coming soon.
// You can also use std::function<> parameters to receive events from C++.

class contact_events : public scapix::bridge::object<contact_events>
{
public:

	virtual ~contact_events() = default;

	virtual void name_changed() = 0;
	virtual void id_changed() = 0;

};

struct data
{
	std::int32_t a;
	float b;
	bool c;
};

class contact;

class contact : public scapix::bridge::object<contact>
{
public:

	static std::shared_ptr<contact> create() { return std::make_shared<contact>(); }

	std::vector<std::int8_t> int8_vec() const { return {0, 1, 2}; }
	std::vector<std::int16_t> int16_vec() const { return {0, 1, 2}; }
	std::vector<std::int32_t> int32_vec() const { return {0, 1, 2}; }
	std::vector<std::int64_t> int64_vec() const { return {0, 1, 2}; }

	std::vector<std::uint8_t> uint8_vec() const { return {0, 1, 2}; }
	std::vector<std::uint16_t> uint16_vec() const { return {0, 1, 2}; }
	std::vector<std::uint32_t> uint32_vec() const { return {0, 1, 2}; }
	std::vector<std::uint64_t> uint64_vec() const { return {0, 1, 2}; }

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
	void register_on_name_change(std::function<void(std::string)> handler) { handler("callback from C++"); }
	void callback2(std::function<void(std::shared_ptr<contact>)> handler) { handler(std::make_shared<contact>("id2", "name2")); }

	void send_contacts(std::vector<std::shared_ptr<contact>> friends) {}

	std::vector<std::int32_t> test_array(std::vector<std::int32_t> a)
	{
		for (auto& i : a)
			++i;

		a.push_back(777);
		a.push_back(888);

		return a;
	}

	std::vector<float> test_array2(std::vector<float> a)
	{
		for (auto& i : a)
			++i;

		a.push_back(77.7f);
		a.push_back(88.8f);

		return a;
	}

	data test_struct(data d)
	{
		d.a++;
		d.b--;
		d.c = true;

		return d;
	}

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
