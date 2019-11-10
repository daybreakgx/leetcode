#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
  int val;
  struct ListNode* next;
};

/* link list without header node*/
int insertListTail(struct ListNode** head, int val) {
  struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
  if (new == NULL) {
    return -1;
  }
  new->val = val;
  new->next = NULL;
  if (*head == NULL) {
    *head = new;
  } else {
    struct ListNode* tmp = *head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = new;
  }
  return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode* ret = NULL;
  struct ListNode* tmp_l1 = l1;
  struct ListNode* tmp_l2 = l2;
  int tmpNum = 0;
  while (tmp_l1 || tmp_l2) {
    if (tmp_l1) {
      tmpNum += tmp_l1->val;
      tmp_l1 = tmp_l1->next;
    }
    if (tmp_l2) {
      tmpNum += tmp_l2->val;
      tmp_l2 = tmp_l2->next;
    }
    insertListTail(&ret, tmpNum % 10);
    tmpNum = tmpNum / 10;
  }
  if (tmpNum != 0) {
    insertListTail(&ret, tmpNum);
  }
  return ret;
}

void printList(struct ListNode* head) {
  struct ListNode* tmp = head;
  if (NULL == head) {
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
    free(delNode);
    delNode = NULL;
  }
}

void main() {
  int int_l1[] = {2, 4, 3};
  int int_l2[] = {5, 6, 4};
  struct ListNode* l1 = NULL;
  struct ListNode* l2 = NULL;
  for (int i = 0; i < sizeof(int_l1) / sizeof(int_l1[0]); i++) {
    insertListTail(&l1, int_l1[i]);
  }
  printList(l1);
  for (int i = 0; i < sizeof(int_l2) / sizeof(int_l2[0]); i++) {
    insertListTail(&l2, int_l2[i]);
  }
  printList(l2);
  struct ListNode* ret = addTwoNumbers(l1, l2);
  printList(ret);
  freeList(ret);
}
