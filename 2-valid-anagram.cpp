class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        std::unordered_map<char, int> character_frequencies_s;

        for (char c : s)
        {
            if (character_frequencies_s.count(c))
            {
                int c_freq = character_frequencies_s[c];
                c_freq++;
                character_frequencies_s[c] = c_freq;
            }
            character_frequencies_s.insert({c, 1});
        }

        // for (auto cf : character_frequencies_s) {
        //     std::cout << cf.first << " " << cf.second << "\n";
        // }

        std::unordered_map<char, int> character_frequencies_t;

        for (char c : t)
        {
            if (character_frequencies_t.count(c))
            {
                int c_freq = character_frequencies_t[c];
                c_freq++;
                character_frequencies_t[c] = c_freq;
            }
            character_frequencies_t.insert({c, 1});
        }

        if (character_frequencies_s == character_frequencies_t)
        {
            return true;
        }

        return false;
    }
};
