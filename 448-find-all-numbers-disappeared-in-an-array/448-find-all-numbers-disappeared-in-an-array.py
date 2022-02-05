class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        temp = set()
        for item in nums:
            temp.add(item)
        res = []
        for item in range(1, len(nums)+1):
            if(item not in temp):
                res.append(item)
        
        return res
        