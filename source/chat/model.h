/*

chat/model.h

*/

#ifndef CHAT_MODEL_H
#define CHAT_MODEL_H

#include <scapix/bridge/object.h>
#include <chat/contact.h>
#include <chat/session.h>

namespace chat {

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

private:

	std::vector<std::shared_ptr<contact>> contacts_;
	std::vector<std::shared_ptr<session>> sessions_;

};

} // namespace chat

#endif // CHAT_MODEL_H
