class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkStatus;
    unordered_map<string, pair<int, int>> routeAvg;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkStatus[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> p = checkStatus[id];
        checkStatus.erase(id);
        routeAvg[p.first+" "+stationName].first += t - p.second;
        routeAvg[p.first+" "+stationName].second ++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto p = routeAvg[startStation+ " " + endStation];
        return (double) p.first / p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */