<!--
Copy to dsa/<topic>/<problem-slug>.md . Fill ALL tiers you can reach.
The point is the JUMP between tiers — write WHY the next tier is faster.
Commit: feat(dsa): <slug> — brute, better, optimal + complexity
-->

# Two Sum  ·  [LeetCode 1672](https://leetcode.com/problems/richest-customer-wealth/description/)  ·  Difficulty: 🟢Easy

**Pattern:** Array Traversal / Row Sum / Aggregation

## Problem (in my words)
You are given a 2D array accounts.
Each row represents one customer, and each value in that row represents the money they have in one bank.
accounts[i][j] = Customer i has accounts[i][j] money in bank j.
We need to find the maximum wealth among all customers.
In Simple words:-
For every customer:
    Add all their bank balances.
    Find the largest total.

## Examples
```
Input:  accounts = [[1,2,3], [3,2,1]]
Output: 6
```
```
Input:  accounts = [[1,5], [7,3], [3,5]]
Output: 10
```
```
Input:  accounts = [[2,8,7], [7,1,3], [1,9,5]]
Output: 17
```

---

## Tier 1 — Brute force
**Idea:** Nested Loops. For every customer:
Calculate their total wealth.
Compare it with the maximum wealth found so far.
We use one loop for customers and one loop for banks.
```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int customers = accounts.size();
        int banks = accounts[0].size();

        int maxWealth = 0;

        // Go through every customer.
        for (int i = 0; i < customers; i++) {

            int wealth = 0;

            // Add all bank balances
            // belonging to this customer.
            for (int j = 0; j < banks; j++) {

                wealth += accounts[i][j];
            }

            // Update maximum wealth.
            maxWealth = max(maxWealth, wealth);
        }

        return maxWealth;
    }
};

```
**Time:** O(mn)  ·  **Space:** O(1)  ·  **Why it's slow:** Using nested loops needs traversing the whole array for each element until the solution is found. We traversed every customer's row and calculated their total wealth.
After calculating each customer's wealth, we immediately compared it against maxWealth.

## Tier 2 — Better
**Idea:** Use range-based for loops.
Instead of working with indices: accounts[i][j],
we directly process: customer and money
```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int maxWealth = 0;

        // Each row represents one customer.
        for (const vector<int>& customer : accounts) {

            int wealth = 0;

            // Each value represents money
            // in one of the customer's banks.
            for (int money : customer) {

                wealth += money;
            }

            // Keep the maximum wealth seen so far.
            maxWealth = max(maxWealth, wealth);
        }

        return maxWealth;
    }
};

```
**Time:** O(mn)  ·  **Space:** O(n)  ·  **What improved & why:** This doesn't change Big-O complexity, but it makes the code cleaner and reduces index-related bugs. We kept the exact same algorithm but expressed the 2D traversal directly in terms of customers and balances. There is no asymptotically faster solution. So the remaining improvement is primarily implementation quality, not Big-O.

## Tier 3 — Advanced/Optimal
**Idea:** The cleanest implementation is:
For each customer:
    calculate wealth
    update maximum
We can use accumulate() to calculate each row's sum.
```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int maxWealth = 0;

        // Process each customer.
        for (const auto& customer : accounts) {

            // Calculate total wealth of this customer.
            int wealth = accumulate(
                customer.begin(),
                customer.end(),
                0
            );

            // Update the maximum wealth.
            maxWealth = max(maxWealth, wealth);
        }

        return maxWealth;
    }
};

```
**Time:** O(mn)  ·  **Space:** O(1)  ·  **Why this is Advanced:** We treated every row as one customer's wealth calculation. accumulate() sums the row, and maxWealth keeps only the largest total. No sorting, HashMap, or extra matrix is necessary.

---