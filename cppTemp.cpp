#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists (ListNode* list1,ListNode* list2){

        ListNode* mergedSortedList = new ListNode(0);
        ListNode* tail = mergedSortedList;

        while (list1 && list2){
            if (list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr){
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        ListNode* head = mergedSortedList->next;
        delete mergedSortedList;

        return head;
    }
};

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    printList(merged);  // Output: 1 2 3 4 5 6

    return 0;
}