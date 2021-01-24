# Quicksort

The quicksort algorithm has worst-case running time of $\Theta(n^2)$ on an input array of $n$ numbers. Despite this slow worst-case running time, quicksort is often the best practical choice for sorting because it is remarkably efficient on the average: its expected running time is $\Theta(n\lg n)$, and tge constant factors hidden in the $\Theta(n\lg n)$ notation are quite small.  

## Description of quicksort  

**Divide** : Partition (rearrange) the array $A[p\cdots r] into the (possibly empty) subarrays $A[p\cdots q-1]$ and $A[q+1\cdots r]$ such that each element of $A[p\cdots q-1]$ is less than or equal to $A[q]$, which is ,in turn, less than or equal to each element of $A[q+1\cdots r]$.  

**Conquer** : Sort the two subarrays $A[p\cdots q-1]$ and $A[q+1\cdots r]$ by recursive calls to quicksort.  

**Conquer** : Sort the two subarrays $A[p\cdots q-1]$ and $A[q+1\cdots r]$ by recursive calls to quicksort.  

**Combine** : Because the subarrays are already sorted, no work is needed to combine them: the entire array $A[p\cdots r]$ is now sorted.  

**QUICKSORT(A, p, r)**  
```c
if p < r
    q = PARTITION(A, p, r)
    QUICKSORT(A, p, q-1)
    QUICKSORT(A, q+1, r)
```

**PARTITION(A, p, r)**
```c
x = A[r]
i = p-1
for j = p to r-1
    if A[j] <= x
        i = i+1
        exchange A[i] with A[j]
exchange A[i+1] with A[r]
return i+1
```  

**Initialization** : Prior to the first iteration of the loop, $i=p-1$ and $j=p$. Because no values lie between $p$ and $i$ and no values lie between $i+1$ and $j-1$, ther first two conditions of the loop invariant are trivially satisfied. The assignment in line 1 satisfies the third condition.  

**Maintenance** :  We consider two cases, depending on the outcome of the test in line 4. When $A[j]\gt x$; the only action in the loop is to increment $j$. After $j$ is incremented, condition 2 holds for $A[j-1]$ and all other entries remain unchanged. When $A[j]\le x$; the loop increment $i$ swaps $A[i]$ and $A[j]$, and then increments $j$. Because of the swap, we now have that $A[i]\le x$, and condition 1 is satisfied. Similarly, we also have that $A[j-1]\gt x$, since the item that was swapped into $A[j-1]$ is, by the loop invariant, greater than $x$.

**Termination** : At termination, $j=r$. Therefore, every entry array is in one of  the three sets described by the invariant, and we have partitioned the values in the array into three sets: those less than or equal to $x$, those greater than $x$, and a singleton set containing $x$ 

