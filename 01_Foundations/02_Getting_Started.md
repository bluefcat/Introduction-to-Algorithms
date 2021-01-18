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

