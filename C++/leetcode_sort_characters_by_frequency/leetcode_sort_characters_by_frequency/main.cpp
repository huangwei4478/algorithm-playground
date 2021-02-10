//
//  main.cpp
//  leetcode_sort_characters_by_frequency
//
//  Created by huangwei on 2021/2/9.
//

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution_vector_sort {
public:
    // unordered map -> ordered vector, use pair to compair their 'seconds'
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for (const auto& c: s) {
            ++ump[c];
        }
        vector<pair<char, int>> vec;
        for (const auto&m : ump) {
            vec.push_back(m);
        }
        
        sort(vec.begin(), vec.end(), [](const auto& p1, const auto& p2) { return p1.second > p2.second; });
        
        string ret;
        for (const auto &v : vec) {
            ret += string(v.second, v.first);
        }
        
        return ret;
    }
};

class Solution_Priority_Queue {
    
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        
        for (const auto &c: s) {
            ++ump[c];
        }
        
        priority_queue<pair<int, char>> pq;
        for (const auto &m : ump) {
            pq.push({ m.second, m.first });
        }
        
        string ret;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            ret.append(t.first, t.second);
        }
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
