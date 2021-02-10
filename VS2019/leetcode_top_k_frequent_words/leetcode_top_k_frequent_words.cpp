// leetcode_top_k_frequent_words.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

struct Order {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        return (a.first > b.first || (a.first == b.first && a.second < b.second));
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        int N = words.size();
        Order ord;

        unordered_map<string, int> word_freq;
        for (string x : words) word_freq[x]++;

        priority_queue<pair<int, string>, vector<pair<int, string>>, Order> pq;

        for (auto item : word_freq) {
            pair<int, string> tmp{ item.second, item.first };
            if (pq.size() < k) pq.push(tmp);
            else if (ord(tmp, pq.top())) {
                pq.push(tmp);
                pq.pop();
            }
        }

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

