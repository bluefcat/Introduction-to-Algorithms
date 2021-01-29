# Elementary Data Structures  

## **Stacks and queues** 

Stack and queues are dynamic sets in which the element removed from the set by the DELETE operation is prespecified.  

In a **stack**, the element deleted from the set is the one most recently inserted: the stack implements a **last-in, first-out**, or ***LIFO***, policy.  
Similarly, in a **queue**, the element deleted is always the ine that has been in the set for the longest time: the queue implements a **first-in, first-out**, or ***FIFO***, policy.  

### **Stacks**  

The INSERT operation on a stack is often called PUSH, and the DELETE operation, which does not take an element argument, is often called POP.  

**STACK-EMPTY(S)**  
```c
if S.top == 0
    return TRUE
else return FALSE
```

**PUSH(S, x)**
```c
S.top = S.top + 1
S[S.top] = x
```

**POP(S)**
```c
if STACK-EMPTY(S)
    error "underflow"
else S.top = S.top - 1
    return S[S.top + 1]
```

Each of the three stack operations takes $O(1)$ time.

### **Queues**  

We call the INSERT operation on a queue ENQUEUE, and we call the DELETE operation DEQUEUE; like the stack operation POP, DEQUEUE takes no element argument.  

**ENQUEUE(Q, x)**
```c
Q[Q.tail] = x
if Q.tail == Q.length
    Q.tail = 1
else Q.tail = Q.tail + 1
```

**DEQUEUE(Q)**
```c
x = Q[Q.head]
if Q.head == Q.length
    Q.head = 1
else Q.head = Q.head + 1
return x
```

Each operation takes $O(1)$ time.

## **Linked lists**

A linked list is a data structure in which the objects are arranged in a linear order. Unlike an array, however, in which the linear order is determined by the array indices, the orderin a linked list is determined by a pointer in each object.  

### **Searching a linked list**  

The procedure **LIST-SEARCH(L, k)** finds the first element with key $k$ in list $L$ by a simple linear search, returning a pointer to this element. If no object with key $k$ appears in the list, then the procedure returns NIL.  

**LIST-SEARCH(L, k)**
```c
x = L.head
while x != NIL and x.key != k
    x = x.next
return x
```  
To search a list of $n$ objects, the **LIST-SEARCH** procedure takes $\Theta(n)$ time in the worst case, since it may have to search the entire list.  

### **Inserting into a linked list**  

Given an element $x$ whose *key* attribute has already been set, the **LIST-INSERT** procedure "splices" $x$ onto the front of the linked list.  

**LIST-INSERT(L, x)**
```c
x.next = L.head
if L.head != NIL
    L.head.prev = x
L.head = x
x.prev = NIL
```

The running time for **LIST-INSERT** on a list of $n$ elements is $O(1)$.  

### **Deleting from a linked list**  

The procedure **LIST-DELETE** removes an element $x$ from a linked list $L$.  

**LIST-DELETE(L, x)**
```c
x = LIST-SEARCH(L, x)
if x.prev != NIL
    x.prev.next = x.next
else L.head = x.next
if x.next != NIL
    x.next.prev = x.prev
```  

**LIST-DELETE** runs in $O(1)$ time, but if we wish to delete an element with a given key, $\Theta(n)$ time is required in the worst case because we must first call **LIST-SEARCH** to find the element.
