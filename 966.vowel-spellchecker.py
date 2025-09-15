#
# @lc app=leetcode id=966 lang=python3
#
# [966] Vowel Spellchecker
#

# @lc code=start
class Solution:
    def spellchecker(self, wordlist: list[str], queries: list[str]) -> list[str]:
        def devowel(s: str) -> str:
            # if char is a vowel, it can be replaced by anything.
            # since vowel replacement has a lower precedence after capitalization, we should
            # make all chars lower case
            return ''.join('*' if ch.lower() in 'aeiou' else ch.lower() for ch in s)

        exact = set(wordlist)
        lower_first: dict[str, str] = {}
        devowel_first: dict[str, str] = {}

        for w in wordlist:
            wl = w.lower()
            dv = devowel(w)
            # Preserve first occurrence only
            if wl not in lower_first:
                lower_first[wl] = w
            if dv not in devowel_first:
                devowel_first[dv] = w

        ans = []
        for q in queries:
            if q in exact:
                ans.append(q)
                continue
            ql = q.lower()
            if ql in lower_first:
                ans.append(lower_first[ql])
                continue
            dq = devowel(q)
            if dq in devowel_first:
                ans.append(devowel_first[dq])
                continue
            ans.append("")
        return ans
        
# @lc code=end

