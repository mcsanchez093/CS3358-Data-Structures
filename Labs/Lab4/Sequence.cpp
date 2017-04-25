

#include <cassert>
#include "sequence.h"

namespace CS3358_FA16_A04_sequenceOfNum
{
    template <class T>
    sequence() : used(0), current_index(0) { }
    
    template <class T>
    void sequence<T>::start() { current_index = 0; }
    
    template <class T>
    void sequence<T>::end()
    { current_index = (used > 0) ? used - 1 : 0; }
    
    template <class T>
    void sequence<T>::advance()
    {
        assert( is_T() );
        ++current_index;
    }
    
    template <class T>
    void sequence<T>::move_back()
    {
        assert( is_T() );
        if (current_index == 0)
            current_index = used;
        else
            --current_index;
    }
    
    template <class T>
    void sequence<T>::add(const T& entry)
    {
        assert( size() < CAPACITY );
        
        size_type i;
        
        if ( ! is_T() )
        {
            if (used > 0)
                for (i = used; i >= 1; --i)
                    data[i] = data[i - 1];
            data[0] = entry;
            current_index = 0;
        }
        else
        {
            ++current_index;
            for (i = used; i > current_index; --i)
                data[i] = data[i - 1];
            data[current_index] = entry;
        }
        ++used;
    }
    
    template <class T>
    void sequence<T>::remove_current()
    {
        assert( is_T() );
        
        size_type i;
        
        for (i = current_index + 1; i < used; ++i)
            data[i - 1] = data[i];
        --used;
    }
    
    template <class T>
    typename sequence<T>::size_type sequence<T>::size() const { return used; }
    
    template <class T>
    bool sequence<T>::is_T() const { return (current_index < used); }
    
    template <class T>
    T sequence<T>::current() const
    {
        assert( is_T() );
        
        return data[current_index];
    }
}

