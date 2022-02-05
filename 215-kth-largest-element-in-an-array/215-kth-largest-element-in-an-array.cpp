class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //implementing a min heap so that we can only keep k elements in the heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int n : nums)
        {
            pq.push(n);
            if(pq.size() > k)  //O(log k) time 
            {
                pq.pop();  //remove the min element in the pq at that time
            }
        }
        return pq.top();
    }
};