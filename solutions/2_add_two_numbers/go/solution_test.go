package main

import (
	"testing"
)

func TestAddTwoNumbers(t *testing.T) {
	l1 := &ListNode{
		val: 2, next: &ListNode{
			val: 4, next: &ListNode{
				val: 3, next: nil}}}
	l2 := &ListNode{
		val: 5, next: &ListNode{
			val: 6, next: &ListNode{
				val: 4, next: nil}}}

	res := AddTwoNumbers(l1, l2)
	if res.val != 7 || res.next.val != 0 || res.next.next.val != 8 {
		t.Errorf("AddTwoNumbers failed on 2->4->3 5->6->4")
	}
}
