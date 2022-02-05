class Solution {
public:
    int maxArea(vector<int>& height) {
        //with the two pointer soln
        //we are trying to raise the min height 
        //because min height is the limiting factor
        
        int l = 0; 
        int r = height.size() - 1;
        int area = 0;
        while(l < r)
        {
            area = max(area, min(height[l], height[r]) * (r-l));
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return area;
    }
};