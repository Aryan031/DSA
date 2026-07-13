# Frog Jump - My Approach

## Overview

This is one of the most basic Dynamic Programming problems. Instead of directly memorizing the DP solution, I solved it in multiple stages to understand how Dynamic Programming is derived from recursion.

---

## 1. Brute Force (Recursion)

Since I come from a recursion background, my first instinct was to solve the problem recursively.

I started from the **last index** and explored two possible jumps at every step:

* A **single jump** (`n-1`)
* A **double jump** (`n-2`)

I maintained a `cost` variable that stored the total cost accumulated so far.

Whenever I reached the `0`th index, I compared the current cost with the minimum cost found so far (`finalCost`) and updated it if the current path was better.

Although this approach works correctly, it recalculates the same states multiple times, resulting in **exponential time complexity**.

---

## 2. DP - Memoization

To optimize the recursive solution, I converted it into a memoized DP solution.

Instead of carrying the accumulated `cost` throughout the recursion, I changed the recursive function so that it **returns the minimum cost required to reach index `n`**.

### Base Cases

* If `n == 0`, return `0`.
* If `dp[n] != -1`, return the already computed answer.

### Recursive Transition

Compute the cost of reaching the current index from:

* Index `n-1`
* Index `n-2` (only if `n >= 2`)

```cpp
int first = solve(height, n - 1, dp)
            + abs(height[n] - height[n - 1]);

int second = INT_MAX;

if (n >= 2) {
    second = solve(height, n - 2, dp)
             + abs(height[n] - height[n - 2]);
}

dp[n] = min(first, second);
return dp[n];
```

This optimization ensures that every state is computed only once.

---

## 3. DP - Tabulation

After deriving the recursive relation, converting it into tabulation became straightforward.

I created a DP array where:

```text
dp[i] = Minimum cost required to reach index i
```

I initialized:

```cpp
dp[0] = 0;
```

Then I iterated through the array only once and filled each `dp[i]` using the previously computed values.

Finally,

```cpp
return dp[n - 1];
```

contains the answer.

---

## 4. Space Optimization

While observing the tabulation solution, I noticed that each state depends only on:

* `dp[i - 1]`
* `dp[i - 2]`

Therefore, storing the entire DP array is unnecessary.

I replaced the DP array with just three variables:

* `prev1` → stores `dp[i - 1]`
* `prev2` → stores `dp[i - 2]`
* `curr` → stores the current answer

This reduced the space complexity from **O(n)** to **O(1)** while keeping the time complexity **O(n)**.

---

# Complexity Analysis

| Approach           | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Recursion          | O(2ⁿ)           | O(n)             |
| Memoization        | O(n)            | O(n)             |
| Tabulation         | O(n)            | O(n)             |
| Space Optimized DP | O(n)            | O(1)             |

---

# Key Learning

The biggest takeaway from this problem was understanding how to derive a Dynamic Programming solution instead of memorizing it.

```text
Recursion
      ↓
Memoization
      ↓
Tabulation
      ↓
Space Optimization
```

This approach helped me understand **why** each optimization works and will make solving future DP problems much more intuitive.