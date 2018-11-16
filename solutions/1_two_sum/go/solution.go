package main

import "fmt"

func TwoSum(nums []int, target int) []int {
	numToAddendIndex := make(map[int]int)
	result := make([]int, 2)

	for i, v := range nums {
		needed := target - v
		if index, ok := numToAddendIndex[needed]; ok {
			result[0], result[1] = index, i
			break
		} else {
			numToAddendIndex[v] = i
		}
	}

	return result
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9
	res := TwoSum(nums, target)
	fmt.Printf("%d, %d\n", res[0], res[1])
}
