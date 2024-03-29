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
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <scapix/bridge/object.h>
#include <chat/contact.h>

#include <iostream>

namespace chat {

// test aliases
using string_type = std::string;
using integer16 = std::int16_t;

class session : public scapix::bridge::object<session>
{
public:

	using integer32 = std::int32_t;

	session() noexcept {}
	session(const string_type&) {}
	session(std::vector<string_type> vs, int, int, int, int) : strings_(vs) {}
	session(int) {}
	session(int, long long) {}
	session(std::string&& s1, std::string&& s2) { strings_.push_back(s1); strings_.push_back(s2); }
	session(std::string&& s1, std::string&& s2, const int&) { strings_.push_back(s1); strings_.push_back(s2); }
	session(std::string&& s1, std::string&& s2, const int&, long long) { strings_.push_back(s1); strings_.push_back(s2); }
	session(std::string s1, std::string s2, std::string = "") { strings_.push_back(s1); strings_.push_back(s2); }
	session(std::function<void()> callback) {}

	void int_test1(bool, std::int8_t, std::int16_t, std::int32_t, std::int64_t, integer16, integer32) noexcept {}
	void int_test2(const std::int8_t&, const std::int16_t&, const std::int32_t&, const std::int64_t&, const integer16&, const integer32&) {}

	void unsigned_test1(bool, std::uint8_t, std::uint16_t, std::uint32_t, std::uint64_t) noexcept {}
	void unsigned_test2(const std::uint8_t&, const std::uint16_t&, const std::uint32_t&, const std::uint64_t&) {}

	enum enum_type1 { one, two };
	enum class enum_type2 { one, two };

	enum_type1 enum_test1(enum_type1, enum_type2) { return one; }
	enum_type2 enum_test2(enum_type1, enum_type2) { return enum_type2::one; }

	const std::string& ref_test(const std::string&, std::string&&) { return name; }
	void int_test3(std::int8_t&&, std::int16_t&&, std::int32_t&&, std::int64_t&&, integer16&&, integer32&&) {}

	// Using int types directly works, but generates non-portable (target specific) code.
//	void int_test4(signed char, short, int, long, long long) {}

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

	std::shared_ptr<contact> object(std::shared_ptr<contact> m) { return m; }
	std::shared_ptr<std::string> object(std::shared_ptr<std::string> m) { return m; }
	int object(int m) { return m; }

	enum class color { red, green, blue };
	void test_enum(color) {}

	int operator + (int) { return 0; }
	~session() {}
	friend void friend_test() {}
	auto auto_test() { return 55; }
	auto auto_test2();

	int* test_unsupported_param_type() { return {}; }
	void test_unsupported_param_type(int, int*) {}

	void alias_test(std::string s1, string_type s2) {}

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
		catch (const std::exception& e)
		{
			std::cout << "caught " << e.what() << "\n";
		}
	}

	void throw_int()
	{
		throw 5;
	}

	void throw_exception()
	{
		throw std::runtime_error("test exception string");
	}

	const std::vector<std::string>& strings() const { return strings_; }

	std::vector<std::vector<std::uint8_t>> composed(std::vector<std::vector<std::uint8_t>> p) { return p; }
	std::unordered_map<std::uint16_t, std::vector<std::uint8_t>> composed2(std::unordered_map<std::uint16_t, std::vector<std::uint8_t>> p) { return p; }
	std::unordered_map<std::uint16_t, std::unordered_map<std::uint16_t, std::vector<std::uint8_t>>> composed3(std::unordered_map<std::uint16_t, std::unordered_map<std::uint16_t, std::vector<std::uint8_t>>> p) { return p; }
	std::unordered_map<std::uint16_t, std::unordered_map<std::uint16_t, std::string>> composed4(std::unordered_map<std::uint16_t, std::unordered_map<std::uint16_t, std::string>> p) { return p; }

private:

	std::string name = "session1";
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
