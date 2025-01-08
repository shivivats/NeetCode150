class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // going by the neetcode video explanation of the modified bucket sort algo

        // make a bucket of size n which is the size of the input array
        // each value in the bucket corresponds to the number whose frequency is at that index
        // i.e. bucket index 2 has its value as the array of numbers that occur twice in the input array

        std::unordered_map<int, int> count;
        std::vector<vector<int>> freq(nums.size() + 1);

        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++; // get all the counts of each number in a hashmap
        }

        for (auto it : count)
        {
            freq[it.second].push_back(it.first); // store the buckets here
        }

        vector<int> res;

        for (int i = freq.size() - 1; i >= 0; i--)
        { // go through the buckets in descending order of count
            for (int j = 0; j < freq[i].size(); j++)
            {
                res.push_back(freq[i][j]); // keep adding to result till k items are added
                if (res.size() == k)
                {
                    return res;
                }
            }
        }
    }
};
