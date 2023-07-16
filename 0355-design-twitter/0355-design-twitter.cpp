class Twitter {
private:
    unordered_map<int, pair<unordered_set<int>, vector<int>>> twat;
    vector<int> whoPost;
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        twat[userId].second.push_back(tweetId);
        whoPost.push_back(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        unordered_map<int, int> used;
        int i = whoPost.size() - 1;
        while(ans.size() < 10 && i >= 0){
            if(twat[userId].first.find(whoPost[i]) != twat[userId].first.end() || whoPost[i] == userId){
                vector<int> feed = twat[whoPost[i]].second;
                ans.push_back(feed[feed.size() - 1 - used[whoPost[i]]]);
                used[whoPost[i]]++;
            } --i;
        } 
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        twat[followerId].first.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        twat[followerId].first.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */