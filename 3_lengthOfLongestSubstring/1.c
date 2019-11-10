#include <stdio.h>
#include <string.h>

#define MAX(x, y) ((x) > (y)) ? (x) : (y)

int lengthOfLongestSubstring(char* s) {
  int hashTable[256];
  memset(hashTable, -1, sizeof(hashTable));
  char* index = s;
  int maxLen = 0;
  // 滑动窗口start和end初始值均为0
  int end = 0, start = 0;
  while (*index != '\0') {
    // 如果当前字符在窗口中，则将start指向当前字符的下一位
    if (hashTable[*index] != -1) {
      start = MAX(start, hashTable[*index] + 1);
    }
    // 设置(或更新)该字符的窗口坐标为当前index
    hashTable[*index] = end;
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