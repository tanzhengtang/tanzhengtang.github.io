---
title: Terecent Tao Analysis I Chapter2 & Exercise
date: 2023-3
mathjax: true
categories: 
- Math
tags: 
- Math
---
# Chapter 2  
* Just to record my own thought and answer,if there has any error,please leave a message in the comment area. 
## 2.1 The Peano Axioms  
### 2.1.4 Proposition: 3 is a natural number  
* Use Axiom 2.2 : If n is a natural number, then n++ is also a natural number.  
* We know that 2 is natural number, and 3 is 2++,so 3 is natural number.

### 2.1.6 Proposition: 4 is not equal to 0  
* Use Axiom 2.3: 0 is not the successor of any natural number.  
* 4 is 3++,so 4 is not equal to 0.

### 2.1.8 Proposition: 6 is not equal to 2
* Use Axiom 2.4 : Different natural numbers must have different successors.  
* 6 is 5++,and 2 is 1++, 5 is not equal to 1, so 6 is not equal to 2.  

### 2.1.11 Proposition: A certain property P(n) is true for every natural number n  
* Use Axiom 2.5 (Principle of mathematical induction): Let P(n) be any property pertaining to a natural number n. Suppose that P(0) is true, and suppose that whenever P(n) is true, P(n++) is also true. Then P(n) is true for every natural number n.  
* According to the proposition, P(0) is true, if P(n) is true, according to axiom 2.5, we must to show P(n++) is true. Because n++ is natural number, according to the proposition again,P(n++) is true, so the proposition is true.

### 2.1.16 Proposition(Recursive definitions): Suppose for each natural number $n$, we have some function $f_n$ : $N → N$ from the natural numbers to the natural numbers. Let $c$ be a natural number. Then we can assign a unique natural number $a_n$ to each natural number $n$, such that $a_0 = c$ and $a_{n++}$ = $f_n(a_n)$ for each natural number $n$.  
* The definition(informal) of function is a $x$ for a only $y$.  
* According to the proposition, $a_n$ is also a one-to-one function of N to N.  
* The proof is focus on 'unique natural number'. If $a_0$ is set to $c$, according to the proposition, other $a_n$ can not be $c$, because axiom 2.3. If there exist $a_n$ equal to $a_0$,the $n$ must be 0. Now we suppose $a_n$ is true for this property, we can show $a_{n++}$ is also true, because n++ is natural number, and n++ is not equal to n.  

Look at the official proof, I know my thought is not right. I don't know if this is correct that thinking $a_0 = c$ is belong to $f_n$.  

**Please help me to understand the official anwser, I will be very grateful for it.**

## 2.2 Addition  
### 2.2.2 Lemma: For any natural number $n$, $n + 0 = n$  
* Use Axiom 2.5 and Definition 2.2.1 (Addition of natural numbers) : Let m be a natural number. To add zero to m, we define $0 + m := m$. Now suppose inductively that we have defined how to add n to m. Then we can add $n++$ to m by defining $(n++) + m := (n + m)++$.
* Let $n = 0$, $n + 0 = 0 + 0 = 0 = n$, assume $n + 0 = n$ is true, show $(n++) + 0 = (n + 0)++ = (n++)$ is also true.

### 2.2.3 Lemma: For any natural numbers $n$ and $m$, $n + (m++) = (n + m)++$  
* Use Axiom 2.5 and Definition 2.2.1.    
* Let $n = 0$, $0 + (m++) = (m++) = (0 + m)++$, suppose $n + (m++) = (n+m)++$ is true. Show $(n++) + (m++) = (n + m(++))++ = ((n + m)++)++ = ((n++) + m)++$ is also true.

### 2.2.4 Proposition (Addition is commutative) : For any natural numbers $n$ and $m$, $n+m=m+n$  
* Use Axiom 2.5, Lemma 2.2.2 and Lemma 2.2.3   
* Let $n = 0$, $n + m = 0 + m = m = m + 0 = m + n$, suppose $n + m = m + n$ is true. Show $(n++) + m = (n + m)++ = (m + n)++ = m + (n++)$ is also true.  

### 2.2.5 Proposition : (Addition is associative). For any natural numbers $a,b,c$, we have $(a+b)+c=a+(b+c)$  
* Use Axiom 2.5, Lemma 2.2.2 and Lemma 2.2.3
* Let $a = 0$,$(a + b) + c = 0 + b + c = 0 + (b + c) = a + (b + c)$, suppose $(a + b) + c = a + (b + c)$ is true, show $((a++) + b) + c = ((a + b)++) + c = ((a + b) + c)++ = (a + (b + c))++ = (a++) + (b + c)$ is also true.  

