//
//  main.cpp
//  leetcode_min_mutation_gene
//
//  Created by huangwei on 2020/9/9.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int minMutation(string start, string end, vector<string>& bank) {
    unordered_set<string> dict(bank.cbegin(), bank.cend());
    if (dict.find(end) == dict.end()) return -1;
    queue<string> todo;
    todo.push(start);
    vector<char> letter = {'A', 'C', 'G', 'T'};
    int ladder = 1;
    while (!todo.empty()) {
        int n = int(todo.size());
        for (int i = 0; i < n; i++) {
            string word = todo.front();
            todo.pop();
            for (int j = 0; j < word.size(); j++) {
                char c = word[j];
                for (int k = 0; k < letter.size(); k++) {
                    word[j] = letter[k];
                    if (word == end) return ladder;
                    if (dict.find(word) != dict.end()) {
                        todo.push(word);
                        dict.erase(word);
                    }
                }
                word[j] = c;
            }
        }
        ladder++;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
