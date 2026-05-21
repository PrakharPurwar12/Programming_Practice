# Check if All Bits Set

## Question
Given a number `n`, check whether every bit in the binary representation of the given number is set or not.

Return `true` if yes, otherwise `false`.

### Examples
- Input: `n = 7`
  - Output: `true`
  - Explanation: Binary for `7` is `111`, all bits are set.
- Input: `n = 8`
  - Output: `false`
  - Explanation: Binary for `8` is `1000`, not all bits are set.
- Input: `n = 0`
  - Output: `false`
  - Explanation: All bits are `0`.

### Constraints
- `0 ≤ n ≤ 10^5`

## Approach
1. Convert the number `n` to its binary form or use bitwise logic.
2. A number has all bits set if it is of the form `2^k - 1` (for example: `1`, `3`, `7`, `15`, ...).
3. Use the check `n & (n + 1) == 0` for `n > 0`, because numbers with all bits set satisfy this property.
4. If `n` is `0`, return `false`.

This approach runs in constant time `O(1)` and does not require iterating over individual bits.