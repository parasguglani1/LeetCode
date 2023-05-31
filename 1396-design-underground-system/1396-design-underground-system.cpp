class UndergroundSystem {
public:
        map<double,pair<string,double>> p;
    map<pair<string, string>, pair<double, double>> sums;

    UndergroundSystem() {
        p.clear();
        sums.clear();
        
        //initalize hashmaps
        
    }
    
    void checkIn(int id, string stationName, int t) {
        p[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        sums[{p[id].first,stationName}]={sums[{p[id].first,stationName}].first+t-p[id].second,sums[{p[id].first,stationName}].second+1};
        
    }
    
    double getAverageTime(string startStation, string endStation) {
 return sums[{startStation,endStation}].first/sums[{startStation,endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */