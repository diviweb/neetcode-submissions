class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> freq(1001, 0);
        for(int i = 0; i < stones.size(); i++)
            freq[stones[i]]++;
        
        int biggest = 1000;

        while(true) {
            while(biggest > 0 && freq[biggest] == 0)
                biggest--;

            if(biggest == 0)
                return 0;
            
            freq[biggest]--;
            int second = biggest;

            while(second > 0 && freq[second] == 0)
                second--;

            if(second == 0)
                return biggest;

            freq[second]--;
            freq[biggest - second]++;
        }
    }
};
