class UndergroundSystem {
private:
    unordered_map<string, pair<double, int>> mp;
    // (from station -> to station) -> moving average & sum.
    unordered_map<int, pair<string, int>> checkins;
    // id -> from station & start time.
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkins[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto resp = checkins[id];
        string fromStation = resp.first;
        int startTime = resp.second;
        int currentTime = t - startTime;
        string route = fromStation + "->" + stationName;
        if(mp.find(route) != mp.end()) {
            // we already have a moving avg
            auto& avg = mp[route];
            double& movingAvg = avg.first;
            int& count = avg.second;
            movingAvg = ((movingAvg * count) + currentTime) / ((double)(++count));
            // mp[route] = {newAverage, count+1};
        } else {
            // first time we got this end station.
            mp[route] = {currentTime, 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "->" + endStation; 
        return mp[route].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */