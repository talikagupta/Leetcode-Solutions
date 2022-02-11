class LRUCache {
    //the front of the list is the most recently used
    //the back is the lru
    int cap;
    list<pair<int, int>> l;
    unordered_map< int , list<pair<int, int>>::iterator > map;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end())
        {
            return -1;
        }
        else
        {
            //if we find the key in the map then
            //1. we return the value
            //2. we move that node to the beginning of the list l
            
            l.splice(l.begin(), l, map[key]);
            //map[key] is an iterator to a list of pairs
            return map[key]->second;
        }
    }
    
    void put(int key, int value) {
        //if key-value pair already exists then 
        //1. update the value of the node 
        //2. move the node to the beginning(which get fn already handles)
        
        if(get(key) != -1)
        {
            map[key]->second = value;
            return;
        }
        
        //if key-val pair doesnt exist then
        //1. if capacity isnt full, add the new node to the beginning of list
        //2. if cap is full, remove the node at the end of list l
        //  and add a new node at the beginning of list 
        
        if(l.size() == cap)
        {
            int delKey = l.back().first;
            l.pop_back();
            map.erase(delKey);
        }
        
        l.emplace_front(key, value);
        map[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */