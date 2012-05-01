
#ifndef _ITR_UTILS_HPP_
#define _ITR_UTILS_HPP_

namespace ItrUtils {
    template <class ForwardIterator>
    void sequence_delete(ForwardIterator first, ForwardIterator last)
    {
        while (first != last)
            delete *first++;
    }

    template <class ForwardIterator>
    void map_delete(ForwardIterator first, ForwardIterator last)
    {
        while (first != last)
            delete (*first++).second;
    }
}

#endif
