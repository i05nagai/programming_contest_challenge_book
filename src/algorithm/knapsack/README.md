
## Problem

### Large knapsack problem
* $1 \le n \le 40$,
    * number of items
* $1 \le w_{i} \le 10^{15}$,
    * weight of $i$-th item
* $1 \le v_{i} \le 10^{15}$,
    * vlaue of $i$-th item
* $1 \le W \le 10^{15}$,
    * weight limit
* $$J_{1:n} := \{1, \ldots, n\}$$,
* $m := \floor n/2 \rfloor$,

$$
    I \subseteq J_{1:n},
    \
    \bar{w}_{I}
    :=
        \sum_{i \in I}
            w_{i},
    \
    \bar{v}_{I}
    :=
        \sum_{i \in I}
            v_{i},
$$

Suppose that $I^{*}$ is optimal subset.
For $I \subseteq J_{n}$,

$$
    (
        \exists I^{\prime} \subseteq J_{n}
        \text{ s.t. }
        \bar{w}_{I}
        \le
        \bar{w}_{I^{\prime}}
        \land
        \bar{v}_{I}
        \ge
        \bar{v}_{I^{\prime}}
    )
    \implies
    I \not\subseteq I^{*}
    .
$$


$J \subseteq J_{m+1:n}$,

$$
    \max
    \{
       \sum_{i \in I}
           v_{i}
       \mid
       I \subseteq J_{1:n/2},
       \
       \sum_{i \in I}
           w_{i}
        \le
        W
        -
        \bar{w}_{J}
    \}
$$

### Reference
* pp 149
* Section 3-2
