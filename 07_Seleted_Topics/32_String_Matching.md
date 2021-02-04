# String Matching

|Algorithm|Preprocessing time|Matching time|
|:---|:---:|:---:|
|Native|$0$|$O((n-m+1)m)$|
|Rabin-Karp|$\Theta(m)$|$O((n-m+1)m)$|
|Finite automaton|$O(m\|\Sigma \|)$|$\Theta(n)$|
|Knuth-Morris-Pratt|$\Theta(m)$|$\Theta(n)$|  


## **Notation and terminology**  

We denote by $\Sigma^*$ the set of all finite-length strings formed using characters from the alphabet $\Sigma$.  

The zero-length ***empty-string***, denoted $\epsilon$, also belongs to $\Sigma^*$.  

The length of a string $x$ is denoted $\|x\|$. 

The ***concatenation*** of two strings $x$ and $y$, denoted $xy$, has length $\|x\|+\|y\|$ and consists of the characters from $x$ followed by the characters from $y$.  

---
We say that a string $w$ is a ***prefix*** of a string $x$, denoted $w\sqsubset x$, if $x=wy$ for some string $y\in \Sigma^*$. Note that if $w \sqsubset x$, then $\|w\|\le\|x\|$.  

Similarly, we say that a string $w$ is a ***suffix*** of a string $x$, denoted $w\sqsupset x$, if $x=yw$ for some $y\in \Sigma^*$. As with a prefix, $w\sqsupset x$ implies $\|w\|\le \|x\|$.

The empty string $\epsilon$ is both a suffix and a prefix of every string.  

For any strings $x$ and $y$ and any character $a$, we have $x\sqsupset y$ if and only if $xa\sqsupset ya$.  

---

### ***Lemma 32.1 (Overlapping-suffix lemma)***  
Supposethat $x, y$ and $z$ are strings such that $x\sqsupset z$ and $y\sqsupset z$. If $\|x\|\le\|y\|$, then $x\sqsupset y$. If $\|x\|\ge\|y\|$, then $y\sqsupset x$. If $\|x\|=\|y\|$, then $x=y$.  

---

## **The native string-matching algorithm**  

**NATIVE-STRING-MATCHER(T, P)**
```c
n = T.length
m = P.length
for s = 0 to n-m
    if P[1..m] == T[s+1, s+m]
        print "Pattern occurs with shift"" s
```  

Procedure **NATIVE-STRING-MATCHER** takes time $O((n-m+1)m)$, and this bound is tight in the worst case.  


## **The Rabin-Karp algorithm**  

**RABIN-KARP-MATCHER(T, P, d, q)**
```c
n = T.length
m = P.length
h = d^(m-1) mod q
p = 0
t_0 = 0
for i = 1 to m          //preprocessing
    p = (dp + P[i]) mod q
    t_0 = (dt_0 + T[i]) mod q

for s = 0 to n-m        //matching
    if p == t_s
        if P[1..m] == T[s+1..s+m]
            print "Pattern occurs with shift" s
    
    if s < n-m
        t_{s+1} = (d(t_s-T[s+1]h)+T[s+m+1]) mod q
```  

## **String matching with finite automata**

### **Finite automata**
- $Q$ is a finite set of ***states***
- $q_0\in Q$ is the ***start state***.
- $A\subseteq Q$ is a distinguished set of ***accepting states***.
- $\Sigma$ is a finite ***input alphabet***.
- $\delta$ is a function from $Q\times\Sigma$ into $Q$, called the ***transition function*** of $M$.  

the finite automaton begins in state $q_0$ and readsthe characters of its input string one at a time. If the automaton is in state $q$ to state $\delta(q, a)$. If the automaton is in state $q$ and reads input character $a$, it moves from state $q$ to state $\delta(q, a)$. Whenever its current state $q$ is a member of $A$, the machine $M$ has ***accepted*** the string read so far. An input that is not accepted is ***rejected***.  

A finite automaton $M$ induces a function $\phi$, called the ***final-state function***, from $\Sigma^*$ to $Q$ such that $\phi(w)$  is the state $M$ ends up in after scanning the string $w$. Thus, $M$ accepts a string $w$ if and only if $\phi(w)\in A$. We define the function $\phi$ recursively, using the transition function:  

$\begin{aligned}\phi(\epsilon) &= q_0\\\phi(wa) &= \delta(\phi(w), a)\text{ for }w\in \Sigma^*, a\in \Sigma \end{aligned}$  

### **String-matching automata**  
In order to specify the string-matching automaton corresponding to a given pattern $P[1\cdots m]$, we first define an auxiliary function $\sigma$, called the ***suffix function*** corresponding to $P$. The function $\sigma$ maps $\Sigma^*$ to $\{0, 1, \cdots, m\}$ such that $\sigma(x)$ is the length of the longest prefix of $P$ that is also a suffix of x :  

$\sigma(x) = \max\{k:P_k \sqsupset x\}$  

- The state set $Q$ is $\{0, 1, \cdots, m\}$. The start state $q_0$ is state0, and state $m$ is the only accepting state.  
- The transition function $\delta$ is defined by the following equation, for any state $q$ and character $a$:  
  $\delta(q, a) =\sigma(P_qa)$.  

**FINITE-AUTOMATON-MATCHER(T, d, m)**
```c
n = T.length
q = 0
for i = 1 to n
    q = d(q, T[i])
    if q == m
        print "Pattern occurs with shift" i-m
```  

**COMPUTE-TRANSITION-FUNCTION(P, s)**
```c
m = P.length
for q = 0 to m
    for each character a \in s
        k = min(m+1, q+2)
        repeat
            k = k-1
        until P_k \sqsupset P_q a
        d(q, a) = k
return d
```
