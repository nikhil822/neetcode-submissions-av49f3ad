/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func solve(ans *ListNode, ele *ListNode) *ListNode {
    dummy := &ListNode{}
    curr := dummy
    for ans != nil && ele != nil {
        if ans.Val < ele.Val {
            curr.Next = ans
            ans = ans.Next
        } else {
            curr.Next = ele
            ele = ele.Next
        }
        curr = curr.Next
    }
    if ans != nil {
        curr.Next = ans
    } else {
        curr.Next = ele
    }
    return dummy.Next
}
func mergeKLists(lists []*ListNode) *ListNode {
    var ans *ListNode = nil
    for _, val := range lists {
        ans = solve(ans, val)
    }
    return ans

}
