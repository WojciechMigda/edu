/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: iMessageCollection.hpp
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

/*
 *  Interface class Checklist:
 *  ==========================
 *  [ ] Methods are abstract: virtual method() = 0;
 *  [ ] No ctor is defined
 *  [ ] Destructor is not abstract: virtual ~dtor();
 *  [ ] Copy operator is private and undefined: T& operator=(const T &);
 */

#ifndef IMESSAGECOLLECTION_HPP_
#define IMESSAGECOLLECTION_HPP_

#include "Message.hpp"
#include <memory>

class IMessageCollection
{
private:
    IMessageCollection & operator=(const IMessageCollection &);
public:
    virtual void add(std::shared_ptr<Message> && message) = 0;
    virtual ~IMessageCollection(){};
};

#endif /* IMESSAGECOLLECTION_HPP_ */
