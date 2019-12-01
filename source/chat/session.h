/*

chat/session.h

*/

#ifndef CHAT_SESSION_H
#define CHAT_SESSION_H

#include <string>
#include <vector>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <scapix/bridge/object.h>
#include <chat/contact.h>
#include <boost/container/vector.hpp>

#include <iostream>

namespace chat {

// test aliases
using string_type = std::string;
using integer = int;

class session : public scapix::bridge::object<session>
{
public:

	session() {}
	session(const string_type&) {}
	session(std::vector<string_type> vs, int, int, int, int) : strings_(vs) {}
	session(int) {}
	session(int, long long) {}
	session(std::string&& s1, std::string&& s2) { strings_.push_back(s1); strings_.push_back(s2); }
	session(std::string&& s1, std::string&& s2, const int&) { strings_.push_back(s1); strings_.push_back(s2); }
	session(std::string&& s1, std::string&& s2, const int&, long long) { strings_.push_back(s1); strings_.push_back(s2); }
	session(std::string s1, std::string s2, std::string = "") { strings_.push_back(s1); strings_.push_back(s2); }
	session(std::function<void()> callback) {}

//	void test_int(bool, const bool&, bool&&, int, const int&, int&&) {}

	// In case of conflict, only the first overloaded function is bridged:

	std::string string(std::string filter) { return filter; }
	std::string string(std::string filter) const { return filter; }
	std::string& string(std::string& filter) { return filter; }
	std::string&& string(std::string&& filter) { return std::move(filter); }
	const std::string& string(const std::string& filter) { return filter; }
	const std::string&& string(const std::string&& filter) { return std::move(filter); }

	// test java keywords

	void test_java_keyword(int package) {}
	void synchronized() {}

	// test python keywords
    
	void global() {}
	void del() {}

	// test snake case conversion

	void getHTTPRequest22() {}
	void SetHTTP2Request_3D() {}
	void SetHTTP2Request_4d() {}
	void someCSharpName() {}
	void _someNSStringName_() {}
	void HELLO_HTTP2A333De8() {}
	void HELLO_Http() {}

	// test integers: prefer using std::intXX_t types for portability

	void int_test1(std::int8_t, std::int16_t, std::int32_t, std::int64_t) {}
	void int_test2(signed char, short, int, long, long long) {}

	std::shared_ptr<contact> object(std::shared_ptr<contact> m) { return m; }
	std::shared_ptr<std::string> object(std::shared_ptr<std::string> m) { return m; }
	int object(int m) { return m; }

	enum class color { red, green, blue };
	void test_enum(color) {}

	int operator + (int) { return 0; }
	~session() {}
	friend void friend_test() {}
	auto auto_test() { return 0; }
	auto auto_test2();

	int* test_unsupported_param_type() { return {}; }
	void test_unsupported_param_type(int, int*) {}
	void test_unsupported_param_type(std::string, boost::container::vector<int>) {}

	void alias_test(std::string s1, string_type s2, int i1, integer i2) {}

	void async_connect(std::string host, std::function<void(string_type)> handler) {}

	const std::vector<std::shared_ptr<contact>>& contacts() { return contacts_; }
	std::vector<std::shared_ptr<contact>> contacts(std::string filter) { return contacts_; }

	std::map<std::string, std::shared_ptr<contact>> map(std::map<std::string, std::shared_ptr<contact>> m) { m.emplace("added from C++", std::make_shared<contact>()); return m; }
	std::map<std::string, std::string> map(std::map<std::string, std::string> m) { return m; }
	std::map<int, std::string> map2(std::map<int, std::string> m) { return m; }
	std::map<int, float> map3(std::map<int, float> m) { return m; }

	std::set<std::string> set(std::set<std::string> s) { return s; }
	std::unordered_map<std::string, std::shared_ptr<contact>> unordered_map(std::unordered_map<std::string, std::shared_ptr<contact>> s) { return s; }
	std::unordered_set<std::string> unordered_set(std::unordered_set<std::string> s) { return s; }

	std::vector<std::shared_ptr<contact>> tags(std::vector<std::shared_ptr<contact>> tags) { return contacts_; }
	std::vector<int> ints(std::vector<int> ints) { return ints; }
	std::vector<std::string> strings(std::vector<std::string>) { return {}; }

	void add_contact(std::shared_ptr<contact> contact);
	void remove_contact(std::shared_ptr<contact> contact);

	std::string send_message(std::string message);
	void send_message2(std::string message, int count) {}
	std::string send_message3(std::shared_ptr<contact> contact, std::string message, int count) { return message + std::to_string(count); }

	void close();

	std::shared_ptr<contact> sample2() { return nullptr; }
	std::shared_ptr<contact> sample2(bool/*, char*/, short, int/*, long*/, float, double) { return nullptr; }

	static void sample();
	static int sample(std::string, std::vector<std::string>) { return {}; }

	auto connect(std::function<int(std::string, std::vector<std::shared_ptr<contact>>)> handler)
	{
		return handler("hello2", contacts_);
	}

	using handler_type = int(std::string, std::vector<std::shared_ptr<contact>>);

	void connect2(std::function<handler_type> handler)
	{
		[[maybe_unused]] auto r = handler("hello3", contacts_);
	}

	void connect3(std::function<std::string(std::string, std::vector<std::shared_ptr<contact>>)> handler)
	{
		[[maybe_unused]] auto r = handler("hello2", contacts_);
	}

	void connect4(std::function<std::string(int, std::vector<std::shared_ptr<contact>>)> handler)
	{
		[[maybe_unused]] auto r = handler(55, contacts_);
	}

//    std::function<handler_type> connect5(std::function<std::string(int, std::vector<std::shared_ptr<contact>>)> handler)
//    {
//        [[maybe_unused]] auto r = handler(55, contacts_);
//        return nullptr;
//    }
//
//    std::function<handler_type> connect6(std::function<std::string(int, std::function<handler_type>)> handler)
//    {
//        [[maybe_unused]] auto r = handler(55, nullptr);
//        return nullptr;
//    }

	void connect7(std::vector<std::vector<std::function<void()>>>)
	{
	}

	void connect8(std::vector<std::vector<std::string>>)
	{
	}

	void test_exception(std::function<void()> callback)
	{
		try
		{
			callback();
		}
		catch (int e)
		{
			std::cout << "caught " << e << "\n";
		}
	}

	void throw_exception()
	{
		throw 5;
	}

	const std::vector<std::string>& strings() const { return strings_; }

private:

	std::vector<std::string> strings_;
	std::vector<std::shared_ptr<contact>> contacts_;

};

class session2 : public scapix::bridge::object<session2>
{
public:

	void add_contact(std::shared_ptr<contact> contact) {}
	void add_session(std::shared_ptr<session> session) {}
	void add_session2(std::shared_ptr<session2> session) {}

};
    
} // namespace chat

#endif // CHAT_SESSION_H
