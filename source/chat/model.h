/*

chat/model.h

*/

#ifndef CHAT_MODEL_H
#define CHAT_MODEL_H

#include <scapix/bridge/object.h>
#include <chat/contact.h>
#include <chat/session.h>

namespace chat {

struct struct1
{
	std::int32_t a;
	std::string b;
	std::vector<std::uint32_t> buffer;
};

struct struct2
{
	std::vector<std::string> strings;
	std::function<std::string(std::string)> callback;
	struct1 f1;
};

class model : public scapix::bridge::object<model>
{
public:

	model() {}

	void connect(std::string id, std::string password);
	void disconnect();

	const std::vector<std::shared_ptr<contact>>& friends() { return contacts_; }
	std::vector<std::shared_ptr<contact>> friends(std::string filter) { return {}; }

	void add_friend(std::shared_ptr<contact> contact) {}
	void remove_friend(std::shared_ptr<contact> contact) {}

	const std::vector<std::shared_ptr<session>>& sessions() { return sessions_; }
	std::shared_ptr<session> session_with_contact(std::shared_ptr<contact> contact) { return {}; }

	struct1 test_struct(struct2 p)
	{
		p.f1.a++;
		p.f1.b += " back from C++";
		p.f1.buffer.push_back(77);
		auto s = p.callback(p.strings[0]);
		return p.f1;
	}

	data test_struct(data d)
	{
		d.a++;
		d.b--;
		d.c = true;

		return d;
	}

private:

	std::vector<std::shared_ptr<contact>> contacts_;
	std::vector<std::shared_ptr<session>> sessions_;

};

} // namespace chat

#endif // CHAT_MODEL_H
