class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            sum+=nums[i];
        }
        if(sum % 2 == 1) return false;
        int target = sum/2;
        set<int> subsums;
        subsums.insert(0);
        for(auto n : nums)
        {
            set<int> freshSet;
            for(auto s : subsums)
            {
                if(s+n < target){
                    freshSet.insert(s+n);
                }
                else if(s+n == target)
                {
                    return true;
                }
                
                freshSet.insert(s);
            }
            
            subsums = freshSet;
        }
        
        auto t = subsums.find(target);
        if(t != subsums.end()) 
            return true;
        else
            return false;
        
    }
};