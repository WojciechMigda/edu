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

#include "MessageCollection.hpp"
#include "Timeline.hpp"
#include "Message.hpp"
#include "SerializedTimeline.hpp"

#include "iTimeline.hpp"
#include "TimelineAdapter.hpp"

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
    TimelineAdapter<Timeline>           timeline(messageCollection);
    iTimeline                           *i_timeline_p = &timeline;
    std::shared_ptr<Message>            message(new Message);

    EXPECT_CALL(*mock, add(message)).Times(1);

    i_timeline_p->publish(message);

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
