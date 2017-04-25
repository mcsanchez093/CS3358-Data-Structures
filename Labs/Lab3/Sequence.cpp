#include <cassert>
#include "Sequence.h"
#include <iostream>
using namespace std;

namespace CS3358_Fa2016
{
    sequence::sequence(size_type initial_capacity)
    {
        data= new value_type [initial_capacity];
        current_index=0;
        capacity=initial_capacity;
        used=0;
    }
    
    sequence::sequence(const sequence& source)
    {
        data=new value_type[source.capacity];
        capacity=source.capacity;
        current_index=source.current_index;
        used=source.used;
        copy(source.data,source.data+used,data);
    }
    
    sequence::~sequence()
    {
        delete [] data;
    }
    
    // MODIFICATION MEMBER FUNCTIONS
    void sequence::resize(size_type new_capacity)
    {
        if (new_capacity < used)
            new_capacity = used;
        
        if (new_capacity <= 0)
            new_capacity = 1;
        
        capacity = new_capacity;
        value_type* newData = new value_type[capacity];
        
        for (size_type i = 0; i < used; i++)
            newData[i] = data[i];
        delete [] data;
        
        data = newData;
    }
    
    void sequence::start()
    {
        current_index = 0;
    }
    
    void sequence::advance()
    {
        current_index++;
    }
    
    void sequence::insert(const value_type& entry)
    {
        if (used == 0)
        {
            data[current_index] = entry;
            used++;
        }
        else if (used >= 1)
        {
            if (used == capacity)
                resize(capacity + 1);
            
            for (size_type i = used; i > current_index; i--)
            {
                data[i] = data[i-1];
            }
            data[current_index] = entry;
            used++;
        }
    }
    
    void sequence::attach(const value_type& entry)
    {
        if (used == 0)
        {
            data[0] = entry;
            used++;
        }
        else if (used >= 1)
        {
            if (used == capacity)
                resize(capacity + 1);
            
            current_index = used + 1;
            data[current_index] = entry;
            used++;
        }
    }
    
    void sequence::remove_current()
    {
        assert(is_item());
        
        for  ( size_type i=0; i<used;i++)
            
            data[i]=data[i+1];
    	   used--;
        data[current_index]=current_index;
        
    }
    
    sequence& sequence::operator=(const sequence& source)
    {
        if (this != &source)
        {
            value_type* newData = new value_type[source.capacity];
            for (size_type i = 0; i < source.used; ++i)
                newData[i] = source.data[i];
            delete [] data;
            data = newData;
            capacity = source.capacity;
            used = source.used;
            current_index = source.current_index;
        }
        return *this;
    }
    
    
    // CONSTANT MEMBER FUNCTIONS
    sequence::size_type sequence::size() const
    {
        return used;
    }
    
    bool sequence::is_item() const
    {
        if (current_index < used && used > 0)
            return true;
        else
            return false;
    }
    
    
    sequence::value_type sequence::current() const
    {
        return data[current_index];
    }
}
