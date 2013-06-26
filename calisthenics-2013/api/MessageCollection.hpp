/*******************************************************************************
 * Copyright (c) 2013, Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: MessageCollection.hpp
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
 * 2013-06-26   wm              Initial version
 *
 ******************************************************************************/

#ifndef MESSAGECOLLECTION_HPP_
#define MESSAGECOLLECTION_HPP_

#include "Message.hpp"
#include <memory>

class MessageCollection
{
private:

public:
    virtual void add(std::shared_ptr<Message> message){};

    virtual ~MessageCollection(){}
};


#endif /* MESSAGECOLLECTION_HPP_ */
