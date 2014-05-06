//File Name  : LRU_Cache.cpp
//Author     : Avanty
//Date       : 2014/5/6
//Descpriton : Design and implement a data structure for Least Recently Used (LRU) cache.
//            It should support the following operations: get and set.
//            get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//            set(key, value) - Set or insert the value if the key is not already present.
//            When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

/* TLE
struct lruvalue{
    int value;
    int age;
};

class LRUCache{

    public:
	    LRUCache(int capacity) {
		capacity_avanty = capacity;
	    }

	    void set_age(int key){
		map<int, lruvalue>::iterator iter;
		for(iter=lrucache.begin();iter!=lrucache.end();iter++){
		    if(iter->first == key){
			iter->second.age = 1;
		    }
		    else{
			iter->second.age++;
		    }
		}
	    }
	        
	    int get(int key) {
		map<int, lruvalue>::iterator iter;
		iter = lrucache.find(key);
		if(iter != lrucache.end()){
		    set_age(key);
		    return iter->second.value;
		}
		else
		    return -1;
	    }
		    
	    void set(int key, int value) {
		map<int, lruvalue>::iterator iter;
		int old_key,old_age;
		iter = lrucache.find(key);
		if(iter != lrucache.end()){
		    lrucache[key].value = value;
		    set_age(key);
		}
		else if(lrucache.size() < capacity_avanty){
		    lrucache[key].value = value;
		    set_age(key);
		}
		else{
		    iter = lrucache.begin();
		    old_key = iter->first;
		    old_age = iter->second.age;
		    for(iter = lrucache.begin(); iter != lrucache.end(); iter++){
			if(iter->second.age > old_age){
			    old_key = iter->first;
			}
		    }
		    lrucache.erase(old_key);
		    lrucache[key].value = value;
		    set_age(key);
		}

	    }

	    int capacity_avanty;
	    map<int, lruvalue> lrucache;
	  
};
*/
/*
struct lruvalue{
    int value;
    int age;
};

class LRUCache{
    public:
	    LRUCache(int capacity) {
		capacity_avanty = capacity;
		time_avanty = 100000;
	    }

	    void set_age(int key){
		lrucache[key].age = time_avanty;
		time_avanty--;
	    }
	        
	    int get(int key) {
		map<int, lruvalue>::iterator iter;
		iter = lrucache.find(key);
		if(iter != lrucache.end()){
		    set_age(key);
		    return iter->second.value;
		}
		else
		    return -1;
	    }
		    
	    void set(int key, int value) {
		map<int, lruvalue>::iterator iter;
		int old_key,old_age;
		iter = lrucache.find(key);
		if(iter != lrucache.end()){
		    lrucache[key].value = value;
		    set_age(key);
		}
		else if(lrucache.size() < capacity_avanty){
		    lrucache[key].value = value;
		    set_age(key);
		}
		else{
		    iter = lrucache.begin();
		    old_key = iter->first;
		    old_age = iter->second.age;
		    for(iter = lrucache.begin(); iter != lrucache.end(); iter++){
			if(iter->second.age > old_age){
			    old_key = iter->first;
			}
		    }
		    lrucache.erase(old_key);
		    lrucache[key].value = value;
		    set_age(key);
		}

	    }

	    int capacity_avanty;
	    int time_avanty;
	    map<int, lruvalue> lrucache;
	  
};
*/

struct CacheNode{
    int key;
    int val;
    CacheNode(int k, int v) : key(k),val(v){}
};

class LRUCache{
    public:
	    LRUCache(int capacity) {
		cache_capacity = capacity;
	    }
	    int get(int key) {
		if(cachemap.find(key) == cachemap.end()) return -1;
		else{
		    cachelist.splice(cachelist.begin(),cachelist,cachemap[key]);
		    cachemap[key] = cachelist.begin();
		    return cachemap[key]->val;
		}
	    }
	    void set(int key, int value) {
		if(cachemap.find(key) == cachemap.end()){
		    if(cachemap.size() == cache_capacity){
			cachemap.erase(cachelist.back().key);
			cachelist.pop_back();
		    }
		    cachelist.push_front(CacheNode(key,value));
		    cachemap[key] = cachelist.begin();
		}
		else{
		    cachemap[key]->val = value;
		    cachelist.splice(cachelist.begin(),cachelist,cachemap[key]);
		    cachemap[key] = cachelist.begin();
		}
	    }
    private:
	    int cache_capacity;
	    list<CacheNode> cachelist;
	    unordered_map<int, list<CacheNode>::iterator> cachemap;
};

int main(){
    LRUCache lc(2);
    lc.set(1,1);
    lc.set(2,2);
    cout<<lc.get(1)<<endl;
    lc.set(3,3);
    lc.set(3,4);
    cout<<lc.get(2)<<endl;
    cout<<lc.get(3)<<endl;
    lc.set(2,2);
    lc.set(1,1);
    cout<<lc.get(2)<<endl;
    cout<<lc.get(3)<<endl;
    cout<<lc.get(2)<<endl;
    return 0;
}
