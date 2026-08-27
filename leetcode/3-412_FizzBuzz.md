<!--
Copy to dsa/<topic>/<problem-slug>.md . Fill ALL tiers you can reach.
The point is the JUMP between tiers — write WHY the next tier is faster.
Commit: feat(dsa): <slug> — brute, better, optimal + complexity
-->

# Fizz Buzz  ·  [LeetCode 412](https://leetcode.com/problems/fizz-buzz/description/)  ·  Difficulty: 🟢Easy

**Pattern:** Simulation

## Problem (in my words)
You are given an integer n. For every number from 1 to n:
If the number is divisible by both 3 and 5, add "FizzBuzz".
If divisible by 3, add "Fizz".
If divisible by 5, add "Buzz".
Otherwise, add the number itself as a string.
Return the complete array/vector

## Examples
```
Input: n = 3
Output: ["1","2","Fizz"]
```
```
Input:  n = 5
Output: ["1","2","Fizz","4","Buzz"]
```
```
Input:  n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
```
---

## Tier 1 — Brute force
**Idea:** For every number, independently check:
Is it divisible by 3? Is it divisible by 5? Is it divisible by both? A straightforward implementation can perform the checks independently.
```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> ans;

        for (int i = 1; i <= n; i++) {

            bool divisibleBy3 = (i % 3 == 0);
            bool divisibleBy5 = (i % 5 == 0);

            // Divisible by both 3 and 5
            if (divisibleBy3 && divisibleBy5) {
                ans.push_back("FizzBuzz");
            }
            // Divisible only by 3
            else if (divisibleBy3) {
                ans.push_back("Fizz");
            }
            // Divisible only by 5
            else if (divisibleBy5) {
                ans.push_back("Buzz");
            }
            // Not divisible by either
            else {
                ans.push_back(to_string(i));
            }
        }

        return ans;
    }
};
```
**Time:** O(n)  ·  **Space:** O(1)  ·  **Why it's slow:** The order matters here for executing instructions. As we are required to return the array/vector, the auxiliary space complexity will be O(1). The Output Space will be O(n).

## Tier 2 — Better/Optimal
**Idea:** Instead of calculating two Boolean conditions: (i % 3 == 0) and (i % 5 == 0), directly check with LCM(3,5) = 15 i.e. (i % 15 == 0) for "FizzBuzz".
```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> ans;

        for (int i = 1; i <= n; i++) {

            // Divisible by both 3 and 5
            // means divisible by LCM(3,5) = 15.
            if (i % 15 == 0) {
                ans.push_back("FizzBuzz");
            }
            // Divisible by 3
            else if (i % 3 == 0) {
                ans.push_back("Fizz");
            }
            // Divisible by 5
            else if (i % 5 == 0) {
                ans.push_back("Buzz");
            }
            // Otherwise, use the number itself.
            else {
                ans.push_back(to_string(i));
            }
        }

        return ans;
    }
};

```
**Time:** O(n)  ·  **Space:** O(1)  ·  **What improved & why:** Still one iteration for every number and each iteration performs a constant number of operations.

---