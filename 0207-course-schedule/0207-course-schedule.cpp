class Solution {
public:
    bool hasCyc(unordered_set<int>& vis, unordered_map<int, vector<int>>& Courses, int course){
        if (vis.find(course) != vis.end()){
            return false;
        }
        if(Courses[course].empty()){
            return true;
        }
        vis.insert(course);
        for(int i = 0; i < Courses[course].size(); ++i){
            if (!hasCyc(vis, Courses, Courses[course][i])){
                return false;
            }
        }
        Courses[course].clear();
        vis.erase(course);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> Courses;
        for(int i = 0; i < prerequisites.size(); ++i){
            Courses[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> vis;
        for(int i = 0; i < numCourses; ++i){
            if(!hasCyc(vis, Courses, i)){
                return false;
            }
        }
        return true;
    }
};