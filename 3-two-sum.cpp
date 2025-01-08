class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> arraymap;

        // took hints from the one pass hashmap concept in the solution video to code this
        // original solution was the brute force one

        for (int i = 0; i < nums.size(); i++)
        {
            if (arraymap.count(target - nums[i]))
            {                                                             // check if target - current_value exists in the hashmap
                return std::vector<int>({arraymap[target - nums[i]], i}); // if so then we have found the solution
            }
            else
            {
                arraymap.insert({nums[i], i}); // otherwise add current_value and its index to the array
            }
        }
    }
};
