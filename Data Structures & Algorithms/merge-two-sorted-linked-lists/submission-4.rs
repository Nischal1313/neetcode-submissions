// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//     pub val: i32,
//     pub next: Option<Box<ListNode>>,
// }
//
// impl ListNode {
//     #[inline]
//     pub fn new(val: i32) -> Self {
//         ListNode { next: None, val }
//     }
// }
impl Solution {
    pub fn merge_two_lists(
        mut list1: Option<Box<ListNode>>,
        mut list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut dummy = ListNode::new(0);
        let mut current = &mut dummy;

        while let (Some(l1), Some(l2)) = (list1.as_ref(), list2.as_ref()) {
            if l1.val <= l2.val {
                current.next = list1.take();
                current = current.next.as_mut().unwrap();
                list1 = current.next.take();
            } else {
                current.next = list2.take();
                current = current.next.as_mut().unwrap();
                list2 = current.next.take();
            }
        }

        if list1.is_some() {
            current.next = list1;
        } else {
            current.next = list2;
        }

        dummy.next
    }
}