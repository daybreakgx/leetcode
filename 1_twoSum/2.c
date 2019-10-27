#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hashTable {
  struct hashData **head;
  int hashSize;
};

struct hashData {
  int key;
  int value;
  struct hashData *next;
};

int initHashTable(struct hashTable *table, unsigned int tableSize) {
  if (tableSize <= 0) {
    return -1;
  }
  table->head = malloc(sizeof(struct hashData *) * tableSize);
  memset(table->head, 0, sizeof(struct hashData *) * tableSize);
  if (table->head == NULL) {
    free(table);
    return -1;
  }
  table->hashSize = tableSize;
  return 0;
}

void freeHashTable(struct hashTable *table) {
  if (table != NULL) {
    for (int i = 0; i < table->hashSize; i++) {
      struct hashData *head = table->head[i];
      while (head != NULL) {
        struct hashData *tmp = head;
        head = head->next;
        free(tmp);
      }
    }
    free(table->head);
    table->head = NULL;
  }
}

int hashFunction(int key, int tableSize) { return abs(key) % tableSize; }

int insertData(struct hashTable *table, int key, int value) {
  int hashValue = hashFunction(key, table->hashSize);
  struct hashData *tmp = malloc(sizeof(struct hashData));
  if (tmp == NULL) {
    return -1;
  }
  tmp->key = key;
  tmp->value = value;
  tmp->next = table->head[hashValue];
  table->head[hashValue] = tmp;
  return 0;
}

int findData(struct hashTable *table, int key) {
  int hashValue = hashFunction(key, table->hashSize);
  struct hashData *tmp = table->head[hashValue];
  while (tmp != NULL) {
    if (tmp->key == key) {
      return tmp->value;
    }
    tmp = tmp->next;
  }
  return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int *ret = (int *)malloc(sizeof(int) * 2);
  if (ret == NULL) {
    return NULL;
  }
  struct hashTable table;
  initHashTable(&table, numsSize);
  for (int i = 0; i < numsSize; i++) {
    int tmp = findData(&table, target - nums[i]);
    if (tmp != -1) {
      ret[0] = tmp;
      ret[1] = i;
      *returnSize = 2;
      freeHashTable(&table);
      return ret;
    }
    insertData(&table, nums[i], i);
  }
  freeHashTable(&table);
  return NULL;
}

void main() {
  int nums[] = {0, 8, 9, 10, 100, 0};
  int target = 0;
  int *ret = NULL;
  int retSize = 0;

  ret = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &retSize);
  printf("ret size: %d\n", retSize);
  for (int i = 0; i < retSize; i++) {
    printf("%d\n", ret[i]);
  }
}