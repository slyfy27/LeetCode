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
        
        // https://leetcode-cn.com/problems/merge-sorted-array/
//        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//            int h1 = 0, h2 = 0;
//            int sorted[m+n];
//            int cur;
//            while (h1 < m || h2 < n) {
//                if (h1 == m) {
//                    cur = nums2[h2];
//                    h2 ++;
//                } else if (h2 == n) {
//                    cur = nums1[h1];
//                    h1 ++;
//                } else if (nums1[h1] < nums2[h2]) {
//                    cur = nums1[h1];
//                    h1 ++;
//                } else {
//                    cur = nums2[h2];
//                    h2 ++;
//                }
//                sorted[h1 + h2 - 1] = cur;
//            }
//            for (int i = 0; i != m + n; ++ i) {
//                nums1[i] = sorted[i];
//            }
//        }
        
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int p1 = m - 1, p2 = n - 1;
            int tail = m + n - 1;
            int tmp;
            while (p1 >= 0 || p2 >= 0) {
                if (p1 == -1) {
                    tmp = nums2[p2--];
                } else if (p2 == -1) {
                    tmp = nums1[p1--];
                } else if (nums1[p1] > nums2[p2]) {
                    tmp = nums1[p1--];
                } else {
                    tmp = nums2[p2--];
                }
                nums1[tail--] = tmp;
            }
        }
    };
}
