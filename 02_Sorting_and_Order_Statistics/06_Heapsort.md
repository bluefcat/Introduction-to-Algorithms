# Heapsort  

Like merge sort, but unlike insertion sort, heapsort's running time is $O(n\lg n)$. Like insertion sort, but unlike merge sort, heapsort sorts in place: only a constant number of array elements are stored outside the input array at any time.  

## **Heaps**  
The (***binary***) **heap** data structure is an array object that we can view as a nearly complete binary tree. Each node of the tree corresponds to an element of the array. The tree is completely filled on all levels except possibly the lowest, which is filled from the left up to a point. 

**PARENT(i)**
```c
return floor(i/2)
```
**LEFT(i)**
```c
return 2*i
```

**PARENT(i)**
```c
return 2*i+1
```

In a **max-heap**, the **max-heap property** is that for every node $i$ other than the root,  

$A[\text{PARENT}(i)]\ge A[i]$  

that is, the value of a node is at nost the value of its parent.  

A **min-heap** is organized in the opposite way; the **min-heap property** is that for every node $i$ other than the root,  

$A[\text{PARENT}(i)]\le A[i]$  

The smallest element in a min-heap is at the root.  
Since a heap of $n$ elements is based on a complete binary tree, its height is $\Theta(\lg n)$.  

## **Maintaining the heap property**  

**MAX-HEAPIFY(A, i)**
```c
l = LEFT(i)
r = RIGHT(i)

if l <= A.heap-size and A[l] > A[i]
    largest = l
else largest = i
if r <= A.heap-size and A[r] > A[largest]
    largest = r
if largest != i
    exchange A[i] with A[largest]
    MAX-HEAPIFY(A, largest)
```  

Ther children's subtrees each have size at most $2n/3$-the wort case occurs when the bottom level of the tree is exactly half full-and therefore we can describe the running time of **MAX-HEAPIFY** by the recurrence  
$T(n)\le T(2n/3)+\Theta(1)$.  

The solution to this recurrence is $T(n)=O(\lg n)$. Alternatively, we can characterize the running time of **MAX-HEAPIFY** on a node of height $h$ as $O(h)$.  

## **Building a heap**  

We can use the procedure **MAX-HEAPIFY** in a bottom-up manner to convert an $A[1\cdot n]$, where $n=A.\text{length}$, into a max-heap.

**BUILD-MAX-HEAP(A)**  
```c
A.heap-size = A.length
for i = floor(A.length/2) downto 1
    MAX-HEAPIFY(A, i)
```

