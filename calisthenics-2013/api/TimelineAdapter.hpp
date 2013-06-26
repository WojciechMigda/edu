/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: TimelineAdapter.hpp
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


#ifndef TIMELINEADAPTER_HPP_
#define TIMELINEADAPTER_HPP_

#include <memory>

#include "iTimeline.hpp"
#include "SerializedTimeline.hpp"
#include "Message.hpp"

template <class T>
class TimelineAdapter : public ITimeline, public T
{
public:
    explicit TimelineAdapter(std::shared_ptr<MessageCollection> messageCollection)
    :
        T(messageCollection)
    {

    }
    virtual ~TimelineAdapter(){}

private:
    virtual void publish(std::shared_ptr<Message> && message)
    {
        T::publish(std::move(message));
    }

    virtual void serialize(SerializedTimeline & placeholder)
    {
        T::serialize(placeholder);
    }
};


#endif /* TIMELINEADAPTER_HPP_ */
