#
# @lc app=leetcode id=1733 lang=python3
#
# [1733] Minimum Number of People to Teach
#

# @lc code=start
class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        toTeach = set()
        for u, v in friendships:
            u -= 1
            v -= 1
            if not any(lang in languages[v] for lang in languages[u]):
                toTeach.add(u)
                toTeach.add(v)
        minTeaching = len(languages) + 1
        for lang in range(1, n + 1):
            count = 0
            for u in toTeach:
                if lang not in languages[u]:
                    count += 1
            minTeaching = min(minTeaching, count)
        return minTeaching

                
        
# @lc code=end

