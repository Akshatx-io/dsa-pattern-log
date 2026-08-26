# LEETCODE PROFILE-> [Akshatx-io](https://leetcode.com/u/Akshatx-io/)

## PATTERNS:-

## 1 — Nested Loops
**Idea:** Try every possible combination / pair.

**Pattern Recognition:**
- Need to check every pair / combination.
- No obvious way to eliminate candidates.
- Use as the baseline solution before optimizing.

### Template
```cpp
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        // Check current pair / combination

        if (/* condition */)
        {
            return /* answer */;
        }
    }
}
```
**Mental Trigger:**
````
"Try every possible pair."
        ↓
Nested Loops
````

---

## 2 — Two Pointers
**Idea:** Maintain two pointers and move one of them based on the current condition.

**Pattern Recognition:**
- Array is sorted / can be sorted.
- Working with pairs, ranges, or opposite ends.
- Current result tells you which pointer can be safely moved.
- Common for pair-sum and target problems.

### Template
**Opposite-Direction:**
```cpp
int left = 0;
int right = n - 1;

while (left < right)
{
    // Calculate current state
    int current = /* expression using left and right */;

    if (/* found answer */)
    {
        return /* answer */;
    }
    else if (/* need larger value / sum */)
    {
        left++;
    }
    else
    {
        right--;
    }
}
```

**Pair Sum:**
```cpp
int left = 0;
int right = n - 1;

while (left < right)
{
    int sum = arr[left] + arr[right];

    if (sum == target)
    {
        return /* answer */;
    }
    else if (sum < target)
    {
        left++;
    }
    else
    {
        right--;
    }
}
```

**Mental Trigger:**
````
Sorted Array
     +
Pair / Range
     +
Can eliminate candidates
        ↓
   Two Pointers
````

---

## 3 — HashMap / HashSet Complement
**Idea:** For the current value, calculate what value is required and check whether it has already been seen.
Complement = Target - Current

**Pattern Recognition:**
- Need a pair satisfying a target condition.
- Need fast lookup of a previously seen value.
- Array is unsorted.
- Want to improve O(n²) search to O(n) average.

### Template
**HashMap — One Pass:**
```cpp
unordered_map<int, int> mp;

for (int i = 0; i < n; i++)
{
    int complement = target - nums[i];

    if (mp.count(complement))
    {
        return {mp[complement], i};
    }

    mp[nums[i]] = i;
}
```

**HashSet Version:** Use when you only need to know whether a value exists, not its index/frequency.
```cpp
unordered_set<int> st;

for (int x : nums)
{
    int complement = target - x;

    if (st.count(complement))
    {
        return /* answer */;
    }

    st.insert(x);
}
```

**Mental Trigger:**
````
Need a pair
     ↓
What do I need for current?
     ↓
Complement = Target - Current
     ↓
Have I seen it?
     ↓
HashMap / HashSet
````

---

## 4 — Prefix Sum
**Idea:** A prefix sum stores the cumulative result from the beginning of the array up to the current position.

**Pattern Recognition:**
- sum of elements from index 0 to i / cumulative sum
- Prefix Sum

### Template
```cpp
vector<int> prefix(n);

prefix[0] = arr_name[0];

for (int i = 1; i < n; i++)
{
    prefix[i] = prefix[i - 1] + arr_name[i];
}
```
**Mental Trigger:**
````
Current answer
      ↓
Previous answer + Current element
      ↓
Prefix Sum / Running Sum
````

---

