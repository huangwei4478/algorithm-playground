//
//  main.cpp
//  fib
//
//  Created by huangwei on 2021/1/4.
//

#include <iostream>
#include <vector>

using namespace std;

vector<long long> memo;

long long fib( int n ) {
    if ( n == 0 ) return 0;
    if ( n == 1 ) return 1;
    if ( memo[n] != -1 ) return memo[n];
    
    memo[n] = fib( n - 1 ) + fib( n - 2 );
    
    return memo[n];
}

int main(int argc, const char * argv[]) {
    int n = 45;
    
    memo = vector<long long>( n + 1, -1 );
    
    time_t startTime = clock();
    long long res = fib(n);
    time_t endTime = clock();
    
    cout << "fib(" << n << ") = " << res << endl;
    cout << "time : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    return 0;
}
