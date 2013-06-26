/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: iTimeline.hpp
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


#ifndef ITIMELINE_HPP_
#define ITIMELINE_HPP_

#include <memory>

#include "Message.hpp"
#include "SerializedTimeline.hpp"

class iTimeline
{
private:
    iTimeline & operator=(const iTimeline &);
public:
    virtual void publish(std::shared_ptr<Message> message) = 0;
    virtual void serialize(SerializedTimeline & placeholder) = 0;

    virtual ~iTimeline(){}

};

#endif /* ITIMELINE_HPP_ */
