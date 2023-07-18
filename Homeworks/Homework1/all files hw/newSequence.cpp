//
//  Sequence.cpp
//  Homework1
//
//  Created by Anthony Chen on 4/15/23.
//

#include "newSequence.h"

//Sequence::Sequence(){
//    m_size = 0;
//    //m_all = m_size;
//    m_arr = new ItemType[m_all];
//};

Sequence::Sequence(int size){
    if(size < 0){
        std::cout << "bad total" << std::endl;
    }
    m_size = 0;
    m_all = size;
    m_arr = new ItemType[size];
};

Sequence::~Sequence(){
    delete[] m_arr;
}

Sequence::Sequence(const Sequence& other){
    m_size = other.m_size;
    m_all = other.m_all;
    m_arr = new ItemType[m_all];
    for (int i = 0; i < m_all; i++){
        m_arr[i] = other.m_arr[i];
    }

}

Sequence& Sequence::operator=(const Sequence& other){
    if (this != &other)
    {
        delete [] m_arr;
            
        m_all = other.m_all;
        m_size = other.m_size;
        
        m_arr = new ItemType[other.m_all];
        for(int i = 0; i < other.m_size; i++)
        {
            m_arr[i] = other.m_arr[i];
        }
        return *this;
    } else {
        return *this;
    }
}

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
    //std::cout << m_size << " " << m_all << std::endl;
    if(m_size <= m_all && pos <= m_size && pos >= 0){
        for(int i = m_size - 1; i >= pos; i--){
            m_arr[i+1] = m_arr[i];
        }
        m_arr[pos] = value;
        m_size++;
        return pos;
    }
    return -1;
}

// MY M_ALL SIZE IS NOT INCREASING WITH THE ARRAYS
int Sequence::insert(const ItemType& value){
    int j = 0;
    if(m_size > m_all){
        //std::cout << m_size << " " << m_all << std::endl;
        return -1;
    } else if(m_size == 0){
        insert(0, value);
        return 0;
    } else {
        for(int i = 0; i <= m_size; i++){
            if(value <= m_arr[i]){
                insert(i, value);
                return i;
            }
            j = i;
        }
        insert(j, value);
        return j;
    }
    
    
    
//    {
//        for(int i = 0; i <= size() - 1; i++){
//            if(value <= m_arr[i]){
//                for(int j = size() - 1; j >= i; j--){
//                    m_arr[j+1] = m_arr[j];
//                }
//                m_arr[i] = value;
//                m_size ++;
//                return i;
////                insert(i, value);
////                std::cout << i;
////                return i;
//            }
//        }
//        insert(size(), value);
//        return size();
//    }
}

bool Sequence::erase(int pos){
    if(size() < m_all - 1 && pos >= 0 && pos < size()){
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
    if(size() < m_all - 1 && pos >= 0 && pos < size()){
        value = m_arr[pos];
        return true;
    }
    return false;
}

bool Sequence::set(int pos, const ItemType& value){
    if(size() < m_all - 1 && pos >= 0 && pos < size()){
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
    ItemType* temp;
    temp = m_arr;
    m_arr = other.m_arr;
    other.m_arr = temp;
    
    int temp_size;
    temp_size = m_size;
    m_size = other.m_size;
    other.m_size = temp_size;
    
    int temp_all;
    temp_all = m_all;
    m_all = other.m_all;
    other.m_all = temp_all;
}



