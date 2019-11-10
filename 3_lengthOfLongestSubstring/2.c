#include <stdio.h>
#include <string.h>

#define MAX(x, y) ((x) > (y)) ? (x) : (y)

int lengthOfLongestSubstring(char* s) {
  int hashTable[256] = {0};
  char* index = s;
  int maxLen = 0;
  // 滑动窗口start和end初始值均为0
  int end = 0, start = 0;
  while (*index != '\0') {
    // 如果当前字符在窗口中，则将start指向当前字符的下一位
    start = MAX(start, hashTable[*index]);
    // 设置(或更新)该字符的窗口坐标为当前位置的下一位
    hashTable[*index] = end + 1;
    // printf("start: %d, end:%d\n", start, end);
    maxLen = MAX(maxLen, end - start + 1);
    index++;
    end++;
  }
  return maxLen;
}

void main() {
  char tmpStr[] = "abcdgbfhab";
  int ret = lengthOfLongestSubstring(tmpStr);
  printf("ret: %d", ret);
}