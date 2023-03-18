class BrowserHistory {
public:
    stack<string> fow,bck;
    
    BrowserHistory(string homepage) {
        
        bck.push(homepage);
    }
    
    void visit(string url) {
        while(!fow.empty())
        {
            fow.pop();
        }
        bck.push(url);
    }
    
    string back(int steps) {
        while(bck.size()>1 && steps>0)
        {
            steps--;
            string st=bck.top();
            bck.pop();
            fow.push(st);
            
        }
        return bck.top();
        
    }
    
    string forward(int steps) {
      while(!fow.empty() && steps>0)
        {
            steps--;
            string st=fow.top();
            fow.pop();
            bck.push(st);
            
        }   
        return bck.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */