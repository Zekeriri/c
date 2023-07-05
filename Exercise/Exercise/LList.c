#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;


struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    struct ListNode* kPtr = pListHead;
    struct ListNode* cur = pListHead;
    if (k == 0)
    {
        return NULL;
    }
    while (--k)
    {
        if (cur->next == NULL)
        {
            return NULL;
        }
        cur = cur->next;

    }
    while (1)
    {
        if (cur->next == NULL)
        {
            return kPtr;
        }
        kPtr = kPtr->next;
        cur = cur->next;

    }
}
int main()
{
    ListNode* Node1 = (ListNode*)malloc(sizeof(ListNode));
	Node1->val = 1;
	ListNode* Node2 = (ListNode*)malloc(sizeof(ListNode));
	Node2->val = 2;
	ListNode* Node3 = (ListNode*)malloc(sizeof(ListNode));
	Node3->val = 3;
	ListNode* Node4 = (ListNode*)malloc(sizeof(ListNode));
	Node4->val = 4;
	ListNode* Node5 = (ListNode*)malloc(sizeof(ListNode));
	Node5->val = 5;
	
	Node1->next = Node2;
	Node2->next = Node3;
	Node3->next = Node4;
	Node4->next = Node5;
	Node5->next = NULL;

    printf("%d", FindKthToTail(Node1, 6)->val);
    return 0;

}