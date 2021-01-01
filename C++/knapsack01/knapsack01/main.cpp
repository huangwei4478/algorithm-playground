//
//  main.cpp
//  knapsack01
//
//  Created by huangwei on 2020/11/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Knapsack01 {
private:
    int bestValue()
public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int C) {
        int n = w.size();
        return bestValue( w, v, n - 1, C );
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
