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

int insertListHead(struct ListNode** head, int val) {
  LOG_INFO("insert head: %d", val);
  struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
  if (NULL == tmp) {
    LOG_ERROR("malloc singly linked node failed.");
    return -1;
  }
  tmp->val = val;
  tmp->next = *head;
  *head = tmp;
  return 0;
}

int insertListTail(struct ListNode** head, int val) {
  LOG_INFO("insert tail: %d", val);
  struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
  if (new == NULL) {
    LOG_ERROR("malloc singly link node failed.");
    return -1;
  }
  new->val = val;
  new->next = NULL;
  if (*head == NULL) {
    *head = new;
    LOG_INFO("new header.");
  } else {
    struct ListNode* tmp = *head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = new;
  }
  return 0;
}

struct ListNode* deleteNode(struct ListNode* head, int val) {
  if (head == NULL) {
    LOG_ERROR("list head is null");
    return NULL;
  }
  LOG_INFO("delete node: %d", val);
  struct ListNode* tmp = head;
  if (head->val == val) {
    head = head->next;
    free(tmp);
    tmp = NULL;
    return head;
  }
  while (tmp->next != NULL) {
    if (tmp->next->val == val) {
      struct ListNode* delNode = tmp->next;
      tmp->next = delNode->next;
      free(delNode);
      delNode = NULL;
      return head;
    }
    tmp = tmp->next;
  }
  LOG_ERROR("not found val(%d) in list", val);
  return head;
}

void printList(struct ListNode* head) {
  struct ListNode* tmp = head;
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
  while (head != NULL) {
    struct ListNode* delNode = head;
    head = head->next;
    LOG_INFO("free %d", delNode->val);
    free(delNode);
    delNode = NULL;
  }
}
void main() {
  int testList[] = {1, 2, 3, 5};
  struct ListNode* head = NULL;
  printf("hello");

  for (int i = 0; i < sizeof(testList) / sizeof(testList[0]); i++) {
    insertListTail(&head, testList[i]);
  }
  printList(head);
  for (int i = 0; i < sizeof(testList) / sizeof(testList[0]); i++) {
    insertListHead(&head, testList[i]);
  }
  printList(head);

  for (int i = 0; i < sizeof(testList) / sizeof(testList[0]); i++) {
    head = deleteNode(head, testList[i]);
    printList(head);
  }
  freeList(head);
}
