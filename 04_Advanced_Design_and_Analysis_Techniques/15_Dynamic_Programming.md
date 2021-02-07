<style>
b {
    color: slateblue;
}
</style>

# **Dynamic Programming**  

## **INDEX**

1. [Rod cutting](#rod-cutting)
2. [Longest common subsequence](#longest-common-subsequence)

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

**BOTTOM-UP-CUT-ROD(p, n)**
```c
let r[0..n] be a new array
r[0] = 0
for j = 1 to n
    q = -inf
    for i = 1 to j
        q = max(q, p[i] + r[j-i])
    r[j] = q
return r[n]
```

## **Matrix-chain multiplication**  

## **Elements of dynamicprogramming**  

## **Longest common subsequence**  

In the ***longest-common-subsequence problem***, we are given two sequences $X=\langle x_1, x_2, \cdots, x_m\rangle$ and $Y=\langle y_1,y_2,\cdots,y_n\rangle$ and wish to find a maximum length common subsequence of $X$ and $Y$.  

### **Step 1: Characterizing a longest common subsequence**  

The LCS problem has an optimal-substructure property, however, as the following theorem shows. Given a sequence $X=\langle x_1,x_2,\cdots,x_m\rangle$, we define the $i$th ***prefix*** of $X$, for $i=0,1,\cdots,m$, as $X_i=\langle x_1, x_2, \cdots, x_i\rangle$. For example, if $X=\langle A,B,C,B,D,A,B\rangle$, then $X_4=\langle A,B,C,B\rangle$ and $X_0$ is the empty sequence.  

#### ***Theorem 15.1 (Optimal substructure of an LCS)***
Let $X=\langle x_1, x_2,\cdots, x_m\rangle$ and $Y=\langle y_1, y_2,\cdots, y_n\rangle$ be sequences, and let $Z=\langle z_1, z_2,\cdots, z_k\rangle$ be any LCS of $X$ and $Y$.  

1. If $x_m = y_n$, then $z_k = x_m = y_n$ and $Z_{k-1}$ is an LCS of $X_{m-1}$ and $Y_{n-1}$.
2. If $x_m \neq y_n$, then $z_k\neq x_m$ implies that $Z$ is an LCS of $X_{m-1}$ and $Y$.
3. If $x_m \neq y_n$, then $z_k\neq y_n$ implies that $Z$ is an LCS of $X$ and $Y_{n-1}$.  

### **Step 2: A recursive solution**  

$$
c[i, j]=
\begin{cases}
    0 && \text{if } i=0\text{ or }j=0, \\
    c[i-1, j-1] + 1 && \text{if } i,j > 0\text{ and }x_1=y_j, \\
    \max(c[i, j-1], c[i-1, j]) && \text{if } i,j > 0 \text{ and }x_i\neq y_j,
\end{cases}
$$

### **Step 3: Computing the length of an LCS**  

<br>  

**LCS-LENGTH(X, Y)**
```c
m = X.length
n = Y.length
let b[1..m, 1..n] and c[0..m, 0..n] be new tables
for i = 1 to m
    c[i, 0] = 0
for j = 0 to n
    c[0, j] = 0
for i = 1 to m
    for j = 1 to n
        if x_i == y_j
            c[i, j] = c[i-1, j-1]+1
            b[i, j] = "↖"
        else if c[i-1, j] >= c[i, j-1]
            c[i, j] = c[i-1, j]
            b[i, j] = "↑"
        else c[i, j] = c[i, j-1]
            b[i, j] = "←"
return c and b
```

### **Step 4: Constructing an LCS**  

||$y_i$|B|D|C|A|B|A|
|:-:|-:|-:|-:|-:|-:|-:|-:|
$x_i$|0|0|0|0|0|0|0|
A|<b>0|↑ 0|↑ 0|↑ 0|↖ 1|← 1|↖ 1|
B|0|<b>↖ 1|<b>← 1|← 1|↑ 1|↖ 2|← 2|
C|0|↑ 1|↑ 1|<b>↖ 2|<b>← 2|↑ 2|↑ 2|
B|0|↖ 1|↑ 1|↑ 2|↑ 2|<b>↖ 3|← 3|
D|0|↑ 1|↑ 2|↖ 2|↑ 2|<b>↑ 3|↑ 3|
A|0|↑ 1|↑ 2|↑ 2|↖ 3|← 3|<b>↖ 4|
B|0|↖ 1|↑ 2|↑ 2|↑ 3|↖ 4|<b>↑ 4|  
<br>

**PRINT-LCS(b, X, i, j)**
```c
if i == 0 or j == 0
    return
if b[i, j] == "↖"
    PRINT-LCS(b, X, i-1, j-1)
    print x_i
else if b[i ,j] == "↑"
    PRINT-LCS(b, X, i-1, j)
else PRINT-LCS(b, X, i, j-1)
```