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
//    vector<int> nums = vector<int>(3);
//    nums.push_back(1);
//    nums.push_back(1);
//    nums.push_back(2);
////    nums.push_back(4);
////    nums.push_back(5);
//    int res = solution.removeDuplicates(nums);
//    std::cout << "result\n" << res << "\n";
//    for (int i = 0; i < res; i ++) {
//        std::cout << nums[i] << "\n";
//    }
    
//    vector<int> rs = solution.getRow3(3);
//    for (int i = 0; i < rs.size(); i ++) {
//        std::cout << rs[i] << "\n";
//    }
    
//    vector<int> prices = {7,1,5,3,6,4};
//    int income = solution.maxProfit2(prices);
//    std::cout << income << "\n";
    
//    int rs = solution.countPrimes(10);
//    std::cout << rs << "\n";
//    vector<int> nums = {2147483647,2147483647};
//    bool rs = solution.containsNearbyDuplicate(nums, 0);
//    vector<string> rs = solution.summaryRanges(nums);
//    for (string s : rs) {
//        std::cout << s << "\n";
//    }
//    vector<int> nums = {0,1,2,3,0,13};
//    solution.moveZeroes(nums);
    
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    solution.intersect(nums1, nums2);
    return 0;
}
