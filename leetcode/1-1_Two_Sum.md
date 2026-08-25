<!--
Copy to dsa/<topic>/<problem-slug>.md . Fill ALL tiers you can reach.
The point is the JUMP between tiers — write WHY the next tier is faster.
Commit: feat(dsa): <slug> — brute, better, optimal + complexity
-->

# Two Sum  ·  [LeetCode 01](https://leetcode.com/problems/two-sum/description/)  ·  Difficulty: 🟢Easy

**Pattern:** Nested loops/ hashing / two pointers

## Problem (in my words)
You are given an array of integers nums and an integer target.
Return indices of the two numbers such that they add up to target.

## Examples
```
Input:  nums = [2,7,11,15], target = 9
Output: [0,1]
```
```
Input:  nums = [3,2,4], target = 6
Output: [1,2]
```

---

## Tier 1 — Brute force
**Idea:** Nested Loops
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        // Try every possible pair.
        for (int i = 0; i < n; i++) {

            // Start from i + 1 so that
            // we never use the same element twice.
            for (int j = i + 1; j < n; j++) {

                // Check whether the current pair
                // adds up to the target.
                if (nums[i] + nums[j] == target) {

                    // Exactly one solution exists,
                    // so we can immediately return.
                    return {i, j};
                }
            }
        }

        return {};
    }
};
```
**Time:** O(n²)  ·  **Space:** O(1)  ·  **Why it's slow:** Using nested loops needs traversing the whole array for each element until the solution is found.

## Tier 2 — Better
**Idea:** Sorting + Two Pointers
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        // Store:
        // {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value.
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {

            int sum =
                arr[left].first +
                arr[right].first;

            if (sum == target) {

                return {
                    arr[left].second,
                    arr[right].second
                };
            }

            if (sum < target) {
                // Need a larger sum.
                left++;
            }
            else {
                // Need a smaller sum.
                right--;
            }
        }

        return {};
    }
};
```
**Time:** O(n log n)  ·  **Space:** O(n)  ·  **What improved & why:** REMEMBER TO PRESERVE THE ORIGINAL INDICES AS THEY WILL CHANGE AFTER SORTING WHICH WILL LEAD TO WRONG ANSWERS. This approach is better than traversing nested loops. The sorting takes an average time of nlogn and thn traversing the array with the help of 2 pointers takes n, so total complexity is nlogn.

## Tier 3 — Advanced
**Idea:** Unordered Map with two passes
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        // First pass:
        // Store every value with its index.
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        // Second pass:
        // Search for the required complement.
        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            // Check whether complement exists.
            if (mp.count(complement)) {

                int j = mp[complement];

                // Make sure we don't use
                // the same element twice.
                if (j != i) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};
```
**Time:** O(n)  ·  **Space:** O(n)  ·  **Why this is Advanced:** Using Unordered map only requires 2 passes, one for storing the elements in the map and one for searching, each taking O(n) time. So total is O(2n)~O(n).

## Tier 3 — Optimal
**Idea:** Unordered Map with single pass
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Stores:
        // number -> index
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            // The number required to pair
            // with nums[i] to reach target.
            int complement = target - nums[i];

            // If complement has already appeared,
            // we have found the answer.
            if (mp.count(complement)) {

                return {
                    mp[complement],
                    i
                };
            }

            // Store current number AFTER checking.
            mp[nums[i]] = i;
        }

        return {};
    }
};
```
**Time:** O(n)  ·  **Space:** O(n)  ·  **Why this is optimal:** This approach does not even need 2 passes. At each step, we are calculating complement, checking whether the complement exists in the map if yes, then answer and if not, then add nums[i]->i to the map

---