class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        cache = {}
        for i, n in enumerate(nums):
            needed = target - n
            if needed in cache:
                return [cache[needed], i]
            else:
                cache[n] = i
        return []


if __name__ == "__main__":
    s = Solution()
    print(s.twoSum([2, 7, 11, 15], 9))
