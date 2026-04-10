/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    // 2 pointers fast and slow, move the fast pointer to n steps ahead
	temp := &ListNode{Val: 0, Next: head}
	fast := temp
	slow := temp
	for n >= 0 {
		fast = fast.Next
		n--
	}
	for fast != nil {
		fast = fast.Next
		slow = slow.Next
	}
	slow.Next = slow.Next.Next
	return temp.Next
}
