#include <unordered_map>
#include <string>
using namespace std;

class UndergroundSystem {
private:
    unordered_map<int,pair<string,int>> checkedIn;
    unordered_map<string,pair<int,int>> mp;

public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        // already checked in at other station/time
        if(checkedIn.find(id) != checkedIn.end())
            return;
        
        // not checked in
        checkedIn[id] = { stationName, t };        
    }
    
    void checkOut(int id, string stationName, int t) {
        // already checked out at other station/time
        if(checkedIn.find(id) == checkedIn.end())
            return;
        
        // check out
        pair<string,int> checkIn = checkedIn[id];
        checkedIn.erase(id);

        string key = checkIn.first + '_' + stationName;
        if(mp.find(key)!=mp.end()) {
            mp[key].second += 1;
            mp[key].first += t - checkIn.second;
        }
        else mp[key] = { t - checkIn.second, 1 };
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + '_' + endStation;
        if(mp.find(key)==mp.end())
            return 0.0;
        
        pair<int,int> data = mp[key];
        return (double)data.first / (double)data.second;
    }
};
