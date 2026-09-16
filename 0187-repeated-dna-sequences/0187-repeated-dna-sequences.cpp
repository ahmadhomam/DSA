class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> freq;

        for (int i = 0; i + 9 < s.size(); i++) {
            string temp = s.substr(i, 10);

            freq[temp]++;

            if (freq[temp] == 2) {
                ans.push_back(temp);
            }
        }

        return ans;
    }
};