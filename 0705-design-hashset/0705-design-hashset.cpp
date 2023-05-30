class MyHashSet {
public:
    int v[1000001]={0};
    MyHashSet() {
        
        
    }
    
    void add(int key) {
        v[key]=1;
    }
    
    void remove(int key) {
        v[key]=0;
    }
    
    bool contains(int key) {
        return v[key];
    }
};
