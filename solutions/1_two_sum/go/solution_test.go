package main

import (
	"testing"
)

func TestTwoSum(t *testing.T) {
	nums := []int{2, 7, 11, 15}
	target := 9
	res := TwoSum(nums, target)
	exp := []int{0, 1}

	if res[0] != exp[0] || res[1] != exp[1] {
		t.Errorf("Results slice was incorrect: got [%d, %d], expected [%d, %d]", res[0], res[1], exp[0], exp[1])
	}
}
