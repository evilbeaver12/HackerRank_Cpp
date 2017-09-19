#include "LRUCache.h"

using namespace std;

LRUCache::LRUCache(int capacity)
{
    this->cp = capacity;
    head = nullptr;
    tail = nullptr;
}

void LRUCache::set(int key, int value)
{
    if (mp.count(key) == 0)
    {
        Node* newNode = new Node(key, value);
        setHead(newNode);
        mp[key] = newNode;
        if (mp.size() > cp)
        {
            Node* oldTail = tail;
            tail = tail->prev;
            tail->next = nullptr;
            mp.erase(oldTail->key);
            delete oldTail;
        }
    }
    else
    {
        Node* currentNode = mp[key];
        currentNode->value = value;
        moveToHead(currentNode);
    }
    printFromHead();
}

int LRUCache::get(int key)
{
    if (mp.count(key) == 1)
    {
        Node* currentNode = mp[key];
        moveToHead(currentNode);
        printFromHead();
        return currentNode->value;
    }
    return -1;
}

void LRUCache::setHead(Node* node)
{
    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        head->prev = node;
        node->next = head;
        node->prev = nullptr;
        head = node;
    }
}

void LRUCache::moveToHead(Node* node)
{
    if (node->prev != nullptr)
    {
        node->prev->next = node->next;
        if (node->next == nullptr)
        {
            tail = node->prev;
        }
        else
        {
            node->next->prev = node->prev;
        }
        setHead(node);
    }
}

void LRUCache::printFromHead()
{
    Node* node = head;
    cout << "From head: ";
    while (node != nullptr)
    {
        cout << node->key << ":" << node->value << " -> ";
        node = node->next;
    }
    cout << endl;
}

void LRUCache::printFromTail()
{
    Node* node = tail;
    cout << "From tail: ";
    while (node != nullptr)
    {
        cout << node->key << ":" << node->value << " -> ";
        node = node->prev;
    }
    cout << endl;
}

void LRUCache::printMp()
{
    for (auto &item : mp)
    {
        cout << item.first << " : " << item.second->value << endl;
    }
}