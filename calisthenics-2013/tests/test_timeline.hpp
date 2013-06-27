/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: test_timeline.hpp
 *
 * Description:
 *      description
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2013-06-27   wm              Initial version
 *
 ******************************************************************************/

#include <cxxtest/TestSuite.h>
#include <gmock/gmock.h>
#include <memory>

#include "iMessageCollection.hpp"
#include "Timeline.hpp"
#include "Message.hpp"
#include "SerializedTimeline.hpp"

#include "iTimeline.hpp"
#include "TimelineAdapter.hpp"

struct MessageCollectionMock : public IMessageCollection
{
    void add(std::shared_ptr<Message> && message)
    {
        add_rvr(message);
    }
    MOCK_METHOD1(add_rvr, void (std::shared_ptr<Message> message));
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
    std::shared_ptr<IMessageCollection> messageCollection{mock};
    std::shared_ptr<ITimeline>          iTimeline{new TimelineAdapter<Timeline>{messageCollection}};
    std::shared_ptr<Message>            message{new Message};

    EXPECT_CALL(*mock, add_rvr(message)).Times(1);

    iTimeline->publish(std::move(message));

    TS_ASSERT(testing::Mock::VerifyAndClearExpectations(mock));
}

void testSerializePreparesSerializedTimeline(void)
{
//    MessageCollectionMock               *mock = new MessageCollectionMock;
//    std::shared_ptr<MessageCollection>  messageCollection(mock);
//    Timeline                            timeline(messageCollection);
//    std::shared_ptr<Message>            message(new Message);
//
//    timeline.publish(message);
//
//    EXPECT_CALL(*mock, add(message));
//
//    SerializedTimeline          serialized_timeline("");
//    SerializedTimeline          expected_timeline("");
//
//    timeline.serialize(serialized_timeline);
}

};
