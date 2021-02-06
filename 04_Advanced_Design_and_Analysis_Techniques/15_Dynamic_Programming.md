# **Dynamic Programming**  

## **Rod cutting**  

Serling Enterprises buys long steel rods and cuts them into shorter rods, which it then sells. Each cut is free. The management of Serling Enterprises wants to know the best way to cut up the rods.  
We assume that we know, for $i=1,2,\cdots,$ the price $p_i$ in dollars that Serling Enterprises chares for a rod of length $i$ inches. Rod lengths are always an integral number of inches.  

|length $i$|1|2|3|4|5|6|7|8|9|10|
|:---|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|Price $p_i$|1|5|8|9|10|17|17|20|24|30|   

The **rod-cutting problem** is the following. Given a rod of length $n$ inches and a table of prices $p_i$ for $i=1,2,\cdots, n$, determine the maximum revenue $r_n$ obtainable by cutting up the rod and selling the pieces.  

Consider the case when $n=4$. We see that cutting a 4-inch rod into two 2-inch pieces produces revenue $p_2+p_2 = 5+5 = 10$, which is optimal.  

$r_n = \max_{1\le i\le n}(p_i + r_{n-i})$  

### **Recursive top-down implementation**  

**CUT-ROD(p, n)**
```c
if n == 0
    return 0
q = -inf
for i = 1 to n
    q = max(q, p[i] + CUT-ROD(p, n-i))
return q
```  

To analyze the running time of **CUT-ROD**, let $T(n)$ denote the total number of calls made to **CUT-ROD** when called with its second parameter equal to $n$. this expression equals the number of nodes in a subtree whose root is labeled $n$ in the recursion tree. The count includes the initial call at its root. Thus, $T(0)=1$ and  

$$\begin{aligned}
    T(n)&=1+\sum^{n-1}_{j=0}T(j) \\
    &=2^n
\end{aligned}$$  

and so the running time of **CUT-ROD** is exponential in $n$.

### **Using dynamic programming for optimal rod cutting**  

**MEMOIZED-CUT-ROD(p, n)**
```c
let r[0..n] be a new array
for i = 0 to n
    r[i] = -inf
return MEMOIZED-CUT-ROD-AUX(p, n, r)
```

**MEMOIZED-CUT-ROD-AUX(p, n, r)**
```c
if r[n] >= 0
    return r[n]
if n == 0
    q = 0
else q = -inf
    for i = 1 to n
        q = max(q, p[i] + MEMOIZED-CUT-ROD-AUX(p, n-i, r))
r[n] = q
return q
```