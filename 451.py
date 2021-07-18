from collections import Counter

class Solution:
    def frequencySort(self, s):
        if len(s) <= 2:
            return s
        wordList = list(s)
        counter = Counter(s)
        counter = counter.most_common()
        result = ""
        for i in counter:
            for num in range(i[1]):
                result += i[0]
        return result


solution = Solution()
print((solution.frequencySort('tree')))