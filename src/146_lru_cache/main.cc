/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/04
* @brief  
*
**/

#include <iostream>
#include <map>
#include <list>

using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int,int>> cache;
    map<int, list<pair<int,int>>::iterator> m;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it==m.end()) {
            return -1;
        }

        pair<int,int> kv = *m[key];
        cache.erase(m[key]);
        cache.push_front(kv);
        m[key] = cache.begin();
        return kv.second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it==m.end()) {
            if (cache.size() == cap) {
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                m.erase(lastKey);
                cache.pop_back();
            }
            cache.push_front(make_pair(key,value));
            m[key] = cache.begin();
        } else {
            cache.erase(m[key]);
            cache.push_front(make_pair(key,value));
            m[key] = cache.begin();
        }
    }
};

int main() {
    LRUCache* cache = new LRUCache(2);
    cache->put(2,1);
    cache->put(1,2);
    cache->put(2,3);
    cache->put(4,1);
    cout << cache->get(1) << endl;
    cout << cache->get(2) << endl;
    

    return 0;
}

