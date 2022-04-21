class MyHashSet {
private:
    vector<bool> v;
public:
    MyHashSet() {
        const int limit = (int)pow(10, 6) + 2;
        for(int i=0;i<limit;++i) v.push_back(false);
    }
    
    void add(int key) {
        v[key] = 1;
    }
    
    void remove(int key) {
        v[key] = 0;
    }
    
    bool contains(int key) {
        return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */