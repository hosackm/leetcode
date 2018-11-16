package main

type ListNode struct {
	val  int
	next *ListNode
}

func AddTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var res *ListNode
	if l1 != nil || l2 != nil {
		s := 0
		if l1 != nil {
			s += l1.val
		}
		if l2 != nil {
			s += l2.val
		}

		if s >= 10 {
			s -= 10
			if l1.next != nil {
				l1.next.val++
			} else {
				l1.next = &ListNode{1, nil}
			}
		}
		res = &ListNode{s, nil}
		res.next = AddTwoNumbers(l1.next, l2.next)
	}
	return res
}

func main() {

}
