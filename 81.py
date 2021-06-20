import numpy as np


class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = l + (r - l) / 2
            if nums[mid] == target:
                return True
            
            # check with range is in
            if nums[mid] == nums[l]:
                l += 1
            elif nums[mid] <= nums[r]:
                if nums[mid] < target and nums[r] >= target:
                    l = mid + 1
                else:
                    r = mid - 1
            else:
                if nums[mid] > target and nums[l] <= target:
                    r = mid - 1
                else:
                    l = mid + 1
        return False
        
