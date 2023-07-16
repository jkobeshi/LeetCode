class TimeMap {
public:
    unordered_map<string, map<int, string>> tMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(tMap.find(key) == tMap.end()){
            return "";
        }
        auto it = tMap[key].find(timestamp);
        if(it == tMap[key].end()){
            tMap[key][timestamp] = "";
            it = tMap[key].find(timestamp);
            if(it == tMap[key].begin()){
                tMap[key].erase(timestamp);
                return "";
            }
            --it;
            tMap[key].erase(timestamp);
        }
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */