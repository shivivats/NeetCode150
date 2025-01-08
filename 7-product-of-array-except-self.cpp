class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size(), 1);

        // inspired by the neetcode video solution but code is mine

        vector<int> prefix_prod(nums.size(), 1);
        vector<int> postfix_prod(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++)
        {
            prefix_prod[i] = i == 0 ? nums[i] : prefix_prod[i - 1] * nums[i];
            int j = nums.size() - 1 - i;
            postfix_prod[j] = j == nums.size() - 1 ? nums[j] : postfix_prod[j + 1] * nums[j];
        }

        for (int value : prefix_prod)
        {
            std::cout << value << " ";
        }

        std::cout << "\n";

        for (int value : postfix_prod)
        {
            std::cout << value << " ";
        }

        for (int i = 0; i < nums.size(); i++)
        {
            res[i] = (i == 0 ? 1 : prefix_prod[i - 1]) * (i == nums.size() - 1 ? 1 : postfix_prod[i + 1]);
        }

        return res;
    }
};
