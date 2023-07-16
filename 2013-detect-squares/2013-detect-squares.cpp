class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> mapp;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mapp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int result = 0;
        
        for (auto x = mapp.begin(); x != mapp.end(); x++) {
            for (auto y = x->second.begin(); y != x->second.end(); y++) {
                if (abs(x->first - point[0]) != 0 &&
                    abs(x->first - point[0]) == abs(y->first - point[1])) {
                        result += mapp[x->first][y->first] * 
                        mapp[point[0]][y->first] * 
                        mapp[x->first][point[1]];
                }   
            }
        } return result;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */