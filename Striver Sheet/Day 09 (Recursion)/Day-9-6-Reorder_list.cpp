// Recursion
class Solution {
 public:
  void reorderList(ListNode* head) {
    ListNode* ptr = head;
    ListNode* tail = head;
    bool reordered = false;
    reorderList(head, tail, ptr, reordered);
  }

  void reorderList(ListNode*& head, ListNode* tail, ListNode*& ptr, bool& reordered) {
    if (tail == nullptr) {
      return;
    }
    reorderList(head, tail->next, ptr, reordered);
    if (reordered) {
      return;
    }
    if (head == tail || head->next == tail) {
      if (tail->next != nullptr) {
        tail->next = nullptr;
      }
      reordered = true;
      return;
    }
    head = head->next;
    tail->next = head;
    ptr->next = tail;
    ptr = head;
  }
};
