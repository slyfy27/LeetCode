//
//  aray_solution.cpp
//  leetcode
//
//  Created by slyfy27 on 2021/7/17.
//

#include "aray_solution.hpp"
#include <vector>

using namespace std;

namespace Algorithm {
    
    class EasyArraySolution {
        
    public:
        // https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
        int removeDuplicates(vector<int>& nums) {
            // fast slow
            int n = nums.size();
            if (n == 0) {
                return 0;
            }
            int fast = 1, slow = 1;
            while (fast < n) {
                if (nums[fast] != nums[fast - 1]) {
                    if (fast-slow >= 1) {
                        nums[slow] = nums[fast];
                    }
                    ++slow;
                }
                ++fast;
            }
            return slow;
        }
        
        // https://leetcode-cn.com/problems/remove-element/
        int removeElement(vector<int>& nums, int val) {
            int left = 0,right = nums.size() -1;
            while (left <= right) {
                if (nums[left] == val) {
                    int tmp = nums[right];
                    nums[right] = nums[left];
                    nums[left] = tmp;
                    right --;
                } else {
                    left ++;
                }
            }
            return left;
        }
        
        // https://leetcode-cn.com/problems/plus-one/
        vector<int> plusOne(vector<int>& digits) {
            int carry = (++digits.back()) /10;
            digits.back() %= 10;
            int i = digits.size()-2;
            while(i >= 0 && carry)
            {
                digits[i] += carry;
                carry = digits[i]/10;
                digits[i] %= 10;
                -- i;
            }
            if (carry)
                digits.insert(digits.begin(),1);
            return digits;
        }
    };
}
