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