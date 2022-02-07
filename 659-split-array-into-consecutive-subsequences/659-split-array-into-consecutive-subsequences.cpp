class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, tail;
        
        for(int n : nums)
        {
            freq[n]++;
        }
        
        for(int i : nums)
        {
            if(freq[i] == 0) continue;
            freq[i]--;
            //there are two options for every num
            //1. start your own subsequence
            //2. join an existing one
            
            if(tail[i-1] > 0)
            {
                tail[i-1]--;
                tail[i]++;
            }
            else if(freq[i+1]>0 && freq[i+2]>0)
            {
               freq[i+1]--;
                freq[i+2]--;
                tail[i+2]++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};