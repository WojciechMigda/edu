/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: Timeline.cpp
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


#include <memory>
#include "MessageCollection.hpp"
#include "Timeline.hpp"
#include "SerializedTimeline.hpp"

Timeline::Timeline(std::shared_ptr<MessageCollection> messageCollection)
:
    messageCollection(messageCollection)
{
    ;
}

void Timeline::publish(std::shared_ptr<Message> message)
{
    messageCollection->add(message);
}

void Timeline::serialize(SerializedTimeline & placeholder)
{
    ;
}