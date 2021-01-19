# Getting Started

## **Insertion sort**

Insertion sort, solves the **sorting problem**.
|||
|-|-|
|**Input**| A sequence of $n$ numbers $\langle a_1,a_2,\cdots,a_n\rangle$|
|**output**|A permutation (reordering) $\langle a_1',a_2',\cdots,a_n'\rangle$ of the input sequence such that $a_1'\le a_2'\le \cdots\le a_n'$  

(The numbers that we wish to sort are also known as the key.)  
<br></br>
**INSERTION-SORT(A)**  
```c
for j = 2 to A.length
    key = A[j]
    // Insert A[j] into the sorted sequence A[1 ... j - 1]
    i = j - 1
    while i > 0 and A[i] > key
        A[i + 1] = A[i]
        i = i - 1
    A[i + 1] = key
```

### **Loop invariants and the correctness of insertion sort**

**loop invariant** :  
> At the start of each iteration of the **for** loop of line 1-8, the subarray $A[1 \cdots j-1]$ consists of the elements originally in $A[1 \cdots j-1]$, but in sorted order.  

---
We must show three things about a loop invariant:  

**Initalization** : It is true prior to the first iteration of the loop.

**Maintenance** : If it is true before an iteration of the loop, it remains true before the next iteration.  

*(Note the similarity to mathematical induction)*

**Termination** : When the loop terminates, the invariant gives us a useful property that helps show that the algorithm is correct.  

---

**Initalization** :  
> When $j=2$, The subarray $A = [1 \cdots j-1]$ consists of just the single element $A[1]$,  
> which is in fact the original element in $A[1]$. And this subarray is sorted.  
> Shows that the loop invariant holds prior to the first iteration of the loop.  

**Maintenance** :
> The body of the for loop works by moving $A[j-1], A[j-2], A[j-3]$,  
> and so on by one position to the right until it finds the proper position for $A[j]$,   
> at which point it inserts the value of $A[j]$.  
> The subarray $A[1\cdots j]$ then consists of the elements originally in $A[1\cdots j]$, but in sorted order.  
> Incrementing j for the next iteration of the **for** loop then preserves tohe loop invariant.  

**Termination** : 
> The condition causing the **for** loop to terminate is that $j > \text{A.length} = n$  
> Substituting $n+1$ for $j$ in ther wording of loop invariant,  
> we have that the subarray $A[1\cdots n]$ consists of the elements originally in $A[1 \cdots n]$,  
> but in sorted order.  
> Observing that the subarray $A[1\cdots n]$ is the entire array, we conclude that entire array is sorted, Hence, the algorithm is correct  

## **Analyzing algorithms**  

Predictiong the resources that the algorithm requires. Most often it is computational time that we want to measure.  

### **Analysis of insertion sort**

**input size** : Notion for input size depends on the problem being studied.
- Problem, such as sorting or computing discrete Fourier transforms, the most natural measure is the number of items in the input.
  - ex) the array size $n$ for sorting.

- Problem, such as multiplying two integers, the best measure of input size is the total number of bits needed to represent the input in ordinary binary notation.

- If the input to an algorithm is a graph, the input size can be described by the numbers of vertices and edges in the graph.

**running time** : The number of primitive operations or "steps" executed.

- We shall assume that eache execution of the $i$th line takes time $c_i$, where $c_i$ is a constant.

<img src="./insertion_sort_analysis.png" alt="cost analysis of insertion sort" width=600 height=250></img>

$$
T(n) = c_1n+c_2(n-1)+c_4(n-1)+c_5\sum_{j=2}^n t_j+c_6\sum_{j=2}^n (t_j-1)+c_7\sum_{j=2}^n (t_j-1)+c_8(n-1)
$$  

In Insertion-sort, the best case occurs if the array is already sorted.  

$$
\begin{aligned}
T(n) &= c_1n+c_2(n-1)+c_4(n-1)+c_5(n-1)+c_8(n-1)\\
&= (c_1+c_2+c_4+c_5+c_8)n - (c_2+c_4+c_5+c_8) 
\end{aligned}
$$  
We can express this running time as $an+b$ for constants $a$ and $b$  
that depend on the statement costs $c_i$; it is thus a ***linear function*** of $n$  

If the array is in reverse sorted order ther worst case results.

$$
\sum_{j=2}^n j=\frac{n(n+1)}{2}-1\\\;\\
\sum_{j=2}^n(j-1)=\frac{n(n-1)}{2}
$$  

$$
\begin{aligned}
T(n) &= c_1n+c_2(n-1)+c_4(n-1)+c_5\left(\frac{n(n+1)}{2}-1\right)+c_6\left(\frac{n(n-1)}{2}\right)+c_7\left(\frac{n(n-1)}{2}\right)+c_8(n-1)\\
&= \left(\frac{c_5}2+\frac{c_6}2+\frac{c_7}2\right)n^2+(c_1+c_2+c_4+\frac{c_5}2-\frac{c_6}2-\frac{c_7}2+c_8)n - (c_2+c_4+c_5+c_8) 
\end{aligned}
$$  

We can express this worst-case running time as $an^2+bn+c$ for constants $a, b$ and $c$ that again depend on the statement costs $c_i$; it is thus a ***quadratic function*** of $n$

### **Worst-case and average-case analysis**  

- The worst-case running time of an algorithm gives us an **upper bound** on the running time for any input  

## **Designing algorithm**  

### **The divide-and-conquer approach**  

The divide and conquer paradigm involves three steps at each level of the recursion :  

- **Divide** : the problem into a number of subproblems that are smaller instances of the same problem  
  
