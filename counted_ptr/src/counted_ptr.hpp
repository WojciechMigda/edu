/*******************************************************************************
 * 2013 Wojciech Migda
 * Distributed under the terms of the Public Domain license
 *******************************************************************************
 *
 * Filename: counted_ptr.hpp
 *
 * Description:
 *      Counted pointer template class, based on the concept outlined in the
 *      Jon Jagger's paper in Overload issue 25.
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2013-06-30   wm              Initial version
 *
 ******************************************************************************/


#ifndef COUNTED_PTR_HPP_
#define COUNTED_PTR_HPP_

#define NULL_PTR (0)

template<class _Tp, void _Deleter(void *)=operator delete>
class counted_ptr
{
public:
    typedef     _Tp         element_type;
    typedef     _Tp *       pointer;
    typedef     _Tp const * const_pointer;
    typedef     _Tp &       reference;
    typedef     _Tp const & const_reference;
    typedef     void (*deleter_pointer)(void *);

public:
    counted_ptr() :
        m_ptr(NULL_PTR)
    {}
    counted_ptr(pointer p) :
        m_ptr(p)
    {}

    long use_count() const
    {
        return m_count;
    }

    static deleter_pointer get_deleter(const counted_ptr<_Tp, _Deleter> & sp)
    {
        return _Deleter;
    }

private:
    pointer             m_ptr;
    long                m_count;

};

#endif /* COUNTED_PTR_HPP_ */
