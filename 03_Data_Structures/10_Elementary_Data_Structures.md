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