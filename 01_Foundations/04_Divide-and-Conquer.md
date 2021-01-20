# Divide and Conquer

**Divide** : The problem into a number of subproblems that are smaller instances of the same problem.  

**Conquer** : The subproblems by solving them recursively. If the subproblem sizes are small enough, however, just solve the subproblems in a straightforward manner.  

**Combine** : The solutions to the subproblems into the solution for the original problem.  

## **Recurrence**  

A recurrence is an equation or inequality that describes a function in terms of its value on smaller inputs. For example, we dscribed the worst-case running time $T(n)$ of the **MERGE-SORT** procedure by the rececurrence
$$
T(n)=
\begin{cases}
\Theta(1) & \text{ if }n=1 \\
2T(n/2)+\Theta(n)&\text{ if }n\gt 1 
\end{cases}
$$  
whose solution we claimed to be $T(n) = \Theta(n\lg n)$  

## **The maximum-subarray problem**  

### **A brute-force solution**  
Just try every posiible pair of buy and sell dates in which the buy date precedes the sell date. A period of $n$ days has $\begin{pmatrix}n\\2\end{pmatrix}$ such pairs of dates. Since $\begin{pmatrix}n\\2\end{pmatrix}$ is $\Theta(n^2)$  

### **A solution using divide-and-conquer**  
Suppose we want to find a maximum subarray of the subarray $A[\text{low}\cdots\text{high}]$  
We find the midpoint, say mid, of the subarray, and consider the subarray $A[\text{low}\cdots\text{mid}]$ and $A[\text{low}\cdots\text{mid}]$
Any contiguous subarray $A[i\cdots j]$ of $A[low\cdots high]$ must lie in exactly one of the following places: 
* entirely in the subarray $A[\text{low}\cdots\text{mid}]$, so that $A[\text{mid}+1\cdots\text{high}]$,

* entirely in the subarray $A[\text{mid}+1\cdots\text{high}]$, so that  $\text{mid}\le i\le j\le \text{high}$

* crossing the midpoint, so that $\text{low}\le i\le\text{mid}\lt j\le\text{high}$.  

**FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)**  
```c
left-sum = -inf
sum = 0
for i = mid down to low
    sum = sum + A[i]
    if sum > left-sum
        left-sum = sum
        max-left = i
right-sum = -inf
sum = 0
for j = mid + 1 to high
    sum = sum + A[j]
    if sum > right-sum
        right-sum = sum
        max-right = j

return (max-left, max-right, left-sum + right-sum)
```

**FIND-MAXIMUM-SUBARRAY(A, low, high)**
```c
if high == low
    return (low, high, A[low])  //base case: only one element
else mid = floor((low+high)/2)
    left-low, left-high, left-sum = FIND-MAXIMUM-SUBARRAY(A, low, mid)
    right-low, right-high, right-sum = FIND-MAXIMUM-SUBARRAY(A, mid+1, high)
    cross-low, cross-high, cross-sum = FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)

    if left-sum >= right-sum and left-sum >= cross-sum
        return (left-low, right-high, right-sum)
    else if right-sum >= left-sum and right-sum >= cross-sum
        return (right-low, right-high, right-sum)
    else return (cross-low, cross-high, cross-sum)
```

### **Analyzing the divide-and-conquer algorithm**  

The base case, when $n=1$, is easy: line 2 takes constant time.
$$
T(1)=\Theta(1)
$$

The recursive case occurs when $n\gt 1$.
$$
\begin{aligned}
T(n)&= \Theta(1) + 2T(n/2)+\Theta(n)+\Theta(1)\\
&=2T(n/2)+\Theta(n)
\end{aligned}
$$

Combine equations gives us a recurrence for the running time $T(n)$ of **FIND-MAXIMUM-SUBARRAY** : 
$$
T(n)=
\begin{cases}
\Theta(1) & \text{ if }n=1\\
2T(n/2)+\Theta(n)&\text{ if }n\gt 1    
\end{cases}
$$

As we shall see from the master method, this recurrence has the solution $T(n)=\Theta(n\lg n)$.

## **Strassen's algorithm for matrix multiplication**  

If $A=(a_{ij})$ and $B=(b_{ij})$ are square $n\times n$ matrices, then in the product $C=A\cdot B$, we define the entry $c_{ij}$  

$c_{ij}=\sum_{k=1}^{n}a_{ik}b_{kj}$  

**SQUARE-MATRIX-MULTIPLY(A, B)**
```c
n = A.rows
let C be a new n*n matrix
for i = 1 to n
    for j = 1 to n
        c_ij = 0
        for k = 1 to n
            c_ij = c_ij + a_ik * b_kj

return C
```

The SQUARE-MATRIX-MULTIPLY procedure takes $\Theta(n^3)$ time.  

### **A simple divide-and-conquer algorithm**  

We assume that $n$ is an exact power of 2 in each of the $n\times n$ matrices. We make this assumption because in each divide step, we will divide $n\times n$ matrices into four $n/2\times n/2$ matrices, and by assuming that $n$ is an exact power of 2, we are guaranteed that as long as $n\ge 2$, the dimension $n/2$ is an integer.  

Suppose that we partition each of $A, B$ and $C$ into four $n/2\times n/2$ matrices  
$$
A=\begin{pmatrix}
A_{11}&A_{12}\\
A_{21}&A_{22} 
\end{pmatrix},\quad
B=\begin{pmatrix}
B_{11}&B_{12}\\
B_{21}&B_{22} 
\end{pmatrix},\quad
C=\begin{pmatrix}
C_{11}&C_{12}\\
C_{21}&C_{22} 
\end{pmatrix}
$$
so that we rewrite the equation $C=A\cdot B$ as  
$$
\begin{pmatrix}
C_{11}&C_{12}\\
C_{21}&C_{22} 
\end{pmatrix}=
\begin{pmatrix}
A_{11}&A_{12}\\
A_{21}&A_{22} 
\end{pmatrix}\cdot
\begin{pmatrix}
B_{11}&B_{12}\\
B_{21}&B_{22} 
\end{pmatrix}
$$
Equation corresponds to the four equations
$$
C_{11}=A_{11}\cdot B_{11}+A_{12}\cdot B_{21}\\
C_{12}=A_{11}\cdot B_{12}+A_{12}\cdot B_{22}\\
C_{21}=A_{21}\cdot B_{11}+A_{22}\cdot B_{21}\\
C_{22}=A_{21}\cdot B_{12}+A_{22}\cdot B_{22}
$$  

**SQUARE-MATRIX-MULTIPLY-RECURSIVE(A, B)**
```c
n = A.rows
let C be a new n*n matrix
if n == 1
    C_11 = A_11*B_11
else partition A, B and C as in equations 
    C_11 = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_11, B_11) + SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_12, B_21)    
    C_12 = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_11, B_12) + SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_12, B_22)    
    C_21 = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_21, B_11) + SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_22, B_21)
    C_22 = SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_21, B_12) + SQUARE-MATRIX-MULTIPLY-RECURSIVE(A_22, B_22)
    return C
```

$$
T(n)=
\begin{cases}
\Theta(1) & \text{ if }n=1\\
8T(n/2)+\Theta(n^2)&\text{ if }n\gt 1    
\end{cases}
$$

$T(n)=\Theta(n^3)$  
