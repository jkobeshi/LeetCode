class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(26);
        
        int maxCount = 0;
        int maxCountFrequency = 0;
        
        for (int i = 0; i < tasks.size(); i++) {
            int currCount = ++counter[tasks[i] - 'A'];
            if (maxCount == currCount) maxCountFrequency++;
            else if (maxCount < currCount) {
                maxCount = currCount;
                maxCountFrequency = 1;
            }
        }
        int emptySlots = (maxCount - 1) * (n - (maxCountFrequency - 1));
        int availableTasks = tasks.size() - maxCount * maxCountFrequency;
        int idles = max(0, emptySlots - availableTasks);
        
        return tasks.size() + idles;
    }
};