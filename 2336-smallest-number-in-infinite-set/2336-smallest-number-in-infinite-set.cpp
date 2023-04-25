class SmallestInfiniteSet {
public:
    priority_queue<int> pq;
           vector<int> exists;
    
    SmallestInfiniteSet() {
              exists.resize(100001);
        for(int i=1;i<100000;i++)
        {
            pq.push(-i);
            exists[i]=1;
        
        }
        
    }
    
    int popSmallest() {
        int t=pq.top();
        pq.pop();
        exists[-t]=0;
        return -t;
        
    }
    
    void addBack(int num) {
     if(!exists[num])   
      {      exists[num]=1;// cout<<'h';
        pq.push(-num);}
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */