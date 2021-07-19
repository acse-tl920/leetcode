class Solution:
    def maxAreaOfIsland(self, grid):
        seen = set()
        def area(rowNum, colNum, grid):
            if not(rowNum >=0 and rowNum < len(grid) and colNum >= 0 and colNum < len(grid[0]) and grid[rowNum][colNum] and (rowNum, colNum) not in seen):
                return 0
            seen.add((rowNum, colNum))
            return (1 + area(rowNum+1, colNum, grid) + area(rowNum, colNum+1, grid) + area (rowNum-1, colNum, grid) + area(rowNum, colNum-1, grid))
        maxArea = 0
        for rowNum in range(len(grid)):
            for colNum in range(len(grid[0])):
                maxArea = max(maxArea, area(rowNum, colNum, grid))
        return maxArea
        
solution = Solution()
print(solution.maxAreaOfIsland([[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]))
