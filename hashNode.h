// ------------------------------- hashNode.h -------------------------------
//
// Mahsa Mohajeri, CSS 343
// Created:         05/31/22
// Last Modified:   06/8/22
// ------------------------------------------------------------------------
// Purpose: This class will implement the hashNode class
// ------------------------------------------------------------------------
// Assumptions: Uses template
// ------------------------------------------------------------------------
#ifndef HASHNODE_H
#define HASHNODE_H

const int TABLE_SIZE = 200;

template<typename key, typename val>
class HashNode {
public:
    HashNode(key k, val v)
    {
        K = k;
        V = v;
        next = nullptr;
    }
    ~HashNode();
    key getKey() const
    {
        return K;
    }
    val getVal() const
    {
        return V;
    }
    HashNode* getNext() const
    {
        return next;
    }
    void setNext(HashNode* next)
    {
      HashNode::next = next;
    }
    void setVal(val v)
    {
      V = v; 
    }


private:

    key K;
    val V;
    HashNode* next;
};
template <typename key>
struct keyHash
{
  int operator()(const key& k) const
  {
    return reinterpret_cast<int>(k) % TABLE_SIZE;
  }

};
#endif