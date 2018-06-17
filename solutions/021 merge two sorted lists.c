/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
#include <stdlib.h>
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *pt = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head = pt;
    pt->next = NULL;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            pt->next=l1;
            l1 = l1->next;
        } else {
            pt->next=l2;
            l2 = l2->next;
        }
        pt=pt->next;
    }
    if (l1 == NULL && l2 == NULL) {
        return head->next;
    }
    if (l1 == NULL) {
        pt->next = l2;

    } else {
        pt->next = l1;
    }
    return head->next;
}
