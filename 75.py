class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) <= 1:
            return nums
        
        zeroIndex = 0
        twoIndex = len(nums) - 1
        for i in range(len(nums)):
            # place 2 on the right
            while nums[i] == 2 and i < twoIndex:
                nums[twoIndex], nums[i] = nums[i], nums[twoIndex]
                twoIndex -= 1
            while nums[i] == 0 and i > zeroIndex:
                nums[zeroIndex], nums[i] = nums[i], nums[zeroIndex]
                zeroIndex += 1
                
                
                