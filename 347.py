import numpy as np
import random

class Solution:
    def topKFrequent(self, nums, k):
        dic = {}
        result = []
        
        # build dictionary for the frequence of each element
        for i in nums:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
        
        arr = np.fromiter(dic.values(), dtype=int)

        if len(arr) == 1 and k == 1:
            result.append(nums[0])
            return result
        # do quick select
        l = 0
        r = len(arr) - 1

        pivotInde = len(arr) - k
        while l<r:
            mid = self.quickSelect(arr, l, r)

            # if satisfied
            if mid == pivotInde:
                l = mid
                break

            # if mid is smaller, should look for mid + 1 and r
            elif mid < pivotInde:
                l = mid + 1

            # look for l to mid-1
            elif mid > pivotInde:
                r = mid -1
        
        for ele in dic:
            if dic[ele] >= arr[l]:
                result.append(ele)
        
        return result
    
    def quickSelect(self, arr, l, r):
        p = random.randint(l+1, r)
        arr[r], arr[p] = arr[p], arr[r]

        # pivot is arr[l]
        j = r
        i = l + 1

        # do quick select
        while 1:

            # look for smaller than pivot element
            while j > l and arr[j] >= arr[l]:
                j -= 1
            
            # look for greater than pivot
            while i < r and arr[i] <= arr[l]:
                i += 1

            # if i is greater or equal to j
            if i >= j:
                break

            # swap ith element and jth element
            arr[i], arr[j] = arr[j], arr[i]

        # when the loop break, jth is the last element that smaller than pivot, swap
        arr[j], arr[l] = arr[l], arr[j]

        # return the index where pivot is currently at
        return j

s = Solution()
result = s.topKFrequent([1,1,1,2,2,3], 2)    
print(result)