/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: Timeline.hpp
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

#include "Message.hpp"
#include "iMessageCollection.hpp"
#include "SerializedTimeline.hpp"

#include <memory>

class Timeline
{
private:
    std::shared_ptr<IMessageCollection> messageCollection;

protected:

    explicit Timeline(std::shared_ptr<IMessageCollection> messageCollection);

    void publish(std::shared_ptr<Message> && message);

    void serialize(SerializedTimeline & placeholder);

};
