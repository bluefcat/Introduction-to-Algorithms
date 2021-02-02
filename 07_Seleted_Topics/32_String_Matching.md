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