
#include <cxxtest/TestSuite.h>
#include <gmock/gmock.h>
#include <memory>

#include "MessageCollection.hpp"
#include "Timeline.hpp"
#include "Message.hpp"

using ::testing::ByRef;
using ::testing::_;

struct MessageCollectionMock : public MessageCollection
{
    MOCK_METHOD1(add, void (std::shared_ptr<Message> message));
};

class TestTimeline : public CxxTest::TestSuite
{
private:


public:

TestTimeline()
{
}
~TestTimeline()
{
}

void testPublishAddsMessageToCollection(void)
{
    MessageCollectionMock               *mock = new MessageCollectionMock;
    std::shared_ptr<MessageCollection>  messageCollection(mock);
    Timeline                            timeline(messageCollection);
    std::shared_ptr<Message>            message(new Message);

    EXPECT_CALL(*mock, add(_)).Times(1);

    timeline.publish(message);

    TS_ASSERT(testing::Mock::VerifyAndClearExpectations(mock));
}

};

////////////////////////////////////////////////////////////////////////////////

