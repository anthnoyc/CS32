// Dictionary.cpp

// This is a correct but horribly inefficient implementation of Dictionary
// functionality.  Your job is to change DictionaryImpl to a more efficient
// correct implementation.  You can change it any way you like, subject to
// restrictions in the spec (e.g., that the only C++ library container you
// are allowed to use are vector, list, stack, and queue (and string); if you
// want anything fancier, implement it yourself).
#include "Dictionary.h"
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <cmath>
#include <functional> // for hash
#include <algorithm> // for sort
#include <utility>  // for swap

using namespace std;

void removeNonLetters(string& s);
void generateNextPermutation(string& permutation);
int findPrime(int maxBuckets);

  // This class does the real work of the implementation.

class DictionaryImpl
{
public:
  DictionaryImpl(int maxBuckets) {
      // resize the hash vector to the largest prime number under max buckets.
      m_hash.resize(findPrime(maxBuckets));
  }
  ~DictionaryImpl() {}
  void insert(string word);
  void lookup(string letters, void callback(string)) const;

private:
  struct Node {
      Node(string word, string sorted)
      :m_word(word), m_sorted(sorted){
      }
      string m_word;
      string m_sorted;
  };
    vector<list<Node>> m_hash;
    hash<string> str_hash;
};

// find the largest prime number under the number of max buckets for the optimal number of buckets



void DictionaryImpl::insert(string word)
{
    removeNonLetters(word);
    // make a copy of the word to sort
    string temp = word;
    sort(temp.begin(), temp.end());
    // the has key based on the sorted
    if(!word.empty()){
        size_t value = str_hash(temp);
        size_t index = value % m_hash.size();
        Node insert_node(word, temp);

        m_hash.at(index).push_back(insert_node);
    }
}

void DictionaryImpl::lookup(string letters, void callback(string)) const
{
    if(callback == nullptr){
        return;
    }
    removeNonLetters(letters);
    if(letters.empty()){
        return;
    }
    sort(letters.begin(), letters.end());
    size_t index = str_hash(letters) % m_hash.size();
    list words_list = m_hash.at(index);
    // need to check that the letters are the same
    // can i use auto?
    for(auto itr = words_list.begin(); itr != words_list.end(); itr++){
        if((*itr).m_sorted == letters){
            callback((*itr).m_word);
        }
    }
    return;
}

void removeNonLetters(string& s)
{
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++)
    {
        if (isalpha(*from))
        {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());  // chop everything off from "to" to end.
}


int findPrime(int maxBuckets){
    int factors = 0;
    if(maxBuckets <= 0){
        return 0;
    }
    for (int i = maxBuckets; i >= 2; i--) {
        for (int j = 2 ; j < sqrt(i) + 1; j++) {
            if (i % j == 0){
                factors++;
                break;
            }
        }
        if (factors == 0) {
            return i;
            break;
        }
        factors = 0;
    }
    return 0;
}


//******************** Dictionary functions ******************************

// These functions simply delegate to DictionaryImpl's functions
// You probably don't want to change any of this code

Dictionary::Dictionary(int maxBuckets)
{
    m_impl = new DictionaryImpl(maxBuckets);
}

Dictionary::~Dictionary()
{
    delete m_impl;
}

void Dictionary::insert(string word)
{
    m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
    m_impl->lookup(letters,callback);
}
