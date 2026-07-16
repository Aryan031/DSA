# House Robber (LeetCode 198) - My Approach

## Overview

This problem follows a very similar Dynamic Programming pattern to the Frog Jump problem. Instead of minimizing the cost, the goal here is to **maximize the amount of money** that can be robbed without robbing two adjacent houses.

Rather than memorizing the DP solution directly, I solved it step by step, starting from recursion and gradually optimizing it.

---

## 1. Brute Force (Recursion)

My first instinct was to solve the problem using recursion.

Starting from the **last house**, I considered two choices at every index:

* **Take** the current house.
* **Do not take** the current house.

If I rob the current house, I cannot rob the previous one, so I move to `n-2`.

If I skip the current house, I simply move to `n-1`.

### Base Cases

* If `n == 0`, return `nums[0]`.
* If `n < 0`, return `0`.

### Recursive Transition

```cpp
int take = nums[n] + solve(nums, n - 2);
int notTake = solve(nums, n - 1);

return max(take, notTake);
```

Although this solution is correct, it recalculates the same states multiple times, resulting in **exponential time complexity**.

---

## 2. DP - Memoization

To optimize the recursive solution, I introduced a DP array.

The recursive function now returns the **maximum money that can be robbed considering houses from index `0` to `n`**.

### Base Cases

* If `n == 0`, return `nums[0]`.
* If `n < 0`, return `0`.
* If `dp[n] != -1`, return the already computed answer.

### Recursive Transition

```cpp
int take = nums[n] + solve(nums, n - 2, dp);
int notTake = solve(nums, n - 1, dp);

return dp[n] = max(take, notTake);
```

Since every state is computed only once, the time complexity reduces to **O(n)**.

---

## 3. DP - Tabulation

Once the recursive relation was established, converting it into tabulation became straightforward.

I created a DP array where:

```text
dp[i] = Maximum money that can be robbed considering houses from index 0 to i.
```

I initialized:

```cpp
dp[0] = nums[0];
```

Then I iterated through the array and computed every `dp[i]` using the previously computed states.

For every house:

* **Take** the current house and add `dp[i-2]`.
* **Do not take** the current house and keep `dp[i-1]`.

```cpp
int notTake = dp[i - 1];

int take = nums[i];

if (i > 1)
{
    take = dp[i - 2] + nums[i];
}

dp[i] = max(take, notTake);
```

Finally,

```cpp
return dp[n - 1];
```

contains the maximum amount of money that can be robbed.

---

## 4. Space Optimization

While observing the tabulation solution, I noticed that every state depends only on:

* `dp[i - 1]`
* `dp[i - 2]`

Therefore, storing the entire DP array is unnecessary.

I replaced the DP array with just three variables:

* `i1` → stores `dp[i - 1]`
* `i2` → stores `dp[i - 2]`
* `temp` → stores the current answer

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

The biggest takeaway from this problem was understanding that **Dynamic Programming is all about making decisions at every state**.

At every house, there are only two choices:

```text
Take the current house
        OR
Do not take the current house
```

The optimal answer is simply the maximum of these two choices.

Just like Frog Jump, I derived the solution step by step instead of memorizing it.

```text
Recursion
      ↓
Memoization
      ↓
Tabulation
      ↓
Space Optimization
```

This reinforced an important DP pattern: define the state clearly, express it using previously solved states, and then optimize the solution progressively.