//
//  main.cpp
//  rehap_memo
//
//  Created by huangwei on 2020/11/17.
//

#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    vector<int> memo(n + 1, -1);
    if (n == 0) {
        return 0;
    }
    
    if (n == 1) {
        return 1;
    }
    
    if (memo[n] == -1) {
        memo[n] = fib(n - 1) + fib(n - 2);
    }
    
    return memo[n];
}

int fib_iter(int n) {
    vector<int> memo(n + 1, -1);
    
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    
    return memo[n];
}

int main(int argc, const char * argv[]) {
    int n = 40;
    cout << fib(n) << endl;
}
