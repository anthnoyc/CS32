//
//  Sequence.cpp
//  cs32Proj2
//
//  Created by Anthony Chen on 4/20/23.
//

#include "Sequence.h"
#include <iostream>

Sequence::Sequence(){
    m_items = 0;
    Node* dummy = new Node;
    head = dummy;
    head->next = dummy;
    head->prev = dummy;
}

Sequence::~Sequence() {
    Node* m_Node = head->next;
    Node* temp_next;
    while(m_Node != head){
        temp_next = m_Node->next;
        delete m_Node;
        m_Node = temp_next;
    }
    delete head;
}

Sequence::Sequence(const Sequence& other){
    m_items = other.m_items;
    

    Node* dummy = new Node;
    head = dummy;
    if(m_items == 0){
        head->next = dummy;
        head->prev = dummy;
        return;
    }
    Node* other_p = other.head->next;
    Node* curr = head;
    // p is one more than current
    while(other_p != other.head){
        curr->next = new Node;
        curr->next->data = other_p->data;
        curr->next->prev = curr;
        curr->next->next = head;
        other_p = other_p->next;
        curr = curr->next;
    }
}

Sequence& Sequence::operator=(const Sequence &rhs){
    if(this != &rhs){
        // make a copy of the other
        // swap the current with the copy of the other
        Sequence temp(rhs);
        //create this using the copy constructor
        this->swap(temp);
    }
    return *this;
}

void Sequence::dump() const{
    Node* curr = head;
    for(int i = 0; i <= m_items; i++){
        curr = curr->next;
        std::cerr << curr->data << " ";
    }
}


bool Sequence::empty() const{
    return(m_items == 0);
}

int Sequence::size() const{
    return m_items;
}

int Sequence::insert(int pos, const ItemType &value){
//  insert at position, move everything up, return pos if between 0 and size, else do -1. if pos == size, input at end
    if(pos < 0 || pos > m_items){
        return -1;
    }
    Node* curr = head;
    Node* ahead = head;
    if(m_items == 0){
        Node* input = new Node;
        input->prev = head;
        input->data = value;
        input->next = head;
        head->next = input;
        head->prev = input;
        m_items++;
        return 0;
    }
    int p = 0;
    for(int i = 0; i < pos; i++){
        curr = curr->next;
        ahead = ahead->next;
        p = i + 1;
        }
    if(p == pos){
        Node* input = new Node;
        ahead = ahead->next;
        input->prev = curr;
        input->next = ahead;
        input->data = value;
        curr->next = input;
        ahead->prev = input;
        m_items++;
    }
    return pos;
}

int Sequence:: insert(const ItemType &value){
    Node* curr = head;
    bool is_inputted = false;
    int pos = -1;
    for(int i = 0; i <= m_items; i++) {
        curr = curr->next;
        if(curr->data >= value){
            pos = insert(i, value);
            is_inputted = true;
            break;
        }
    }
    if(!is_inputted){
        pos = insert(m_items, value);
    }
    return pos;
}

bool Sequence::erase(int pos){
    Node* ahead = head->next;
    Node* deleting = head;
    Node* previous = head;
    for(int i = 0; i <= pos; i++){
        ahead = ahead->next;
        deleting = deleting->next;
        if(deleting == head){
            break;
        }
        if(i == pos){
            previous->next = ahead;
            ahead->prev = previous;
            delete deleting;
            m_items--;
            return true;
        }
        previous = previous->next;
    }
    return false;
}

int Sequence::remove(const ItemType &value){
    Node* check = head->next;
    int counter = 0;
//    int j = 0;
//    for(int i = 0; i < m_items; i++){
//        check = check->next;
//        if(check == head){
//            break;
//        }
//        if(check->data == value){
//            erase(i);
//            counter ++;
//        }
//    }
    
    while(check != head){
        Node* deleting = check;
        if(deleting->data == value){
            deleting->prev->next = deleting->next;
            deleting->next->prev = deleting->prev;
            check = check->next;
            delete deleting;
            m_items--;
            counter++;
        } else {
            check = check->next;
        }
    }
    return counter;
}

