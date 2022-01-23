

## Domino

i      2 2 2 1 1 1 0 0 0
j      2 1 0 2 1 0 2 1 0
000: 1 0 1 0 1 1 0 1 0 2
001: 0 0 0 1 0 0 1 0 1 0
010: 0 0 0 0 0 1 0 1 1 0
011: 0 0 0 0 1 0 1 0 0 1
100: 0 1 0 1 0 0 1 0 0 0
101: 0 0 0 0 1 1 0 1 0 0
110: 0 0 1 0 0 0 1 0 0 1
111: 0 0 0 1 0 1 0 1 1 0


## Color Blocks

- a_{i}: the num of patterns to paint even num of blocks with red and green respectively up to i-th block
- b_{i}: the num of patterns to paint even num of blocks with one of colors: red and green, and odd num of blocks with the other color
- c_{i}: the num of patterns to paint odd num of blocks with red and green

a_{i+1} = 2xa_{i} + b_{i}
b_{i+1} = 2xa_{i} + 2xb_{i} + 2xc_{i}
c_{i+1} = b_{i} + 2xc_{i}