### 2.2.6 Proposition : (Cancellation law). Let $a,b,c$ be natural numbers such that $a+b=a+c$. Then we have $b=c$  
* I think this proposition in a simple way: if $a + b = b + c$, then $b = c$.  
* Use Axiom 2.5 and Axiom 2.4.  
* Let $a = 0$, if $a + b = b + c$, then $0 + b = 0 + c$, then $b = c$. Assume this property is true for $a$, show $a++$ is also true for this property.  
* If $(a++) + b = (a++) + c$, then $(a + b)++ = (a + c)++$, according to axiom 2.4, different natural numbers must have different successors, so $(a + b)$ must be equal to $(a + c)$, according to the assumption, so for $a++$, also get the $b = c$. 

### 2.2.8 Proposition : If $a$ is positive and $b$ is a natural number, then $a + b$ is positive (and hence $b + a$ is also, by Proposition 2.2.4)  
* Use Definition 2.2.7 (Positive natural numbers) : A natural number n is said to be positive iff it is not equal to 0.   
* Use Axiom 2.3.  
* If $a$ is positive,then $a$ is not equal to 0, and $b \geq 0$(informal), so $a + b$ must be successor of natural number, and according to axiom 2.3, $a + b$ can not be 0, then $a + b$ is positive.   

### 2.2.9 Corollary : If a and b are natural numbers such that $a + b = 0$, then $a=0$ and $b=0$  
* Use Proposition 2.2.8.  
* If $a$ not equal to 0 or $b$ not equal to $0$, use 2.2.8, then $a + b$ is positive. So 2.2.9 is true.  

### 2.2.10 Lemma : Let a be a positive number. Then there exists exactly one natural number b such that $b++ = a$  
* Thought this lemma is that for every natural number has a positive successor number.  
* Use Axiom 2.5.  
* Let $b = 0$, $0++ = 1$, and $1$ is positive. Assume $n++ = (n++)$, and $n++$ is positive. Show $(n++)++$is positvie.   
* Because $n++$ is positive, so $(n++)++$ is natural number and not equal to 0. So $(n++)++$ is positive.   

### 2.2.12 Proposition (Basic properties of order for natural numbers)  
1. (Order is reflexive) a ≥ a  
2. (Order is transitive) If a≥b and b≥c, then a≥c  
3. (Order is anti-symmetric) If a ≥ b and b ≥ a, then a = b  
4. (Addition preserves order) a≥b if and only if a+c≥b+c  
5. a<b if and only if a++≤b 
6. a<b if and only if b=a+d for some positive number d  
   
* Use 2.2.11 Definition (Ordering of the natural numbers). Let n and m be natural numbers. We say that n is greater than or equal to m, and write n ≥ m or m ≤ n, iff we have n = m + a for some natural number a. We say that n is strictly greater than m, and write n > m or m < n, iff n ≥ m and $n not equal to m$
* $a \geq a$, because $a + 0 = a$, and 0 is natural number.
* If $a \geq b$ and $b \geq c$, then $a \geq c$. Because $b + m = a$, $c + n = b$, use $c + n$ to substitute $b$, have $c + n + m = a$, so $a \geq c$.  
* If $a ≥ b$ and $b ≥ a$, then $a = b$. We have $a + n = b$ and $b + m = a$, then $a + n + m =  a = a + 0$, thought $n + m$ is a natural number, use 2.2.6 proposition, then have $n + m = 0$, use 2.2.9 corollary, then $n = m = 0$, so we get $a = b$.  
* $a≥b$ if and only if $a+c≥b+c$. If $b + n = a$, we can have $a + c = b + n + c = b + c + n$, according to 2.2.11 definition, so $a+c≥b+c$. If we have $a+c≥b+c$, then $a + c = b + c + n = b + n + c$, think $b + n$ is a number, use 2.2.6 proposition, so $a = b + n$, and then $a≥b$.  
* $a<b$ if and only if $a++≤b$. If $a < b$, according to 2.2.11 definition, we have $a + n = b$ and $n$ not equal to 0, use 2.2.10 lemma for $n$($n$ is positive), know there must be a natural number such that $m++ = n$, now we have $a + (m++) = b$, then $(a++) + m = b$, because $m$ is a natural number, So $a++≤b$. If we have $a++≤b$, then $(a++) + m = b$, then $a + (m++) = b$, because $m++$ can not be 0, So $a < b$.  
* $a<b$ if and only if $b=a+d$ for some positive number $d$. If $a < b$, we have $a + d = b$ and $a$ not equal to $b$, assume $d$ is 0, it will get $a = b$, this is a contradiction, so $d$ not equal to 0, then $d$ is positive number. If we have $b=a+d$ for some positive number $d$,so $a \leq b$, because $d$ is positive, then $a$ not equal to $b$, so $a<b$ is true.  

