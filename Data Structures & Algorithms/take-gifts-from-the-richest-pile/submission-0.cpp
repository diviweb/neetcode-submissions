class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < gifts.size(); i++) {
            pq.push(gifts[i]);
        }

        for(int i = 0; i < k; i++) {
            int maxEle = pq.top();
            pq.pop();
            pq.push(sqrt(maxEle));
        }
        long long num = 0;
        while(!pq.empty()) {
            num += pq.top();
            pq.pop();
        }
        return num;
    }
};