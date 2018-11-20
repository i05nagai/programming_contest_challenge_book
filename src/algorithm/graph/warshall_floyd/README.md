## Overview

* $O(|V|^{3})$,
    * to solve all minimum shortest paths

* $dp[k+1][i][j]$,
    * the minimum shortest path between $i$ and $j$ using vertices from $0$ to $k$,

$$
    dp[k + 1][i][j]
    =
    \min(
        dp[k][i][k] + d[k][k][j],
        dp[k][i][k]
    )
$$


## Reference
