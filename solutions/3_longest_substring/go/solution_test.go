package main

import "testing"

func TestLengthOfLongestSubstring(t *testing.T) {
	type Case struct {
		String string
		Length int
	}
	cases := []Case{
		{"abcabcbb", 3},
		{"bbbbb", 1},
		{"pwwkew", 3},
		{"aab", 2},
		{"ab", 2},
		{"a", 1},
	}

	for _, c := range cases {
		if l := LengthOfLongestSubstring(c.String); l != c.Length {
			t.Errorf("Failed: %s -> %d, expected %d", c.String, l, c.Length)
		}
	}
}
