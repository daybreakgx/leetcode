# 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

# 示例 1：

# 输入: "babad"
# 输出: "bab"
# 注意: "aba" 也是一个有效答案。
# 示例 2：

# 输入: "cbbd"
# 输出: "bb"

# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/longest-palindromic-substring
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


def isPalindrome(strParam):
    strLen = len(strParam)
    if strLen == 1:
        return True
    i = 0
    j = strLen - 1
    while True:
        if (i >= j):
            break
        if strParam[i] != strParam[j]:
            return False
        i = i + 1
        j = j - 1
    return True


class Solution:
    def longestPalindrome(self, s: str) -> str:
        subStr = ""
        maxLen = 0
        if len(s) == 1:
            return s
        for i in range(0, len(s)):
            for j in range(i, len(s)):
                # print("start: " + str(i) + " end: " + str(j+1) + " " + s[i:j+1] + " len: " + str(j - i + 1))
                if isPalindrome(s[i:j+1]) and maxLen < j - i + 1:
                    maxLen = j - i
                    subStr = s[i:j+1]
                    # print("find one: " + subStr + " len: " + str(maxLen))
        return subStr


if __name__ == "__main__":
    test = "ac"
    print("source string: " + test)
    s = Solution()
    print(s.longestPalindrome(test))
