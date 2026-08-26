<!--
Copy to dsa/<topic>/<problem-slug>.md . Fill ALL tiers you can reach.
The point is the JUMP between tiers — write WHY the next tier is faster.
Commit: feat(dsa): <slug> — brute, better, optimal + complexity
-->

# Running Sum of 1d Array  ·  [LeetCode 1480](https://leetcode.com/problems/running-sum-of-1d-array/description/)  ·  Difficulty: 🟢Easy

**Pattern:** Nested loops/ hashing / two pointers

## Problem (in my words)
You are given an integer array nums.
For every position i, calculate the sum of all elements from index 0 through i.
runningSum[i] = nums[0] + nums[1] + ... + nums[i]

## Examples
```
Input:  nums = [1,2,3,4]
Output: [1,3,6,10]
```
```
Input:  nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
```

---

## Tier 1 — Brute force
**Idea:** Nested Loops: for every index i, calculate the sum from the beginning of the array up to i.
```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        // For every position i,
        // calculate the sum from index 0 to i.
        for (int i = 0; i < n; i++) {

            int sum = 0;

            // Recalculate the prefix sum
            // from the beginning every time.
            for (int j = 0; j <= i; j++) {

                sum += nums[j];
            }

            ans[i] = sum;
        }

        return ans;
    }
};
```
**Time:** O(n²)  ·  **Space:** O(n)  ·  **Why it's slow:** For every index, we independently recalculated its prefix sum. It works, but we are repeatedly calculating the same values.

## Tier 2 — Better
**Idea:** Instead of calculating each prefix from scratch, maintain one variable: sum. 
current prefix sum = previous prefix sum + current element
```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        // Stores the running/prefix sum
        // as we move through the array.
        int sum = 0;

        for (int i = 0; i < n; i++) {

            // Add the current element
            // to the previous running sum.
            sum += nums[i];

            // Store the running sum
            // for this position.
            ans[i] = sum;
        }

        return ans;
    }
};

```
**Time:** O(n)  ·  **Space:** O(n)  ·  **What improved & why:** Instead of recomputing every prefix sum, we carried the previous sum forward.
previous sum + current value = current sum

## Tier 3 — Optimal
**Idea:** we can directly convert nums into its running-sum array. This is one useful improvement to the previous solution if modifying the input array is allowed.
new nums[i] = old nums[i] + running sum up to i-1. Because after processing i-1, nums[i-1] already contains the running sum up to i-1
```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        // Start from the second element.
        for (int i = 1; i < nums.size(); i++) {

            // nums[i - 1] already contains
            // the running sum up to i - 1.
            nums[i] += nums[i - 1];
        }

        // nums itself is now the running-sum array.
        return nums;
    }
};
```
**Time:** O(n)  ·  **Space:** O(1)  ·  **Why this is optimal:** We traverse from index 1 to n-1 exactly once and no additional array is created. So O(1) auxiliary space. We reused the input array as the output array. Every position stores current value + previous running sum

---