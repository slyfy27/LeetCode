//
//  main.cpp
//  leetcode
//
//  Created by slyfy27 on 2021/7/17.
//

#include <iostream>
#include "aray_solution.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    using namespace Algorithm;
    EasyArraySolution solution = EasyArraySolution();
    vector<int> nums = vector<int>(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
//    nums.push_back(4);
//    nums.push_back(5);
    int res = solution.removeDuplicates(nums);
    std::cout << "result\n" << res << "\n";
    for (int i = 0; i < res; i ++) {
        std::cout << nums[i] << "\n";
    }
    return 0;
}
