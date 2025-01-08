class Solution
{
public:
    string encode(vector<string> &strs)
    {
        // store the string and its length in a separate list and add the length to the beginning
        // also add an underscore after the length

        string res = "";

        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];

            std::cout << s << "\n";

            res += std::to_string(s.size());
            res += "_";
            res += s;
        }

        std::cout << res << "\n";

        return res;
    }

    vector<string> decode(string s)
    {
        std::cout << s << "\n";

        vector<string> res;

        int i = 0;
        while (i < s.size())
        {
            int j = i;
            while (s[j] != '_')
            {
                j++; // keep adding to the length counter
            }
            int length = std::stoi(s.substr(i, j - i)); // get the length as int
            i = j + 1;                                  // set the reading pointer to 1 + length
            j = i + length;                             // set where the next string length count starts
            res.push_back(s.substr(i, length));         // push the curent string to results
            i = j;                                      // set the pointer to the next string
        }

        return res;
    }
};
