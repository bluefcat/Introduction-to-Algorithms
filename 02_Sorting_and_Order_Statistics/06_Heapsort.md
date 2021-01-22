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

To show why **BUILD-MAX-HEAP** works correctly, we use the following loop invariant:  

> At the start of each iteration of the **for** loop of lines 2-3, each node $i+1, i+2, \cdots, n$ is the root of a max-heap  

**Initialization** : Prior to the first iteration of the loop, $i=\lfloor n/2\rfloor$. Each node $\lfloor n/2\rfloor+1, \lfloor n/2\rfloor+2,\cdots,n$ is a leaf and is thus the root of a trivial max-heap.  

**Maintenance** : To see that each iteration maintains the loop invarian, observe that the children of node $i$ are numbered higher than $i$. By the loop invariant, therefore, they are both roots of max-heaps. This is precisely the condtion required the **MAX-HEAPIFY(A, $i$)** call preserves teh property that nodes $i+1, i+2,\cdots,n$ are all roots of max-heaps. Decrementing $i$ in the **for** loop update reestablishes the loop invariant for the next iteration.  

**Termination** : At termination, $i=0$. By the loop invariant, each node $1, 2,\cdots,n$ is the root of a max-heap. In particular, node 1 is.  

Running time of **BUILD-MAX-HEAP** as follows. Each call to **MAX-HEAPIFY** costs $O(\lg n)$ time, and **BUILD-MAX-HEAP** makes $O(n)$ such calls. Thus, the running time is $O(n\lg n)$. This upper bound, though correct, is not asymptotically tight.  

Tight analysis relies on the properties that an $n$-element heap has height $\lfloor\lg n\rfloor$ and at most $\lceil n/2^{h+1}\rceil$ nodes of any height h.  
The time required by **MAX-HEAPIFY** when calle on a node of height $h$ is $O(h)$, and so we can express the total cost of **BUILD-MAX-HEAP** as being bounded from above by  
$$
\begin{aligned}
 \sum^{\lfloor\lg n\rfloor}_{h=0}\lceil \frac{n}{2^{h+1}}\rceil O(h) &= O\left(n\sum^{\lfloor\lg n\rfloor}_{h=0}\frac{h}{2^h}\right) \\
&= O(n) & \because\sum^{\infty}_{h=0}\frac{h}{2^h} = 2   
\end{aligned}
$$  

Hence, we can build a max-heap from an unordered array in linear time.  

## **The heapsort algorithm**

**HEAPSORT(A)**
```c
BUILD-MAX-HEAP(A)
for i = A.length downto 2
    exchange A[1] with A[i]
    A.heap-size = A.heap-size - 1
    MAX-HEAPIFY(A, 1)
```  

The **HEAPSORT** procedure takes time $O(n \lg n)$, since the call to **BUILD-MAX-HEAP** takes time $O(n)$ and each of the $n-1$ calls to **MAX-HEAPIFY** takes time $O(\lg n)$.  

## **Priority queues**  

A **max-priority queue** supports the following operation:  
- **INSERT(S, x)** : insert the element $x$ into the set $S$, which is equivalent to the operation $S = S\cup \{x\}$

- **MAXIMUM(S)** : returns the element of $S$ with the largest key

- **EXTRACT-MAX(S)** : removes and returns the element of $S$ with the largest key  

- **INCREASE-KEY(S, x, k)** : increases the value of element $x$'s key to the new value $k$, which is assumed to be at least as large as $x$'s current key value. 

Alternatively, a min-priority queue spports the operations **INSERT**, **MINIMUM**, **EXTRACT-MIN** and **DECREASE-KEY**.

The procedure **HEAP-MAXIMUM** implements the MAXIMUM operation in $\Theta(1)$ time.  

**HEAP-MAXIMUM(A)**
```c
return A[1]
```  

The running time of **HEAP-EXTRACT-MAX** is $O(\lg n)$, since it performs only a constant amount of work on top of the $O(\lg n)$ time for **MAX-HEAPIFY**.

**HEAP-EXTRACT-MAX(A)**
```c
if A.heap-size < 1
    error "heap underflow"
max = A[1]
A[1] = A[A.heap-size]
A.heap-size = A.heap-size - 1
MAX-HEAPIFY(A, 1)
return max
```

The running time of **HEAP-INCREASE-KEY** on an $n$-element heap is $O(\lg n)$, since the path tradced from the node updated in line 3 to the root has length $O(\lg n)$.

**HEAP-INCREASE-KEY(A, i, key)**
```c
if key < A[i]
    error "new key is smaller than current key"
A[i] = key
while i > 1 and A[PARENT(i)] < A[i]
    exchange A[i] with A[PARENT(i)]
    i = PARENT(i)
```

The running time of **MAX-HEAP-INSERT** on an $n$-element heap is $O(\lg n)$.

**MAX-HEAP-INSERT(A, key)**
```c
A.heap-size = A.heap-size + 1
A[A.heap-size] = -inf
HEAP-INCREASE-KEY(A, A.heap-size, key)
```