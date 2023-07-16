class MedianFinder {
public:

    priority_queue<int, vector<int>, greater<int>> right;
    priority_queue<int> left;

    MedianFinder() {
        
    }
    void addNum(int num) {
        if(left.empty()) left.push(num);
        else if(right.empty()) right.push(num);
        else if(left.size() > right.size()) right.push(num);
        else left.push(num);
        
        if(!left.empty() && !right.empty()){
            if(left.top() > right.top()){
                if(left.size() > right.size()){
                    right.push(left.top());
                    left.pop();
                }
                else if(right.size() > left.size()){
                    left.push(right.top());
                    right.pop();
                }
                else{
                    int temp = left.top();
                    left.pop();
                    left.push(right.top());
                    right.pop();
                    right.push(temp);
                }
            }
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            cout << left.top() << " " << right.top();
            return (double(left.top()) + double(right.top())) / 2;
        }
        if(left.size() > right.size()){
            return double(left.top());
        }
        return double(right.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */