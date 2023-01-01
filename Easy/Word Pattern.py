

# Question Link :: "https://leetcode.com/problems/word-pattern/description/"


# Solution #
class Solution:
    def wordPattern(self, pat: str, s: str) -> bool:
        words = s.split(" ")
        if len(pat) != len(words):
            return False
        d1, d2 = dict(), dict()
        for i in range(len(pat)):
            if pat[i] in d1:
                if d1[pat[i]] != words[i] or d2[words[i]] != pat[i]:
                    return False
            else:
                if words[i] in d2:
                    return False
                d1[pat[i]], d2[words[i]] = words[i], pat[i]
        return True