//
//  main.cpp
//  leetcode_ladder_length
//
//  Created by huangwei on 2020/9/10.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.cbegin(), wordList.cend());
        if (!dict.count(endWord)) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int l = beginWord.length();
        int step = 0;
        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; size--) {
                string w = q.front();
                q.pop();
                for (int i = 0; i < l; i++) {
                    char ch = w[i];
                    // make decision
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        // Found the solution
                        if (w == endWord) return step + 1;
                        // Not in dict, skip it
                        if (!dict.count(w)) continue;
                        // Remove new word from dict
                        dict.erase(w);
                        q.push(w);
                    }

                    // undo decision
                    w[i] = ch;
                }
            }
        }
        return 0;
    }
    
    vector<vector<string>> ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.cbegin(), wordList.cend());
        if (!dict.count(endWord)) return {};
        dict.erase(beginWord);
        dict.erase(endWord);
        
        unordered_map<string, int> steps{{beginWord, 1}};
        unordered_map<string, vector<string>> parents;
        queue<string> q;
        q.push(beginWord);
        
        vector<vector<string>> ans;
        
        const int l = beginWord.length();
        int step = 0;
        bool found = false;
        
        while (!q.empty() && !found) {
            ++step;
            for (int size = q.size(); size > 0; size--) {
                const string p = q.front(); q.pop();
                string w = p;
                for (int i = 0; i < l; i++) {
                    const char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        if (j == ch) continue;
                        w[i] = j;
                        if (w == endWord) {
                            parents[w].push_back(p);
                            found = true;
                        } else {
                            // Not a new word, but another transform with the same number of steps
                            if (steps.count(w) && step < steps.at(w)) {
                                parents[w].push_back(p);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
