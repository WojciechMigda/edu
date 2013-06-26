#include "Message.hpp"
#include "MessageCollection.hpp"

#include <memory>

class Timeline
{
private:
std::shared_ptr<MessageCollection> messageCollection;

public:

explicit Timeline(std::shared_ptr<MessageCollection> messageCollection);

void publish(std::shared_ptr<Message> message);
};
