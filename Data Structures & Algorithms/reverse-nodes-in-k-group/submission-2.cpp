/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <list>

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *temp_hold_k = nullptr;

    ListNode *prev_group_tail = nullptr;
    ListNode *new_head = nullptr;

    while (curr != nullptr) {
      ListNode *checker = curr;
      int remaining_count = 0;
      while (checker != nullptr && remaining_count < k) {
        remaining_count++;
        checker = checker->next;
      }

      if (remaining_count < k) {
        if (prev_group_tail != nullptr) {
          prev_group_tail->next = curr;
        }
        return new_head != nullptr ? new_head : head;
      }

      ListNode *group_start = curr;

      for (int i = 0; i < k; i++) {

        temp_hold_k = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp_hold_k;
      }

      if (new_head == nullptr) {
        new_head = prev;
      }
      if (prev_group_tail != nullptr) {
        prev_group_tail->next = prev;
      }
      prev_group_tail = group_start;
      prev = nullptr;
    }

    return new_head ? new_head : head;
  }
};
