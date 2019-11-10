#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hashData {
  int key;
  int value;
  struct hashData* next;
};

struct hashTable {
  struct hashData** data;
  int size;
};

int initHashTable(struct hashTable* table, int size) {
  if (size <= 0) {
    return -1;
  }
  table->data = malloc(size * sizeof(struct hashData*));
  if (table->data == NULL) {
    printf("init hash table failed.\n");
    return -1;
  }
  memset(table->data, 0, sizeof(struct hashData*) * size);
  table->size = size;
  return 0;
}

void freeHashTable(struct hashTable* table) {
  for (int i = 0; i < table->size; i++) {
    struct hashData* head = table->data[i];
    while (head != NULL) {
      struct hashData* tmp = head;
      head = head->next;
      free(tmp);
      tmp = NULL;
    }
  }
  free(table->data);
  table->data = NULL;
  return;
}
int hashFunction(int key, int size) { return abs(key) % size; }

int insertData(struct hashTable* table, int key, int value) {
  int hashValue = hashFunction(key, table->size);
  struct hashData* new = (struct hashData*)malloc(sizeof(struct hashData));
  if (new == NULL) {
    printf("malloc new hash data failed.\n");
    return -1;
  }
  new->key = key;
  new->value = value;
  new->next = table->data[hashValue];
  table->data[hashValue] = new;
  return 0;
}

int find(struct hashTable* table, int key) {
  int hashValue = hashFunction(key, table->size);
  struct hashData* tmp = table->data[hashValue];
  while (tmp != NULL) {
    if (tmp->key == key) {
      return tmp->value;
    }
    tmp = tmp->next;
  }
  return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int* ret = (int*)malloc(sizeof(int*) * 2);
  *returnSize = 0;
  struct hashTable table;
  memset(&table, 0, sizeof(struct hashTable));
  initHashTable(&table, numsSize);
  for (int i = 0; i < numsSize; i++) {
    int index = find(&table, target - nums[i]);
    if (index != -1) {
      *returnSize = 2;
      ret[0] = index;
      ret[1] = i;
      freeHashTable(&table);
      return ret;
    }
    insertData(&table, nums[i], i);
  }
  free(ret);
  freeHashTable(&table);
  return NULL;
}

void main() {
  int nums[] = {-1, -2, -3, -4, -5};
  int target = -8;
  int* ret = NULL;
  int retSize = 0;

  ret = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &retSize);
  printf("ret size: %d\n", retSize);
  for (int i = 0; i < retSize; i++) {
    printf("%d\n", ret[i]);
  }
}