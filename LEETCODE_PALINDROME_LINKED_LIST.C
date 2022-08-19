#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow, *fast, *prev = NULL, *tmp;
    slow = fast = head;
    // Middle of the linked list in slow
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // reverse second half
    while (slow) {
        tmp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = tmp;
    }

    // Check if palindrome
    fast = head;
    slow = prev;
    while (slow) {
        if (fast->val != slow->val) return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}

void printList(struct ListNode* head) {
    if (head == NULL) return;

    while (head) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("N\n");
}

int main() {

    struct ListNode *l1 = (struct ListNode *)calloc(4, sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)calloc(5, sizeof(struct ListNode));

    struct ListNode *p = l1;

    p->val = 1;
    p->next = l1 + 1;
    p = p->next;

    p->val = 2;
    p->next = l1 + 2;
    p = p->next;

    p->val = 2;
    p->next = l1 + 3;
    p = p->next;

    p->val = 1;
    p->next = NULL;

    p = l2;
    p->val = 1;
    p->next = l2 + 1;
    p = p->next;

    p->val = 2;
    p->next = l2 + 2;
    p = p->next;

    p->val = 3;
    p->next = l2 + 3;
    p = p->next;

    p->val = 2;
    p->next = l2 + 4;
    p = p->next;

    p->val = 1;
    p->next = NULL;

    printList(l1);
    printf("%d\n", isPalindrome(l1));

    printList(l2);
    printf("%d\n", isPalindrome(l2));

    return 0;
}
/*
OUTPUT->
1->2->2->1->N
1
1->2->3->2->1->N
1
*/
