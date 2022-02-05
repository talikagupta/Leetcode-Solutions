class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        res = []
        for item in nums:
            item = abs(item)
            if(nums[item-1] > 0):
                nums[item-1] *= -1
        for i in range(len(nums)):
            if(nums[i] > 0):
                res.append(i+1)
        
        return res
        