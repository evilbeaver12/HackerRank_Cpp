#pragma once
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

// Provided as helper on HackerRank
struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

// Provided as helper on HackerRank
class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
public:
    LRUCache(int capacity);

    void set(int key, int value);
    int get(int key);

private:
    void setHead(Node* node);
    void moveToHead(Node* node);

    void printFromHead();
    void printFromTail();
    void printMp();
};