class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }
        priority_queue<int> maxHeap;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0)
                maxHeap.push(freq[i]);
        }

        int time = 0;
        queue<pair<int, int>> q;
        while(!maxHeap.empty() || !q.empty()) {
            time++;
            if(maxHeap.empty()) {
                time = q.front().second;
            }
            else {
                int fr = maxHeap.top()-1;
                maxHeap.pop();
                if(fr > 0) 
                    q.push({fr, time+n});
            }
            if(!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
