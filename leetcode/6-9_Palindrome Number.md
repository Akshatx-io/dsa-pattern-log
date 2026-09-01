<!--
Copy to dsa/<topic>/<problem-slug>.md . Fill ALL tiers you can reach.
The point is the JUMP between tiers — write WHY the next tier is faster.
Commit: feat(dsa): <slug> — brute, better, optimal + complexity
-->

# Palindrome Number  ·  [LeetCode 9](https://leetcode.com/problems/palindrome-number/submissions/2126745920/)  ·  Difficulty: 🟢Easy

**Pattern:** Math / Digit Manipulation / Reverse Half

## Problem (in my words)
You are given an integer x. You need to determine whether x reads the same: left → right AND right → left. If yes, return:
true else false.
The important constraint is: -2^31 <= x <= 2^31 - 1, that is the range of a signed 32-bit integer(Reversing the whole number can overflow int) and also No negative integer can be a palindrome under normal decimal representation.

## Examples
```
Input:  x = 121
Output: true
```
```
Input:  x = -121
Output: false
```
```
Input:  x = 10
Output: false
```

---

## Tier 1 — Brute force
**Idea:** Convert the integer into a string. Then compare characters from both ends: If every matching pair is equal, the number is a palindrome.
````
left
 ↓
1 2 3 2 1
        ↑
      right
````
```cpp
class Solution {
public:
    bool isPalindrome(int x) {

        // Convert the integer to a string.
        string s = to_string(x);

        int left = 0;
        int right = s.size() - 1;

        // Compare characters from both ends.
        while (left < right) {

            // If characters differ,
            // the number is not a palindrome.
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

```
**Time:** O(d)  ·  **Space:** O(d)  ·  **Why it's slow:** We transformed the numeric palindrome problem into a string palindrome problem. Then we used two pointers from both ends to compare matching digits, at most half the characters. d = number of digits. Therefore: O(d). Since an int has only a fixed number of digits, this is practically constant time, but algorithmically we describe it as: O(log10(x)) with respect to the numeric magnitude. The string representation stores all digits. So Space complexity: O(d) extra space. The problem can be solved mathematically without creating a string. That eliminates the extra O(d) memory.

## Tier 2 — Better
**Idea:** Save the original number. Then reverse all digits mathematically. We repeatedly extract last digit and remove it from the original number. Then keep building the reversed number. Finally: if (original == reversed) true either false.
```cpp
class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers cannot be palindromes.
        if (x < 0) {
            return false;
        }

        // Save the original value
        // because x will be modified.
        int original = x;

        // Use long long so reversing the entire
        // integer cannot overflow int.
        long long reversed = 0;

        while (x > 0) {

            // Extract the last digit.
            int digit = x % 10;

            // Append the digit to reversed.
            reversed = reversed * 10 + digit;

            // Remove the last digit from x.
            x /= 10;
        }

        return original == reversed;
    }
};

```
**Time:** O(d)  ·  **Space:** O(1)  ·  **What improved & why:** We mathematically reversed every digit of the number and compared the reversed number with the original. This removes the string and reduces auxiliary space to O(1).Every iteration removes one digit: x /= 10; and If there are d digits, then T.C.= O(d). We only store: original, reversed, digit. Therefore: O(1) auxiliary space.

## Tier 3 — Advanced/Optimal
**Idea:** For a palindrome: first half == reverse(second half)
So instead of reversing the entire integer, reverse only the last half of its digits.
```cpp
class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers cannot be palindromes.
        if (x < 0) {
            return false;
        }

        // Any non-zero number ending in 0
        // cannot be a palindrome.
        //
        // Example:
        // 10 reversed would be 01 -> 1.
        if (x != 0 && x % 10 == 0) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse only the last half of the number.
        while (x > reversedHalf) {

            // Take the last digit of x
            // and append it to reversedHalf.
            reversedHalf =
                reversedHalf * 10 + x % 10;

            // Remove the last digit from x.
            x /= 10;
        }

        // EVEN number of digits:
        //
        // 1221
        // x = 12
        // reversedHalf = 12
        //
        // ODD number of digits:
        //
        // 12321
        // x = 12
        // reversedHalf = 123
        //
        // Middle digit does not matter,
        // so remove it using / 10.
        return x == reversedHalf ||
               x == reversedHalf / 10;
    }
};

```
**Time:** O(d)  ·  **Space:** O(1)  ·  **Why this is Optimal:** We reversed only the second half of the number instead of reversing the complete integer. Then we compared both halves directly, removing the middle digit for odd-length numbers. More precisely, we process about: d/2 digits. Big-O ignores constants. So T.C.= O(d). Since: d ≈ log10(x), you can also describe this as: O(log x). We use constant auxiliary memory, avoid complete integer reversal, and avoid overflow from reversing the entire number.
The important progression is:
````
String conversion
      ↓
O(d) extra space

Full mathematical reverse
      ↓
O(1) space
but full reversal / overflow concern

Reverse only half
      ↓
O(1) space
+ no full-reversal overflow
+ fewer operations
````

---