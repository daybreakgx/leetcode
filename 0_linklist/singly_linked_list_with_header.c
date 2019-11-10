#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LOG_ERROR(msgFormat, args...)                \
  (printf("[ERROR][%s:%d]", __FUNCTION__, __LINE__), \
   printf(msgFormat, ##args), printf("\n"))
#define LOG_INFO(msgFormat, args...)                                           \
  (printf("[INFO][%s:%d]", __FUNCTION__, __LINE__), printf(msgFormat, ##args), \
   printf("\n"))

struct ListNode {
  int val;
  struct ListNode* next;
};

int insertListHead(struct ListNode* head, int val) {
  if (NULL == head) {
    LOG_ERROR("list head is null");
    return -1;
  }
  struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
  if (NULL == tmp) {
    LOG_ERROR("malloc singly linked node failed.");
    return -1;
  }
  tmp->val = val;
  tmp->next = head->next;
  head->next = tmp;
  return 0;
}

int insertListTail(struct ListNode* head, int val) {
  if (NULL == head) {
    LOG_ERROR("list head is null");
    return -1;
  }
  struct ListNode* tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
  if (new == NULL) {
    LOG_ERROR("malloc singly link node failed.");
    return -1;
  }
  new->val = val;
  new->next = NULL;
  tmp->next = new;
  return 0;
}

int deleteNode(struct ListNode* head, int val) {
  if (head == NULL) {
    LOG_ERROR("list head is null");
    return -1;
  }
  LOG_INFO("delete node: %d", val);
  struct ListNode* tmp = head;
  while (tmp->next != NULL) {
    if (tmp->next->val == val) {
      struct ListNode* delNode = tmp->next;
      tmp->next = delNode->next;
      free(delNode);
      delNode = NULL;
      return 0;
    }
    tmp = tmp->next;
  }
  LOG_ERROR("not found val(%d) in list", val);
  return -1;
}

void printList(struct ListNode* head) {
  struct ListNode* tmp = head->next;
  if (NULL == head) {
    LOG_ERROR("list head is null");
    return;
  }
  while (tmp != NULL) {
    printf("%d ", tmp->val);
    tmp = tmp->next;
  }
  printf("\n");
}

void freeList(struct ListNode* head) {
  struct ListNode* tmp = head->next;
  while (tmp != NULL) {
    struct ListNode* delNode = tmp;
    tmp = tmp->next;
    LOG_INFO("free %d", delNode->val);
    free(delNode);
    delNode = NULL;
  }
  head->next = NULL;
}

void main() {
  int testList[] = {1, 2, 3, 5};
  struct ListNode head;
  memset(&head, 0, sizeof(struct ListNode));
  for (int i = 0; i < sizeof(testList) / sizeof(testList[0]); i++) {
    insertListHead(&head, testList[i]);
  }
  for (int i = 0; i < sizeof(testList) / sizeof(testList[0]); i++) {
    insertListTail(&head, testList[i]);
  }
  printList(&head);
  for (int i = 0; i < sizeof(testList) / sizeof(testList[0]); i++) {
    deleteNode(&head, testList[i]);
    printList(&head);
  }
  freeList(&head);
  printList(&head);
}
