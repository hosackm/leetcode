package main

// Interface to consume runes
type RuneConsumer interface {
	Insert(r rune)
}

// Type that consumes runes and tracks longest substring
type SubstringTracker struct {
	order   []rune
	cache   map[rune]bool
	longest int
}

// Create new SubstringTracker
func NewSubstringTracker() SubstringTracker {
	o := make([]rune, 0)
	c := make(map[rune]bool)
	return SubstringTracker{o, c, 0}
}

// Insert a rune and track longest substring
func (st *SubstringTracker) Insert(r rune) {
	if _, exists := st.cache[r]; exists {
		i := 0
		for _, v := range st.order {
			if v == r {
				break
			}
			i++
		}

		remove := st.order[:i+1]
		st.order = st.order[i+1:]
		for _, rmv := range remove {
			delete(st.cache, rmv)
		}
	}
	st.cache[r] = true
	st.order = append(st.order, r)

	if len(st.order) > st.longest {
		st.longest = len(st.order)
	}
}

// Use SubstringTracker to consume runes and track longest substring
func LengthOfLongestSubstring(s string) int {
	st := NewSubstringTracker()
	for _, r := range s {
		st.Insert(r)
	}
	return st.longest
}

func main() {}
