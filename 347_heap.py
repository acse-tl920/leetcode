import numpy as np
import random
import heapq
from collections import Counter

from collections import Counter
class Solution:
    def topKFrequent(self, nums, k):
        # O(1) time 
        if k == len(nums):
            return nums
        
        # 1. build hash map : character and how often it appears
        # O(N) time
        count = Counter(nums)
        print(count.get)
        # 2-3. build heap of top k frequent elements and
        # convert it into an output array
        # O(N log k) time
        return heapq.nlargest(k, count.keys(), key=count.get) 

s = Solution()
s.topKFrequent([1,1,2,2,3], 2)