bool Sequence::get(int pos, ItemType &value) const{
    if(pos < 0 || pos > m_items){
        return false;
    }
    Node* copy = head;
    for(int i = 0; i <= pos; i++){
        copy = copy->next;
        // check to make sure that didnt reach the end of the LL
        if(copy == head){
            break;
        }
        if(i == pos){
            value = copy->data;
            return true;
        }
    }
    return false;
}

bool Sequence::set(int pos, const ItemType &value){
    if(pos < 0 || pos > m_items || m_items == 0){
        return false;
    }
    Node* curr = head;
    for(int i = 0; i <= pos; i++){
        curr = curr->next;
        if(i == pos){
            curr->data = value;
            return true;
        }
    }
    return false;
}

int Sequence::find(const ItemType &value) const{
    int p = -1;
    Node* curr = head;
    for(int i = 0; i <= m_items; i++){
        curr = curr->next;
        if(curr->data == value){
            p = i;
            break;
        }
    }
    return p;
}

void Sequence::swap(Sequence &other){
    // swap what the pointers point to and the size.
    Node* temp_head;
    temp_head = head;
    head = other.head;
    other.head = temp_head;
    
    int temp_items;
    temp_items = m_items;
    m_items = other.m_items;
    other.m_items = temp_items;
}

void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result){
    Sequence temp_seq;
    ItemType value;
    if(seq1.size() == 0 || seq2.size() == 0){
        result = temp_seq;
        return;
    }
    // meaning that seq 1 is empty so return the reverse of seq2
    // to reverse, add the values to temp sequence using previous pointers
    if(seq1.size() == 0){
        int n = seq2.size() - 1;
        for(int i = 0; i < seq2.size(); i++){
            // less than because the size is one more than the actual indexing
            //get the value of the item at the position at the end
            seq2.get(n, value);
            //insert the item into the temp sequence
            temp_seq.insert(i, value);
            n--;
        }
    } else if (seq2.size() == 0){
        //seq 2 is empty
        int m = seq1.size() - 1;
        for(int i = 0; i < seq1.size(); i++){
            seq1.get(m, value);
            temp_seq.insert(i, value);
            m--;
        }
    } else {
        int n = seq2.size() - 1;
        int seq2_end = 0;
        for(int i = 0; i< seq2.size(); i++){
            seq2.get(n, value);
            temp_seq.insert(i, value);
            n--;
            seq2_end = i;
        }
        int m = seq1.size() - 1;
        for(int i = 0; i < seq1.size(); i++){
            seq1.get(m, value);
            temp_seq.insert(seq2_end + i + 1, value);
            m--;
        }
    }
    result = temp_seq;
}

int subsequence(const Sequence& seq1, const Sequence& seq2){
    // find the first value that has the first value of seqeunce
    // then get the value after that in seq1, if they do not match, then break.
    // continue looping until you reach the end of sequence 2 using seq2.size()
    ItemType value1;
    ItemType value2;
    if(seq2.size() == 0 || seq2.size() > seq1.size()){
        return -1;
    }
    for(int i = 0; i < seq1.size(); i++){
        // get first value of seq2
        seq2.get(0, value2);
        // find the starting location of some subsequence
        seq1.get(i, value1);
        // for the values in sequence 2, loop through and check if they are the same
        if(value1 == value2){
            if(seq2.size() == 1){
                // we only need the subsequence of a single value
                return i;
            }
            for(int j = 1; j < seq2.size(); j++){
                seq1.get(i + j, value1);
                seq2.get(j, value2);
                if(value1 != value2){
                    // go to the next instance of value2 in seq1
                    break;
                }
                if(j == seq2.size() - 1){
                    // once you reach the end of sequence 2 return if the conditions still hold true
                    return i;
                }
            }
        }
    }
    return -1;
}
