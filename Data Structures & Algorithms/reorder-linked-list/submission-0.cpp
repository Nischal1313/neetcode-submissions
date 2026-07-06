#include <algorithm>
#include <charconv>
#include <cstddef>
#include <unordered_map>
#include <iostream>
#include <vector>

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;

        std::unordered_map<int, ListNode*> map;
        ListNode* current = head;
        int index = 0;
        
        while (current != nullptr) {
            map[index] = current;
            current = current->next;
            index++;
        }
        int left = 1; 
        int right = map.size() - 1;
        
        // We use a 'curr' pointer to rewire the list, starting at the original head
        ListNode* curr = head; 

        while (left < right) {
            curr->next = map[right];
            curr = curr->next;
            curr->next = map[left];
            curr = curr->next;
            
            left++;
            right--;
        }

        if (left == right) {
            curr->next = map[left];
            curr = curr->next;
        }
        curr->next = nullptr;
    }
};