//
//  Sequence.hpp
//  cs32Proj2
//
//  Created by Anthony Chen on 4/20/23.
//

#ifndef Sequence_hpp
#define Sequence_hpp
#include <string>
#include <stdio.h>

using ItemType = std::string;

class Sequence{
private:
    struct Node{
        ItemType data;
        struct Node* prev;
        struct Node* next;
    };
    int m_items;
    Node* head;
    
public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence& other);
    Sequence& operator= (const Sequence& rhs);
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    void dump() const;
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_hpp */