### 2.2.13 Proposition : (Trichotomy of order for natural numbers). Let a and b be natural numbers. Then exactly one of the following statements is true: $a<b, a=b$, or $a>b$  
* First, I want to prove that $a,b$ really just have the three relations. Obviously, there has $a = b$. Consider if $a$ not equal to $b$, use axiom 2.3 and 2.4, know that if $a,b$ is different, then their predecrssor is also different.  Recursively trace to the front,$a$ and $b$ trace same times $c$, will get $0$ not equal to $n$,$n \in N$, then $n \geq 0$, and $a$ not equal to $b$, so have $n > 0$, and $n + c > 0 + c$, so have $a > b$ or $a < b$.
* Prove for every $a,b$, only have one relation in the three. If have $a > b$ or $a < b$, use sixth conclusion of 2.2.12 prosition, get $a$ not equal to $b$, beacuse axiom 2.3. And if have $a = b$, can not get $a < b$ or $a > b$, because sixth conclusion of 2.2.12 prosition.

### 2.2.14 Proposition : (Strong principle of induction). Let $m_0$ be a natural number, and let $P(m)$ be a property pertaining to an number $m$. Suppose that for each $m ≥ m_0$, we have the following implication: if $P(m^′)$ is true for all natural numbers $m_0 ≤ m′ < m$, then $P(m)$ is also true. (In particular, this means that $P(m_0)$ is true, since in this case the hypothesis is vacuous.) Then we can conclude that $P(m)$ is true for all natural numbers $m ≥ m_0$.  
* Use axiom 2.5  
* Let $Q(n)$ is such property for all nautral number $n \geq m_0$ that $P(n)$ is true.
* If $n \leq m_0$, $Q(n)$ is vacuous true, because the hypothesis is false. So if we set $n = 0$, $Q(n)$ must be true, because $m_0 \geq 0$.
* Suppose $Q(n)$ is true, consider $Q(n + 1)$. If $m_0 \geq n + 1$, we have vacuous true, it is also true for $Q(n)$. If $n + 1 > m_0$, we have $m_0 \leq n < n+ 1$, because $Q(n)$ is true, so $Q(n+1)$ is also true. So this property is proved.  

### Exercise
* Exercise 2.2.1 Prove Proposition 2.2.5
* Exercise 2.2.2 Prove Lemma 2.2.10
* Exercise 2.2.3 Prove Proposition 2.2.12
* Exercise 2.2.4 Justify the three statements marked (why?) in the proof of Proposition 2.2.13.  
*First why (When $a=0$ we have $0≤b$ for all $b$):* this means for all natural number $b$ we have $b \geq 0$, use axiom 2.5, obviously when $b = 0$, this is true, suppose $b = n$ is true, we can also get $n + 1 > n \geq 0$ is true, so $b \geq 0$.  
*Second why (If $a>b$,then $a++>b$):* use $a > b$, we have $b + n = a$, and $n$ is positvie, and $b + n + 1 = a + 1 = a++$, this is $b + 1 < a++$, and because $b < b + 1$, so $b < a++$.  
*Third why (If $a=b$,then $a++>b$):* becasue $a++ = a + 1 = b + 1$, and 1 is positive, so $a++>b$ is true.  
* Exercise 2.2.5 Prove Proposition 2.2.14
* Exercise 2.2.6 Let $n$ be a natural number, and let $P(m)$ be a property pertaining to the natural numbers such that whenever $P(m++)$ is true, then $P(m)$ is true. Suppose that $P(n)$ is also true. Prove that $P(m)$ is true for all natural numbers $m ≤ n$; this is known as the principle of backwards induction. (Hint: apply induction to the variable $n$.)  
*Proof:* Let $Q(n)$ is such property that $P(m)$ is true for all natural numbers $m \leq n$ when $P(n)$ is true. Let $n = 0$, so $m$ must be 0, so $P(m) = P(n)$ is true, then $Q(n)$ is true when $n = 0$. Suppose $Q(n)$ is true, consider $Q(n++)$. So we have $m \leq n < n++$, because $P(n++)$ is true, then $P(n)$ is true, then $P(m)$ is true (because suppose $Q(n)$ is true), so $Q(n++)$ is true.