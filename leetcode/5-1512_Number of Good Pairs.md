<!--
Copy to dsa/<topic>/<problem-slug>.md . Fill ALL tiers you can reach.
The point is the JUMP between tiers — write WHY the next tier is faster.
Commit: feat(dsa): <slug> — brute, better, optimal + complexity
-->

# Number of Good Pairs  ·  [LeetCode 1512](https://leetcode.com/problems/number-of-good-pairs/description/)  ·  Difficulty: 🟢Easy

**Pattern:** Nested Loops / HashMap / Frequency Counting / Combinatorics

## Problem (in my words)
You are given an integer array nums. A good pair is a pair of indices (i, j) such that: i < j AND nums[i] == nums[j]
We need to return the total number of good pairs.
Important- We are counting indices, not just distinct values.

## Examples
```
Input:  nums = [1,1,1,1]
Output: 6 [ (0,1), (0,2), (0,3), (1,2), (1,3), (2,3)]
```
```
Input:  nums = [1,2,3,1,1,3]
Output: 4 [(0,3), (0,4), (3,4), (2,5)]
```
```
Input:  nums = [1,2,3]
Output: 0 [There are no duplicate values. Therefore no two different indices contain the same number.]
```

---

## Tier 1 — Brute force
**Idea:** Nested Loops. simply check every possible pair.
```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        int n = nums.size();

        int count = 0;

        // Try every possible first index.
        for (int i = 0; i < n; i++) {

            // j starts from i + 1
            // because we need i < j.
            for (int j = i + 1; j < n; j++) {

                // If both positions contain
                // the same value, we found a good pair.
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
        }

        return count;
    }
};

```
**Time:** O(n²)  ·  **Space:** O(1)  ·  **Why it's slow:** We directly implemented the definition of a good pair. Every possible pair of indices is examined, and we increment the answer whenever their values are equal. The problem doesn't actually require us to compare every pair. For a given value, we only care: How many times has this value appeared before? That lets us eliminate the inner loop.

## Tier 2 — Better
**Idea:** HashMap Frequency. Suppose we are processing an element and we have seen that element before, we will simply add that current value to the frequency map.
```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        unordered_map<int, int> freq;

        int count = 0;

        // Process every number once.
        for (int x : nums) {

            // Every previous occurrence of x
            // creates one new good pair with x.
            count += freq[x];

            // Now include the current x
            // in the frequency table.
            freq[x]++;
        }

        return count;
    }
};

```
**Time:** O(n)  ·  **Space:** O(n)  ·  **What improved & why:** We process every element once. HashMap lookup/insertion is O(1) on average. 
The order of the statements is very crucial:-
count += freq[x];
freq[x]++;
Because freq[x] represents: How many previous occurrences of x exist. so how mnay new pairs can be formed. If you incremented first: the current element will incorrectly contribute one pair with itself.
In the worst case, every element can be different i.e. 1 <= nums[i] <= 100 (given constraint) so there are only 100 possible values: 1, 2, 3, ..., 100. That means we can also use a frequency array instead of a HashMap.

## Tier 3 — Advanced
**Idea:** Frequency Array
Because: 1 <= nums[i] <= 100 , we know exactly what values can occur. So No hashing is required.
```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        // Values range from 1 to 100,
        // so we need indices 0 through 100.
        vector<int> freq(101, 0);

        int count = 0;

        // Process each number once.
        for (int x : nums) {

            // Every previous x forms
            // a new good pair with current x.
            count += freq[x];

            // Record the current x.
            freq[x]++;
        }

        return count;
    }
};

```
**Time:** O(n)  ·  **Space:** O(K)  ·  **Why this is Advanced:** We process every element exactly once and thus replaced the HashMap with a fixed-size frequency array because the constraints guarantee that values lie between 1 and 100. The frequency array has a fixed size based on the value range i.e. K=100. So technically: O(100) ~ O(1) with respect to n. The algorithm remains one-pass O(n), but the lookup is simpler and has lower constant overhead. Tier 2 and Tier 3 already have optimal asymptotic time. So Tier 4 isn't about reducing Big-O. It's about understanding the mathematical counting pattern behind the problem and writing the cleanest possible implementation.

## Tier 4 — Optimal
**Idea:** Incremental Pair Counting
This is essentially the frequency solution, but let's understand it as a mathematical invariant.
When processing the current value x:
number of new pairs = number of x's seen previously
Then: frequency[x]++
We're constructing the answer incrementally.
```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        // Stores how many times each value
        // has appeared so far.
        unordered_map<int, int> freq;

        int goodPairs = 0;

        for (int x : nums) {

            // If x has appeared k times before,
            // current x creates k new pairs.
            goodPairs += freq[x];

            // Add current x to the seen frequency.
            freq[x]++;
        }

        return goodPairs;
    }
};

```
**Time:** O(n)  ·  **Space:** O(K)  ·  **Why this is Optimal:** There are n elements. We need to determine how many equal-value pairs exist. At minimum, we must inspect the elements: 
1 → 2 → 3 → ... → n. Therefore we have an: Ω(n) lower bound.
Our solution takes: O(n) average time. Therefore: O(n) = Ω(n) So it is asymptotically optimal.

---