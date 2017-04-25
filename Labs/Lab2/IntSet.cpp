#include "IntSet.h"
#include <iostream>
#include <cassert>
using namespace std;

void IntSet::resize(int new_capacity)
{
    if (new_capacity < used)
        new_capacity = used;
    if (new_capacity < 1)
        new_capacity = 1;
    capacity = new_capacity;
    int * newData = new int[capacity];
    for (int i = 0; i < used; ++i)
        newData[i] = data[i];
    delete [] data;
    data = newData;
}

IntSet::IntSet(int initial_capacity)
{
    used= 0;
    if (initial_capacity < 1)
        capacity = DEFAULT_CAPACITY;
    data = new int[initial_capacity];
}

IntSet::IntSet(const IntSet& src) 
{
    data = new int[capacity];
    for (int i = 0; i < used; ++i)
        data[i] = src.data[i];
}

IntSet::~IntSet()
{
    delete [] data;
}

IntSet& IntSet::operator=(const IntSet& rhs)
{
    if (this != &rhs)
    {
        int* newData = new int[rhs.capacity];
        for (int i = 0; i < rhs.used; ++i)
            newData[i] = rhs.data[i];
        delete [] data;
        data = newData;
        capacity = rhs.capacity;
        used = rhs.used;
    }
    return *this;
}

int IntSet::size() const
{
    return used;
}

bool IntSet::isEmpty() const
{
    if (used == 0)
        return true;
    else
        return false;
}

bool IntSet::contains(int anInt) const
{
    if (used == 0)
        return false;
    for (int i = 0; i < used; i++)  
    {                              
        if (data[i] == anInt)
            return true;
    }
    return false;
}

bool IntSet::isSubsetOf(const IntSet& otherIntSet) const
{
    int truth = 0;  
    
    if (used == 0)  
        return true;     
    for(int i = 0; i < used; ++i)
    {
        if(otherIntSet.contains(data[i]))  
            truth++;                    
    }                                     
    if(truth == used)  
        return true;          
    else
        return false;
    
}

void IntSet::DumpData(ostream& out) const
{  // already implemented ... DON'T change anything
    if (used > 0)
    {
        out << data[0];
        for (int i = 1; i < used; ++i)
            out << "  " << data[i];
    }
}

IntSet IntSet::unionWith(const IntSet& otherIntSet) const
{
    IntSet both = *this;
    
    for (int i = 0; i < otherIntSet.size(); ++i)
        both.add(otherIntSet.data[i]);
    
    return both;
}

IntSet IntSet::intersect(const IntSet& otherIntSet) const
{
    IntSet only;
    
    int sizeBoth = size() + (otherIntSet.subtract(*this)).size();
    
    for (int i = 0; i < sizeBoth; ++i)
    {
        if (contains(data[i]) && otherIntSet.contains(data[i]))
            only.add(data[i]);
    }
    return only;
    
}

IntSet IntSet::subtract(const IntSet& otherIntSet) const
{
    IntSet diff;
    
    for(int i = 0; i < used; i++)
    {
        if(!otherIntSet.contains(data[i]))
            diff.add(data[i]);
    }
    return diff;
    
}

void IntSet::reset()
{
    delete [] data;
    int* newData = new int[DEFAULT_CAPACITY];
    data = newData;
    capacity = 1;*/
}

bool IntSet::add(int anInt)    
{
    if (!contains(anInt))
    {
        if (capacity <= used)
        {
            resize(capacity * 1.5);
            data[used] = anInt;
            used++;
            return true;
        }
        else
        {
            data[used] = anInt;
            used++;
            return true;
        }
    }
    else
        return false;
}

bool IntSet::remove(int anInt)
{
    if (!contains(anInt))  
        return false;
    else
    {
        for (int i = 0; i < used; ++i)  
        {
            if (data[i] == anInt)  
            {
                for (int j = i; j < used - 1; ++j) 
                    data[j] = data[j + 1]; 
            }
        }
        used--;  
        return true;
    }
}

    
    
bool operator==(const IntSet& is1, const IntSet& is2)
    {
        if (is1.isSubsetOf(is2) && is2.isSubsetOf(is1))
        {
            return true;
        }
        
        return false;
    }
    
    
    
    
    
    
    
    
    
    
    
    
