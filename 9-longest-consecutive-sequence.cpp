class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // sorting was my solution but its nlogn so we can do better

        // make a set of all the numbers (sets are by default unique)

        // check if num+1 exists in the set, thus num is the start of a sequence
        // or if num-1 exists then num is part of a sequence

        // most of this code is still mine but I was confused about couting the sequence
        // i feel like the while loop makes it worse than O(n)

        std::set<int> uniques(nums.begin(), nums.end());
        int longestSeq = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!uniques.count(nums[i] - 1))
            {
                // nums[i] is the start of a sequence
                int length = 0;
                while (uniques.count(nums[i] + length))
                {
                    length++;
                }
                longestSeq = longestSeq > length ? longestSeq : length;
            }
        }

        return longestSeq;
    }
};