- **Conquer** : the subproblems by solving them recursively. If the subproblem sizes are small enough, however, just slve the subproblems in a straightforward manner.  

- **Combine** : the solutions to the subproblems into the solution for the original problem.  

The ***merge sort*** algorithm closely follows the divide and conquer paradigm. Intuitively, it operates as follows.

- **Divide** : Divide the $n$-element sequence to be sorted into two subsequences of $\frac{n}2$ elements each.
  
- **Conquer** : Sort the two subsequences recursively using merge sort.
  
- **Combine** : Merge the two sorted subsequences to produce the sorted answer.  

The recursion "bottoms out" when the sequence to be sorted has length 1, in which case there is no work to be done, since every sequence of length 1 is already in sorted order.  

$A[p\cdots q]$ and $A[q+1\cdots r]$ are in sorted order. It ***merges*** them to form a single sorted subarray that replaces the current subarray $A[p\cdots r]$. ($\;p\le q \lt r$  )

**MERGE(A, p, q, r)**
```c
n_1 = q - p + 1
n_2 = r - q
let L[1...n_1+1] and R[1...n_2+1] be new arrays

for i = 1 to n_1
    L[i] = A[p+i-1]

for j = 1 to n_2
    R[j] = A[q + j]

L[n_1+1] = inf
R[n_2+1] = inf
i = 1
j = 1

for k = p to r
    if L[i] <= R[j]
        A[k] = L[i]
        i = i + 1

    else 
        A[k] = R[j]
        j = j + 1
```

**loop invariant** : At the start of each iteration of the **for** loop of lines 12-17 the subarray $A[p\cdots k-1]$ contains the $k-p$ smallest elements of $L[1\cdots n_1+1]$ and $R[1\cdots n_2+1]$, in sorted order. Moreover, $L[i]$ and $R[i]$ are the smallest elements of their arrays that have not been copied back into $A$.  

- **Initialization** : Piror to the first iteration of the loop, we have $k=p$, so that the subarray $A[p\cdots k-1]$ is empty. This empty subarray contains the $k-p=0$ smallest elements of $L$ and $R$ and since $i=j=1$, both $L[i]$ and $R[j]$ are the smallest elements of their arrays that have not been copied back into $A$

- **Maintenance** : Let us first suppose that $L[i]\le R[j]$. Then $L[i]$ is the smallest element not yet copied back into $A$. Incrementing $k$ and $i$ reestablishes the loop invariant for the next iteration.
  
- **Termination** : At termination, $k=r+1$. By the loop invariant, the subarray $A[p\cdots k-1]$, which is $A[p\cdots r]$, contains the $k-p=r-p+1$ smallest elements of $L[1\cdots n_1+1]$ and $R[1\cdots n_2+1]$, in sorted order. The arrays $L$ and $R$ together contain $n_1+n_2+2=r-p+3$ elements. All but the two largest have been copied back into $A$, and these two largest elements are the sentinels.  

**MERGE** procedure runs in $O(n)$ time.  

**MERGE-SORT(A, p, r)**
```c
if p < r
    q = floor((p+r)/2)
    MERGE-SORT(A, p, q)
    MERGE-SORT(A, q+1, r)
    MERGE(A, p, q, r)
```

### **Analyzing divide-and-conquer algorithms**  

We let $T(n)$ be the running time on a problem of size $n$. If the problem size is small enough, say $n\le c$ for some constant $c$, the straightforward solution takes constant time, which we write as $\Theta(1)$.  
Suppose that our division of the problem yields $a$ subproblems, each of which is $1/b$ the size of the original. It takes time $T(n/b)$ to solve one subproblem of size $n/b$, and so it takes time $aT(n/b)$ to solve $a$ of them.  
If we take $D(n)$ time to divide the problem into subproblems and $C(n)$ time to combine the solutions to the subproblems into the solution to the original problem, we get the recurrence

$$
T(n)=
\begin{cases}
\Theta(1) & \text{if } n\le c\\
aT(n/b)+D(n)+C(n)&\text{otherwise}
\end{cases}
$$  

#### **Analysis of merge sort**  

- **Divide** : The divide step hust computes the middle of the subarray, which takes constant time. Thus $D(n)=\Theta(n)$  

- **Conquer** : We recursively solve two subproblems, each of size $n/2$ which contributes $2T(n/2)$ to the running time.

- **Combine** : We have already noted that the **Merge** procedure on an $n$-element subarray takes time $\Theta(n)$, and so $C(n)=\Theta(n)$  

$$

\begin{aligned}
T(n) &=
\begin{cases}
\Theta(1) & \text{if } n=1\\
2T(n/2)+\Theta(n) & \text{if } n\gt 1
\end{cases}\\
&=
\begin{cases}
c & \text{if } n=1\\
2T(n/2) + cn & \text{if } n\gt 1
\end{cases}
\end{aligned}
$$  

For convenience, we assume that $n$ is an exact $2^x$

$$
T(n)=2\,T\left(\frac{n}{2} \right)+cn \\ \; \\
T(n/2)=2\,T\left(\frac{n}{4} \right)+cn \\ \; \\
\begin{aligned}
T(n)&=2\left(2\,T\left(\frac{n}{4} \right)+\frac{cn}{2}\right)+cn \\
&=2\left(2\cdots \left(2\,T\left(\frac{n}{2^x}\right)+\frac{cn}{2^{x-1}}\right)\cdots +\frac{cn}{2}\right)+cn\\
&=2^xc+\sum_{i=0}^{x-1}cn\\
&=2^xc+cnx\\
&=nc+cn\lg n & \because n=2^x
\end{aligned}
$$