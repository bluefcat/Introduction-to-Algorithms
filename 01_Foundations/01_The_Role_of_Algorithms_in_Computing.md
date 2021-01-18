# The Role of Algorithms in Computing

## **Algorithm** 
A sequence of computational steps that transform the input into the output  

### **Example**  
*sorting problem*  
|||
|-|-|
|**input**|A sequence of $n$ numbers $\langle a_1,a_2,\cdots,a_n\rangle$|
|**output**|A permutation (reordering) $\langle a_1',a_2',\cdots,a_n'\rangle$ of the input sequence such that $a_1'\le a_2'\le \cdots\le a_n'$|  

For example, given the input sequence $\langle31,41,59,26,41,58\rangle$, a sorting algorithm returns as output the sequence $\langle26,31,41,41,58,59\rangle$.  

### **What kinds of problems are solved by algorithms?**  

- The Human Genome Project
  
- The finding information in the Internet

- The public-key, cryptograph and digital signature in Electronic commerce

- Allocate scare resource in the most beneficial way  

#### **Underlying techniques**  

(This techique are beyound the scope of this book)

- Determine the shortest route from one intersection to another.  

- Find a longest common subsequence of between two sequences.

- Topological sorting

- Find the convex hull of n points in the plane (Figuer 33.6 on page 1029 for an example)  

## **Algorithms as a technology**  

Computers may be fast, but they are not infinitely fast. And memory may be inexpensive but it is not free. So we should use these resources wisely, and algorithms that are efficient in terms of time or space will help we do so.  

### **Efficiency**  

Diffrent alogorithms devised to solve the same problem often differ dramatically in their efficiency.

||Insertion sort|Merge sort|
|:-:|:-:|:-:|
|efficiency|$c_1n^2$|$c_2 n\lg{n}$|  
(insertion sort typically has a smaller constant factor than merge sort $c_1 < c_2$)


