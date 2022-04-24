class UndergroundSystem {
private:
    map<string, unordered_map<string, pair<double, int>>> mp;
    // from station -> to station -> moving average & sum.
    map<int, pair<string, int>> checkins;
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
        
        auto endStations = mp[fromStation];
        if(endStations.find(stationName) != endStations.end()) {
            // we already have a moving avg
            auto avg = endStations[stationName];
            double movingAvg = avg.first;
            int count = avg.second;
            double newAverage = ((movingAvg * count) + currentTime) / ((double)(count + 1));
            endStations[stationName] = {newAverage, count+1};
            mp[fromStation] = endStations;
        } else {
            // first time we got this end station.
            mp[fromStation][stationName] = {currentTime, 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return mp[startStation][endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */