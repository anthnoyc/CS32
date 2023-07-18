//
//  RainfallList.cpp
//  Homework1
//
//  Created by Anthony Chen on 4/15/23.
//

#include "RainfallList.h"


RainfallList::RainfallList(){
    Sequence m_seq;
};

bool RainfallList::add(unsigned long rainfall){
    // If the rainfall is valid (a value from 0 to 400) and the rainfall list
    // has room for it, add it to the rainfall list and return true.
    // Otherwise, leave the rainfall list unchanged and return false.
    if(rainfall >= 0 && rainfall <= 400){
        m_seq.insert(rainfall);
        return true;
    }
    return false;
}

bool RainfallList::remove(unsigned long rainfall){
    // Remove one instance of the specified rainfall from the rainfall list.
    // Return true if a rainfall was removed; otherwise false.
    return m_seq.erase(m_seq.find(rainfall));
}

int RainfallList::size() const{
    return m_seq.size();
}

unsigned long RainfallList::minimum() const{
    // Return the lowest-valued rainfall in the rainfall list.  If the list is
    // empty, return NO_RAINFALLS.
    if(!m_seq.empty()){
    unsigned long min = 400;
    ItemType compare;
        for(int i = 0; i < m_seq.size(); i++){
            m_seq.get(i, compare);
            if(compare < min){
                min = compare;
            }
        }
        return min;
    }
    return NO_RAINFALLS;
}

unsigned long RainfallList::maximum() const{
    // Return the highest-valued rainfall in the rainfall list.  If the list is
    // empty, return NO_RAINFALLS.
    if(!m_seq.empty()){
    unsigned long max = 0;
    ItemType compare = 0;

        for(int i = 0; i < m_seq.size(); i++){
            m_seq.get(i, compare);
            if(compare > max){
                max = compare;
            }
        }
        return max;
    }
    return NO_RAINFALLS;
}
