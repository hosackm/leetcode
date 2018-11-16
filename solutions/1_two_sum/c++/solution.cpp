#include <vector>
#include <map>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;  // store answer
        std::map<int, int> numToIndex;  // hash map for tracking the needed addend

        int i = 0;  // track the current index
        for(auto num : nums)
        {
            // figure out the addend needed for this number and check if it exists
            int needed = target - num;
            auto neededIter = numToIndex.find(needed);

            // generate result if we already encountered that number
            if(neededIter != numToIndex.end())
            {
                result.push_back(neededIter->second);
                result.push_back(i);
                break;
            }
            // otherwise store in hash map and continue
            else
            {
                numToIndex[num] = i++;
                continue;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    // Public Test Case
    int target = 9;
    std::vector<int> input = {2, 7, 11, 5};
    Solution s = Solution();

    // run to get result
    std::vector<int> result = s.twoSum(input, target);
    std::cout << "Result: input(" << result.at(0) << ") + input("
              << result.at(1) << ") = " << target << std::endl;
    return 0;
}
