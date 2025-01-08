class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        // beat it myself with a "sorting" solution, not the most efficient way
        // and not the best way to check for the anagrams itself

        // std::unordered_map<string, vector<string>> strings_map;

        // for(string s : strs) {
        //     string sorted_str = s;
        //     sort(sorted_str.begin(), sorted_str.end());
        //     if(strings_map.count(sorted_str)) {
        //         strings_map[sorted_str].push_back(s);
        //     }else {
        //         vector<string> stringies = {s};
        //         strings_map.insert({sorted_str, stringies});
        //     }
        // }

        // vector<vector<string>> soln;

        // for(auto strstr : strings_map) {
        //     std::cout << "\n\n";
        //     std::cout << strstr.first << "\n";
        //     for (int i = 0; i < strstr.second.size(); i++) {
        //         std::cout << strstr.second[i] << " ";
        //     }

        //     vector<string> newsoln = strstr.second;
        //     soln.push_back(newsoln);
        // }

        // return soln;

        // following solution based on the solution video by neetcode
        std::unordered_map<string, vector<string>> strings_map;

        for (string s : strs)
        {
            vector<int> count(26, 0);

            // for each string count the number of times each letter appears
            for (char c : s)
            {
                count[c - 'a']++;
            }

            string key = to_string(count[0]); // use the character counts as the hashmap key
            for (int i = 1; i < count.size(); i++)
            {
                key += ", " + to_string(count[i]);
            }
            if (strings_map.count(key))
            {
                strings_map[key].push_back(s);
            }
            else
            {
                vector<string> stringies = {s};
                strings_map.insert({key, stringies});
            }
        }

        vector<vector<string>> result;
        for (const auto &pair : strings_map)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
