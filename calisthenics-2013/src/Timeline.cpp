#include <memory>
#include "MessageCollection.hpp"
#include "Timeline.hpp"

Timeline::Timeline(std::shared_ptr<MessageCollection> _messageCollection)
:
    messageCollection(_messageCollection)
{
;
}

void Timeline::publish(std::shared_ptr<Message> message)
{
    messageCollection->add(message);
}
