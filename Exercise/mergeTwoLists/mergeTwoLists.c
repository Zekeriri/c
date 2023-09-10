#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* cur1 = list1;
    struct ListNode* cur2 = list2;
    struct ListNode* list3 = NULL;
    struct ListNode* cur3 = list3;
    while (cur1 && cur2)
    {
        if (cur1->val > cur2->val)
        {
            if (cur3 == NULL)
            {
                cur3 = cur2;
                list3 = cur3;
                cur2 = cur2->next;
                continue;
            }
            else
            {
                cur3->next = cur2;
            }
            cur2 = cur2->next;
        }
        else
        {
            if (cur3 == NULL)
            {
                cur3 = cur1;
                list3 = cur3;
                cur1 = cur1->next;
                continue;
            }
            else
            {
                cur3->next = cur1;
            }
            cur1 = cur1->next;
        }
        cur3 = cur3->next;
    }
    while (cur1)
    {
        cur3->next = cur1;
        cur3 = cur3->next;
        cur1 = cur1->next;
    }
    while (cur2)
    {
        cur3->next = cur2;
        cur3 = cur3->next;
        cur2 = cur2->next;
    }
    return list3;
}

int main()
{
    // 创建两个有序链表
    struct ListNode* list1 = malloc(sizeof(struct ListNode));
    struct ListNode* list2 = malloc(sizeof(struct ListNode));

    list1->val = 1;
    list1->next = malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;

    list2->val = 1;
    list2->next = malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    // 合并两个链表
    struct ListNode* mergedList = mergeTwoLists(list1, list2);
    // 打印合并后的链表
    struct ListNode* current = mergedList;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }


    return 0;
}