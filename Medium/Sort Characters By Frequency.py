

# Question Link :: "https://leetcode.com/problems/sort-characters-by-frequency/"


# Solution #
class Solution:
    def frequencySort(self, s: str) -> str:
        d = dict()
        ans = ""
        for ch in s:
            d[ch] = (d[ch] + 1) if ch in d else 1
        
        for item in sorted(d.items(), key=lambda kv: (kv[1], kv[0]), reverse=True):
            for ch in item[0]:
                ans += ch*item[1]
    
        return ans
        