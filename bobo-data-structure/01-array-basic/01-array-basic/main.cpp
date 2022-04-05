//
//  main.cpp
//  01-array-basic
//
//  Created by huangwei on 2022/4/5.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> arr;
    arr.resize(10);
    
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = i;
    }
    
    for (const auto& ele: arr) {
        cout << ele << " " << endl;
    }
    
    cout << "-------" << endl;
    
    vector<int> arr2{100, 0, 11};
    
    for (const auto& ele: arr2) {
        cout << ele << " " << endl;
    }
    
    return 0;
}
