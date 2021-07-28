//
//  aray_solution.cpp
//  leetcode
//
//  Created by slyfy27 on 2021/7/17.
//

#include "aray_solution.hpp"
#include <vector>
#include <unordered_set>
#include <set>
#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>

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
        
        // https://leetcode-cn.com/problems/pascals-triangle-ii/
        vector<int> getRow(int rowIndex) {
            vector<vector<int>> rs(rowIndex+1);
            for (int i = 0; i <= rowIndex; i ++) {
                rs[i].resize(i+1);
                rs[i][0] = rs[i][i] = 1;
                for (int j = 1; j < i;  ++ j) {
                    rs[i][j] = rs[i-1][j] + rs[i-1][j-1];
                }
            }
            return rs[rowIndex];
        }
        
        vector<int> getRow2(int rowIndex) {
            vector<int> pre, rs;
            for (int i = 0; i <= rowIndex; i ++) {
                rs.resize(i+1);
                rs[0] = rs[i] = 1;
                for (int j = 1; j < i; ++j) {
                    rs[j] = pre[j-1] + pre[j];
                }
                pre = rs;
            }
            return rs;
        }
        
        vector<int> getRow3(int rowIndex) {
            vector<int> rs = vector<int>(rowIndex+1);
            rs[0] = 1;
            for (int i = 1; i <= rowIndex; ++ i) {
                for (int j = i; j > 0; --j) {
                    rs[j] += rs[j-1];
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode-s/
        int maxProfit(vector<int>& prices) {
            int size = prices.size();
            int dp[size][2];
            dp[0][0] = 0;
            dp[0][1] = -prices[0];
            for (int i = 1; i < size; i ++) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            }
            return max(dp[size-1][0], dp[size-1][1]);
        }
        
        int maxProfit2(vector<int>& prices) {
            int income = 0;
            for (int i = 1; i < prices.size(); i ++) {
                if (prices[i] - prices[i-1] > 0) {
                    income += prices[i] - prices[i-1];
                }
            }
            return income;
        }
        
        // https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> rs(2);
            int left = 1, right = numbers.size();
            while (left < right) {
                int sum = numbers[left-1] + numbers[right-1];
                if (sum > target) {
                    right --;
                } else if (sum < target) {
                    left ++;
                } else {
                    rs.push_back(left);
                    rs.push_back(right);
                    break;
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/count-primes/
        
//        bool isPrime(int x) {
//            for (int i = 2; i * i <= x; i ++) {
//                if (x % i == 0) {
//                    return false;
//                }
//            }
//            return true;
//        }
//
//        int countPrimes(int n) {
//            int rs = 0;
//            for (int i = 2; i < n; i ++) {
//                rs += isPrime(i);
//            }
//            return rs;
//        }
        
        int countPrimes(int n) {
            int count = 0;
            vector<int> isPrime(n, 1);
            for (int i = 2; i < n; i ++) {
                if (isPrime[i]) {
                    count ++;
                    if ((long long)i * i < n) {
                        for (int j = i * i; j < n; j += i) {
                            isPrime[j] = 0;
                        }
                    }
                }
            }
            return count;
        }
        
        int countPrimes2(int n) {
            vector<int> primes;
            vector<int> isPrime(n, 1);
            for (int i = 2; i < n; i ++) {
                if (isPrime[i]) {
                    primes.push_back(i);
                }
                for (int j = 0; j < primes.size() && i * primes[j] < n; j ++) {
                    isPrime[i * primes[j]] = 0;
                    if (i % primes[j] == 0) {
                        break;
                    }
                }
            }
            return primes.size();
        }
        
        // https://leetcode-cn.com/problems/contains-duplicate/
        bool containsDuplicate(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            bool rs = false;
            for (int i = 1; i < nums.size(); i ++) {
                if (nums[i] == nums[i-1]) {
                    rs = true;
                    break;
                }
            }
            return rs;
        }
        
        bool containsDuplicate2(vector<int>& nums) {
            unordered_set<int> set;
            for (int n : nums) {
                if (set.find(n) != set.end()) {
                    return true;
                } else {
                    set.insert(n);
                }
            }
            return false;
        }
        
        // https://leetcode-cn.com/problems/contains-duplicate-ii/
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            if (k == 0) {
                return false;
            }
            unordered_set<int> set;
            for (int i = 0; i < nums.size(); i ++) {
                if (set.find(nums[i]) != set.end()) {
                    return true;
                } else {
                    if (set.size() >= k) {
                        set.erase(nums[i-k]);
                    }
                    set.insert(nums[i]);
                }
            }
            return false;
        }
        
        // https://leetcode-cn.com/problems/summary-ranges/
        vector<string> summaryRanges(vector<int>& nums) {
            int i = 0;
            vector<string> rs;
            while (i < nums.size()) {
                int left = i;
                i ++;
                while (i < nums.size() && nums[i] == nums[i-1] + 1) {
                    i ++;
                }
                int right = i - 1;
                if (left < right) {
                    string ls = to_string(nums[left]);
                    ls += "->";
                    ls += to_string(nums[right]);
                    rs.push_back(ls);
                } else {
                    string ls = to_string(nums[left]);
                    rs.push_back(ls);
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/missing-number/
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            //等差数列求和
            int sum = n * (n+1)/2;
            for (int i: nums) {
                sum -= i;
            }
            return sum;
        }
        
        // https://leetcode-cn.com/problems/move-zeroes/
        void moveZeroes(vector<int>& nums) {
            for (int i = 0; i < nums.size(); i ++) {
                if (nums[i] == 0) {
                    for (int j = i + 1; j < nums.size(); j ++) {
                        if (nums[j] != 0) {
                            //swap
                            int tmp = nums[j];
                            nums[j] = nums[i];
                            nums[i] = tmp;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < nums.size(); i ++) {
                std::cout << nums[i] << "\n" << endl;
            }
        }
        
        // https://leetcode-cn.com/problems/intersection-of-two-arrays/
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> set;
            unordered_set<int> rset;
            vector<int> rs;
            for (int i: nums1) {
                set.insert(i);
            }
            for (int i: nums2) {
                if (rset.find(i) == set.end()) {
                    if (set.find(i) != set.end()) {
                        rs.push_back(i);
                        rset.insert(i);
                    }
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            int p1 = 0, p2 = 0;
            vector<int> rs;
            while (p1 < nums1.size() && p2 < nums2.size()) {
                if (nums1[p1] == nums2[p2]) {
                    rs.push_back(nums1[p1]);
                    p1 ++;
                    p2 ++;
                } else if (nums1[p1] < nums2[p2]) {
                    p1 ++;
                } else {
                    p2 ++;
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/third-maximum-number/
        int thirdMax(vector<int>& nums) {
            set<int> s(nums.begin(), nums.end());
            int n = s.size();
            if (n < 3) return *(s.rbegin());
            set<int>::reverse_iterator iter = s.rbegin();
            iter++;
            iter++;
            return *iter;
        }
        
        // https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
//        vector<int> findDisappearedNumbers(vector<int>& nums) {
//            unordered_set<int> source;
//            vector<int> rs;
//            for (int i = 1; i <= nums.size() ; i ++) {
//                source.insert(i);
//            }
//            for (int n: nums) {
//                source.erase(n);
//            }
//            for (int n: source) {
//                rs.push_back(n);
//            }
//            return rs;
//        }
        
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            int size = nums.size();
            vector<int> rs;
            for (int n: nums) {
                nums[n-1] += size;
            }
            for (int i = 0; i < size; i ++) {
                if (nums[i] > size) {
                    rs.push_back(i+1);
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/
        int minMoves(vector<int>& nums) {
            int min = INT_MAX;
            for (int n: nums) {
                if (n < min) {
                    min = n;
                }
            }
            int rs = 0;
            for (int n: nums) {
                rs += n - min;
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/assign-cookies/
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int gg = 0, ss = 0;
            int rs = 0;
            while (gg < g.size() && ss < s.size()) {
                if (s[ss] >= g[gg]) {
                    ss ++;
                    gg ++;
                    rs ++;
                } else {
                    ss ++;
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/island-perimeter/
        int islandPerimeter(vector<vector<int>>& grid) {
            int rs = 0;
            for (int i = 0; i < grid.size(); i ++) {
                for (int j = 0; j < grid[i].size(); j ++) {
                    if (grid[i][j] == 1) {
                        rs += 4;
                        if (i > 0) {
                            if (grid[i - 1][j] == 1) {
                                rs -= 1;
                            }
                        }
                        if (j > 0) {
                            if (grid[i][j-1] == 1) {
                                rs -= 1;
                            }
                        }
                        if ((i + 1) < grid.size()) {
                            if (grid[i + 1][j] == 1) {
                                rs -= 1;
                            }
                        }
                        if ((j + 1) < grid[i].size()) {
                            if (grid[i][j+1] == 1) {
                                rs -= 1;
                            }
                        }
                    }
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/max-consecutive-ones/
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int rs = 0;
            int tmp = 0;
            for (int i = 0; i < nums.size(); i ++) {
                if (nums[i] == 0) {
                    rs = max(rs,tmp);
                    tmp = 0;
                } else {
                    tmp ++;
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/teemo-attacking/
        int findPoisonedDuration(vector<int>& timeSeries, int duration) {
            int rs = 0;
            rs += duration;
            for (int i = 1; i < timeSeries.size(); i ++) {
                int sub = timeSeries[i] - timeSeries[i-1];
                if (sub < duration) {
                    rs += sub;
                } else {
                    rs += duration;
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/relative-ranks/
        vector<string> findRelativeRanks(vector<int>& score) {
            vector<int> source = score;
            vector<string> rs;
            unordered_map<int, string> map;
            sort(score.begin(), score.end());
            for (int i = 0; i <score.size(); i ++) {
                switch (score.size() - i - 1) {
                    case 0:
                        map[score[i]] = "Gold Medal";
                        break;
                    case 1:
                        map[score[i]] = "Silver Medal";
                        break;
                    case 2:
                        map[score[i]] = "Bronze Medal";
                        break;
                    default:
                        map[score[i]] = to_string(score.size() - i);
                        break;
                }
            }
            for (int i = 0; i < source.size(); i ++) {
                rs.push_back(map[source[i]]);
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/longest-harmonious-subsequence/
        //超时
//        int findLHS(vector<int>& nums) {
//            int rs = 0;
//            for (int i = 0; i < nums.size(); i ++) {
//                int length = 0;
//                bool flag = false;
//                for (int j = 0; j < nums.size(); j ++) {
//                    if (nums[j] == nums[i]) {
//                        length ++;
//                    } else if (nums[j] + 1 == nums[i]) {
//                        length ++;
//                        flag = true;
//                    }
//                }
//                if (flag) {
//                    rs = max(rs,length);
//                }
//            }
//            return rs;
//        }
        
        // https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/
//        vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
//            vector<string> rs;
//            int min = INT_MAX;
//            for (int i = 0 ; i < list1.size(); i ++) {
//                for (int j = 0; j < list2.size(); j ++) {
//                    if (list1[i] == list2[j]) {
//                        if (min > i + j) {
//                            min = i + j;
//                            rs.clear();
//                        } else if (min < i + j) {
//                            break;
//                        }
//                        rs.push_back(list2[j]);
//                        break;
//                    }
//                }
//            }
//            return rs;
//        }
        
        vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
            vector<string> rs;
            unordered_map<string, int> map1;
            int min = INT_MAX;
            for (int i = 0 ; i < list1.size(); i ++) {
                map1[list1[i]] = i;
            }
            for (int j = 0; j < list2.size(); j ++) {
                if (map1.find(list2[j]) != map1.end()) {
                    if (min < map1[list2[j]] + j) {
                        break;
                    } else if (min > map1[list2[j]] + j) {
                        min = map1[list2[j]] + j;
                        rs.clear();
                    }
                    rs.push_back(list2[j]);
                }
            }
            return rs;
        }
        
        // https://leetcode-cn.com/problems/can-place-flowers/
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            int count = 0;
            int m = flowerbed.size();
            int prev = -1;
            for (int i = 0; i < m; i++) {
                if (flowerbed[i] == 1) {
                    if (prev < 0) {
                        count += i / 2;
                    } else {
                        count += (i - prev - 2) / 2;
                    }
                    if (count >= n) {
                        return true;
                    }
                    prev = i;
                }
            }
            if (prev < 0) {
                count += (m + 1) / 2;
            } else {
                count += (m - prev - 1) / 2;
            }
            return count >= n;
        }
        
        // https://leetcode-cn.com/problems/maximum-product-of-three-numbers/
        int maximumProduct(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            return max(nums[0] * nums[1] * nums[n-1], nums[n-1] * nums[n-2] * nums[n-3]);
        }
        
        // https://leetcode-cn.com/problems/maximum-average-subarray-i/
        double findMaxAverage(vector<int>& nums, int k) {
            int rs = 0;
            for (int i = 0; i < k; i ++) {
                rs += nums[i];
            }
            int cur = rs;
            for (int i = k; i < nums.size(); i ++) {
                int tmp = cur - nums[i-k] + nums[i];
                rs = max(rs, tmp);
                cur = tmp;
            }
            return rs*1.0/k;
        }
        
        // https://leetcode-cn.com/problems/set-mismatch/
        vector<int> findErrorNums(vector<int>& nums) {
            vector<int> rs;
            unordered_set<int> set;
            int n = nums.size();
            //等差数列求和
            int errorn;
            int sum = n * (n+1)/2;
            for (int num: nums) {
                if (set.find(num) != set.end()) {
                    errorn = num;
                    rs.push_back(errorn);
                } else {
                    set.insert(num);
                    sum -= num;
                }
            }
            rs.push_back(sum);
            return rs;
        }
        
        // https://leetcode-cn.com/problems/image-smoother/
        vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
            vector<vector<int>> option = {{-1,0},{-1,1},{-1,-1},{1,0},{1,1},{1,-1},{0,1},{0,-1}};
            vector<vector<int>> rs(img.begin(),img.end());
            for (int i = 0; i < img.size(); i ++) {
                for (int j = 0; j < img[i].size(); j ++) {
                    int tmp = img[i][j];
                    int count = 1;
                    for(vector<int> op: option) {
                        int x = i + op[0];
                        int y = j + op[1];
                        if (x >= 0 && x < img.size() && y >= 0 && y < img[i].size()) {
                            tmp += img[x][y];
                            count ++;
                        }
                    }
                    rs[i][j] = tmp/count;
                }
            }
            return img;
        }
        
        // https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
        int findLengthOfLCIS(vector<int>& nums) {
            int rs = 1;
            int cur = 1;
            for (int i = 1; i < nums.size(); i ++) {
                if (nums[i-1] < nums[i]) {
                    cur ++;
                } else {
                    rs = max(rs, cur);
                    cur = 1;
                }
            }
            return max(rs,cur);
        }
        
        // https://leetcode-cn.com/problems/degree-of-an-array/
        int findShortestSubArray(vector<int>& nums) {
            unordered_map<int, vector<int>> rs;
            for (int i = 0; i < nums.size(); i ++) {
                if (rs.find(nums[i]) != rs.end()) {
                    rs[nums[i]].push_back(i);
                } else {
                    vector<int> tmp;
                    tmp.push_back(i);
                    rs[nums[i]] = tmp;
                }
            }
            int m = 1;
            int r = INT_MAX;
            for (auto it = rs.begin(); it != rs.end(); it ++) {
                vector<int> tmp = it->second;
                if (tmp.size() > m) {
                    r = tmp[tmp.size()-1] - tmp[0] + 1;
                    m = tmp.size();
                } else if (tmp.size() == m) {
                    r = min(tmp[tmp.size()-1] - tmp[0] + 1, r);
                }
            }
            return r + 1;
        }
        
        // https://leetcode-cn.com/problems/1-bit-and-2-bit-characters/
        bool isOneBitCharacter(vector<int>& bits) {
            int n = bits.size();
            int idx = 0;
            while (idx < n - 1) {
                idx += bits[idx] + 1;
            }
            return idx == n-1;
        }
        
        // https://leetcode-cn.com/problems/longest-word-in-dictionary/
        
        //前缀数
        class TrieNode {
            string word;
            /// 26个字母
            TrieNode *children[26];
            bool end;
            
            TrieNode(){
                word = "";
                end = false;
                memset(children, sizeof(TrieNode *), 26);
            }
        };
        
        class TrieTree {
            
        };
        
//        string longestWord(vector<string>& words) {
//            
//        }
        
        // https://leetcode-cn.com/problems/range-addition-ii/
        int maxCount(int m, int n, vector<vector<int>>& ops) {
            int x = m, y = n;
            if (ops.size() == 0) {
                return x * y;
            }
            for(auto v: ops) {
                x = min(v[0]-1,x);
                y = min(v[1]-1,y);
                x = max(x, 0);
                y = max(y, 0);
            }
            return (x+1)*(y+1);
        }
        
        // https://leetcode-cn.com/problems/flood-fill/
        
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            const int dx[4] = {1, 0, 0, -1};
            const int dy[4] = {0, 1, -1, 0};
            int currColor = image[sr][sc];
            if (currColor == newColor) return image;
            int n = image.size(), m = image[0].size();
            queue<pair<int, int>> que;
            que.emplace(sr, sc);
            image[sr][sc] = newColor;
            while (!que.empty()) {
                int x = que.front().first, y = que.front().second;
                que.pop();
                for (int i = 0; i < 4; i++) {
                    int mx = x + dx[i], my = y + dy[i];
                    if (mx >= 0 && mx < n && my >= 0 && my < m && image[mx][my] == currColor) {
                        que.emplace(mx, my);
                        image[mx][my] = newColor;
                    }
                }
            }
            return image;
        }
    };
}
