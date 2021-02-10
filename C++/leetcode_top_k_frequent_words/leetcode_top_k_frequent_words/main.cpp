//
//  main.cpp
//  leetcode_top_k_frequent_words
//
//  Created by huangwei on 2021/2/9.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> ump;
        for (const auto& w : words) {
            ump[w]++;
        }
        
        vector<pair<string, int>> vec;
        for (const auto &p : ump) {
            vec.push_back(p);
        }
        
        sort(vec.begin(), vec.end(), [](const auto& p1, const auto& p2) { return p1.second > p2.second; });
        
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    std::cout << solution.topKFrequent(words, 2) << std::endl;
    return 0;
}
