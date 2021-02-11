# Multithreaded Algorithms

In this chapter, we shall extend our algoruthmic model to encompass parallel algorithms, which can run on multiprocessor computer that permits multiple instructions to execute concurrently.  

**Dynamic multithreaded programming**  
Dynamic multithreading allows programmers to specify parallelism in applications with out worrying about communication protocols, load balancing, and other vagarues of static-thread programming. 

## The basic of dynamic multithreading  

$$
\begin{aligned}
F_0 &= 0, \\
F_1 &= 1, \\
F_i &= F_{i-1} + F_{i-2} && \text{ for } i \ge 2.
\end{aligned}
$$  

**FIB(n)**
```c
if n <= 1
    return n
else x = FIB(n-1)
    y = FIB(n-2)
    return x+y
```

$$
\begin{aligned}
T(n) &\le (aF_{n-1}-b)+(aF_{n-2}-b)+\Theta(1) \\
&= a(F_{n-1}+F_{n-2})-2b+\Theta(1) \\
&= aF_n - b -(b-\Theta(1)) \\
&\le aF_n - b
\end{aligned}
$$  

if we choose $b$ large enough to dominate the constant in the $\Theta(1)$. We can then choose $a$ large enough to satisfy the initial condition. The analytical bound.  

$$
\begin{aligned}
T(n) = \Theta(\phi^n) && \phi = \frac{1+\sqrt{5}}{2}
\end{aligned}
$$  

**P-FIB(n)**
```c
if n <= 1
    return n
else x = spawn P-FIB(n-1)
    y = P-FIB(n-2)
    sync
    return x+y
```