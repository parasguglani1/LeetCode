class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>, greater<int>>minpq;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxpq.push(num);
        int temp=maxpq.top();
        maxpq.pop();
        minpq.push(temp);
        if(minpq.size()>maxpq.size())
        {
            int temp=minpq.top();
            minpq.pop();
            maxpq.push(temp);
        }

        
    }
    
    double findMedian() {
                if(minpq.size()!=maxpq.size())
        {
         return maxpq.top();   
        }
        return (minpq.top()+maxpq.top())/2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */