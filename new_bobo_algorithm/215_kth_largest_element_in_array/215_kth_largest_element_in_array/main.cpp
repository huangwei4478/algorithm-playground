//
//  main.cpp
//  215_kth_largest_element_in_array
//
//  Created by 黄炜 on 2022/6/16.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        if (s.size() <= 1) { return s; }

        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                   'A', 'E', 'I', 'O', 'U'};
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (vowels.count(s[l]) == 0 && l < s.size()) {
                l++;
            }

            while (vowels.count(s[r]) == 0 && r >= 0) {
                r--;
            }

            if (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            } else {
                break;
            }
        }

        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << Solution().reverseVowels(".,") << std::endl;
    return 0;
}
