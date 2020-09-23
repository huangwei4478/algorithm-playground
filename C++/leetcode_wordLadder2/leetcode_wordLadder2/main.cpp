//
//  main.cpp
//  leetcode_wordLadder2
//
//  Created by huangwei on 2020/9/14.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

/**
 BFS 创建图
 DFS 搜索路径
 */

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.cbegin(), wordList.cend());
        if (!dict.count(endWord)) return {};
        dict.erase(beginWord);
        dict.erase(endWord);
        
        /**
         - 每个单词扩展到自己的最短步数
         - 用于判断单词是否是同一层
         */
        unordered_map<string, int> steps{{beginWord, 1}};
    
        /**
         记录这个单词的parent
         */
        unordered_map<string, vector<string>> parents;
        queue<string> q;
        q.push(beginWord);
        vector<vector<string>> ans;
        
        const int l = static_cast<int>(beginWord.length());
        int step = 0;
        bool found = false;                 // 是否找到解
        while (!q.empty() && !found) {
            ++step;
            for (int size = q.size(); size > 0; size--) {
                const string p = q.front(); q.pop();            // 这个是parent
                string w = p;                                   // 复制一份w，作为son，开始迭代
                for (int i = 0; i < l; i++) {
                    const char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        if (j == ch) continue;
                        w[i] = j;
                        if (w == endWord) {
                            parents[w].push_back(p);
                            found = true;
                        } else {
                            // 同一层
                            if (steps.count(w) && step < steps.at(w)) {
                                parents[w].push_back(p);
                            }
                        }
                        
                        if (!dict.count(w)) continue;
                        dict.erase(w);
                        q.push(w);
                        steps[w] = steps.at(p) + 1;
                        parents[w].push_back(p);
                    }
                    w[i] = ch;
                }
            }
        }
        
        if (found) {
            vector<string> curr{endWord};
            getPaths(endWord, beginWord, parents, curr, ans);
        }
        
       
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
