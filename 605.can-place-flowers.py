#
# @lc app=leetcode id=605 lang=python3
#
# [605] Can Place Flowers
#

# @lc code=start
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        # exactly the same as house robber? or we should do it greedily and place one every 
        # chance we get?
        # edge cases...
        k = n
        if len(flowerbed) < 3:
            if n == 0:
                return True
            if sum(flowerbed) == 0 and n == 1:
                return True
            return False
        for i in range(len(flowerbed)):
            if k == 0:
                return True
            if i == 0:
                if flowerbed[i] == 0 and flowerbed[i + 1] == 0:
                    flowerbed[i] = 1
                    k -= 1
            elif i == len(flowerbed) - 1:
                if flowerbed[i] == 0 and flowerbed[i - 1] == 0:
                    flowerbed[i] = 1
                    k -= 1
            elif flowerbed[i - 1] == 0 and flowerbed[i] == 0 and flowerbed[i + 1] == 0:
                flowerbed[i] = 1
                k -= 1
        return k == 0

        
# @lc code=end

