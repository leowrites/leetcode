#
# @lc app=leetcode id=43 lang=python3
#
# [43] Multiply Strings
#

# @lc code=start
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        num1Len = len(num1)
        num2Len = len(num2)
        interResults = [[0] * (num2Len + 1) for _ in range(num1Len + 1)]
        for i in range(num1Len, 0, -1):
            for j in range(num2Len, 0, -1):
                # we should start from the back
                prod = (int(num1[i - 1]) * int(num2[j - 1])) + interResults[i][j]
                interResults[i][j] = prod % 10
                interResults[i][j - 1] += prod // 10

        res = [0] * (num1Len + num2Len + 1)
        for i in range(num1Len, -1, -1):
            for j in range(num2Len, -1, -1):
                q = (res[i + j] + interResults[i][j]) // 10
                r = (res[i + j] + interResults[i][j]) % 10
                res[i + j] = r
                res[i + j - 1] += q
        start = 1 if res[1] != 0 else 2
        res = [str(s) for s in res]
        return "".join(res[start:])
                
            

        
# @lc code=end

