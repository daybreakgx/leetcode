#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#define MAX(x, y) ((x) > (y)) ? (x) : (y)
int expandArroudCenter(char* s, int start, int end) {
  while (start >= 0 && end < strlen(s) && s[start] == s[end]) {
    start--;
    end++;
  }
  return end - start - 1;
}

char* longestPalindrome(char* s) {
  if (s == NULL || strlen(s) < 1) {
    return "";
  }
  int len = strlen(s);
  int start = 0, end = 0;
  for (int i = 0; i < len; i++) {
    int len1 = expandArroudCenter(s, i, i);
    int len2 = expandArroudCenter(s, i, i + 1);
    int len3 = MAX(len1, len2);
    if (len3 > end - start) {
      if (len1 > len2) {
        start = i - (len1 - 1) / 2;
        end = i + (len1 - 1) / 2;
      } else {
        start = i - (len2 - 2) / 2;
        end = i + 1 + (len2 - 2) / 2;
      }
    }
  }
  int maxLen = end - start + 1;
  // printf("start:%d, end:%d, maxLen:%d\n", start, end, maxLen);
  char* ret = malloc((maxLen + 1) * sizeof(char));
  memset(ret, 0, sizeof(char) * (maxLen + 1));
  strncpy(ret, s + start, maxLen);
  // printf("s:%s, ret:%s\n", s, ret);
  return ret;
}

void main() {
  char test[] = "babad";
  printf("source string:%s, strlen(test):%d\n", test, strlen(test));
  char* ret = longestPalindrome(test);
  printf("%s\n", ret);
  free(ret);
}