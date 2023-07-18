//
//  Sequence.cpp
//  Homework1
//
//  Created by Anthony Chen on 4/15/23.
//

#include "Sequence.h"

Sequence::Sequence(){
    m_size = 0;
};

bool Sequence::empty() const{
    if (m_size == 0){
        return true;
    }
    return false;

}

int Sequence::size() const{
    return m_size;
}

int Sequence::insert(int pos, const ItemType& value){
    if(m_size < DEFAULT_MAX_ITEMS - 1 && pos >= 0 && pos <= size()){
        for(int i = size() - 1; i >= pos; i--){
            m_arr[i+1] = m_arr[i];
        }
        m_arr[pos] = value;
        m_size ++;
        return pos;
    }
    return -1;
}

int Sequence::insert(const ItemType& value){
    int j = 0;
    if(size() < DEFAULT_MAX_ITEMS){
        if(size() == 0){
            insert(0, value);
            return 0;
        }
        for(int i = 0; i <= size() - 1; i++){
            if(m_arr[i] >= value){
                insert(i, value);
                return i;
            }
            j = i;
        }
        insert(j + 1, value);
        return j + 1;
    }
    return -1;
}

bool Sequence::erase(int pos){
    if(size() < DEFAULT_MAX_ITEMS - 1 && pos >= 0 && pos < size()){
        for(int i = pos; i <= size() - 1; i++){
            m_arr[i] = m_arr[i+1];
        }
        m_size--;
        return true;
    }
    return false;
    
}

int Sequence::remove(const ItemType& value){
    int items_removed = 0;
    for(int i = 0; i < size(); i++){
        if(m_arr[i] == value){
            erase(i);
            items_removed++;
            i--;
        }
    }
    return items_removed;
}

bool Sequence::get(int pos, ItemType& value) const{
    if(size() < DEFAULT_MAX_ITEMS - 1 && pos >= 0 && pos < size()){
        value = m_arr[pos];
        return true;
    }
    return false;
}

bool Sequence::set(int pos, const ItemType& value){
    if(size() < DEFAULT_MAX_ITEMS - 1 && pos >= 0 && pos < size()){
        m_arr[pos] = value;
        return true;
    }
    return false;
    
};

int Sequence::find(const ItemType& value) const{
    for(int i = 0; i <= size() -1; i++){
        if(m_arr[i] == value){
            return i;
        }
    }
    return -1;
}

void Sequence::swap(Sequence& other){
    // original size is larger
    int start_size = 0;
    ItemType temp;
    if(size() > other.size()){
        start_size = size();
    } else {
        start_size = other.size();
    }
    for(int i = 0; i <= start_size; i++){
        temp = m_arr[i];
        m_arr[i] = other.m_arr[i];
        other.m_arr[i] = temp;
    }
    int temp_size;
    temp_size = m_size;
    m_size = other.m_size;
    other.m_size = temp_size;
    
    
    
}



