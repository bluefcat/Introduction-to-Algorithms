# Growth of Function  

We can determine the exact running time of an algorithm.  
The extra precision is not usually worth the effort of computing it  
For large enough inputs, running time are dominated by the effects of the input size itself.  

## **Asymptotic notation**

### **$\Theta$-notation**  
For a given function $g(n)$, we denote by $\Theta(g(n))$ the set of functions  
$$
\Theta(g(n))=\left\{f(n):\text{ there exist positive constants }c_1,c_2\text{ and }n_0\text{ s.t }0\le c_1g(n)\le f(n)\le c_2g(n)\text{ for all }n\ge n_0\right\}
$$  
A function $f(n)$ belongs to the set $\Theta(g(n))$ if there exist positive constants $c_1$ and $c_2$ such that it can be ***sandwiched*** between $c_1g(n)$ and $c_2g(n)$, for sufficiently large $n$.  
We will usually write "$f(n)=\Theta(g(n))$"  

Let us briefly justify this intuition by using the formal definition to show that $\frac1{2}n^2-3n=\Theta(n^2)$. To do so, we must determine positive constants $c_1, c_2$ and $n_0$ such that  
$$
c_1n^2\le \frac1{2}n^2-3n\le c_2n^2
$$  
for all $n\ge n_0$ Dividing by $n^2$ yields  
$$
c_1\le \frac1{2}-\frac3{n}\le c_2
$$  

### **$O$-notation**  
When we have only an ***asymptotic upper bound***, we use $O$-notation.  
$$
O(g(n))=\left\{f(n):\text{ there exist positive constants }c\text{ and }n_0\text{ s.t }0\le f(n)\le cg(n)\text{ for all }n\ge n_0\right\}
$$  

### **$\Omega$-notation**  
$\Omega$-notation provides an ***asymptotic lower bound***.
$$
\Omega(g(n))=\left\{f(n):\text{ there exist positive constants }c\text{ and }n_0\text{ s.t }0\le cg(n)\le f(n) \text{ for all }n\ge n_0\right\}
$$  

### Theorem 3.1  
For any two functions $f(n)$ and $g(n)$, we have $f(n) = \Theta(g(n))$  
if and only if $f(n) = O(g(n))$ and $f(n) = \Omega(g(n))$  

### **$o$-notation**
The asymptotic upper bound provided by $O$-notation may or may not be asymptotically tight. The bound $2^n=O(n^2)$ is asymptotically tight, but the bound $2n=O(n^2)$ is not. We use $o$-notation to denote an upper bound that is not asymptotically tight.  
$$
o(g(n))=\left\{f(n):\text{ for any positive constant }c\gt 0,\text{ there exists a constant }n_0\gt 0\text{ s.t }0\le f(n)\lt cg(n)\text{ for all }n\ge n_0\right\}
$$  

For example, $2n=o(n^2)$, but $2n^2\not =o(n^2)$

### **$\omega$-notation**
We use $\omega$-notation to denote a lower bound that is not asymptotically tight.  
$f(n)\in \omega(g(n))$ if and only if $g(n)\in o(f(n))$.  
$$
\omega(g(n))=\left\{f(n):\text{ for any positive constant }c\gt 0,\text{ there exists a constant }n_0\gt 0\text{ s.t }0\le cg(n)\lt f(n)\text{ for all }n\ge n_0\right\}
$$  

For example, $n^2/2 = \omega(n)$ but $n^2/2 \not =\omega(n^2)$
