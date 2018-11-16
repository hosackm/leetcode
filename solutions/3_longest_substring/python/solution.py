class Solution:
    def longest_substring(self, s):
        # take care of some simple cases
        if len(s) < 2:
            return len(s)
        elif len(s) == 2:
            return 2 if s[0] != s[1] else 1

        # setup cache and list to track insertion order
        cache = set()
        order = []
        longest = 1  # longest has to be at least 1
        for c in s:
            if c in cache:  # we've reached a repeating character
                # remove all characters leading to and including repeating character
                removes = order[:order.index(c)+1]
                for r in removes:
                    order.remove(r)
                    cache.remove(r)

            # add this unseen character to the cache
            cache.add(c)
            order.append(c)

            # check if we're at our longest and store the length
            if len(cache) > longest:
                    longest = len(cache)

        # check if the cache didn't end with a longer substring
        return longest


if __name__ == "__main__":
    cases = [
        ("abcabcbb", 3),
        ("bbbbb", 1),
        ("pwwkew", 3),
        ("aab", 2)
    ]
    s = Solution()
    for c in cases:
        try:
            ans = s.longest_substring(c[0])
            assert ans == c[1]
        except AssertionError:
            print("Failed: '{}' -> {} (expected {})".format(c[0], ans, c[1]))
