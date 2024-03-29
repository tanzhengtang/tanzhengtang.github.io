---
title: 统计学习方法三要素
date: 2022-4-5
mathjax: true
categories: 
- Statistical Learning Methods
tags: 
- Deep Learning
- Math
toc: true
---
# 统计学习方法三要素  
课程内容：  
[https://www.bilibili.com/video/BV1No4y1o7ac?p=4](https://www.bilibili.com/video/BV1No4y1o7ac?p=4)  

## 纲要  

### 三要素的定义  

> 统计学习方法的三要素为模型、策略、算法。  
1. 模型是所有可能的条件概率分布或决策函数，用$\mathcal{F}$表示。而所有的模型的集合称之为假设空间。  
> 对于决策函数，实际上并不是很清楚。课程中，讲课者也只是说了它为非条件概率分布模型。
> 百度百科上，决策函数用于数据分类。例子：在二分类情况下，有决策函数$y=f(x)$，当$y > 0$时，所取$x$实例集合便是一类，$y<0$时的其他实例便是另一类。当然这些可以延伸到多分类问题。  
> 如此看来的话，个人的理解便是：条件概率分布用于预测，而决策函数则是用于分类。  

1. 策略是用于选择最优模型的。  
一般由损失函数来度量模型一次预测的好坏，记作$L(Y,f(X))$  
而度量所有情况下（平均意义下）的模型预测的好坏，则是$R_e = E_p[L(Y,f(X)]$  
而$L$函数是由$Y$和$f(x)$联合决定的，则可通过$E(x)=\sum_{i = 1}^n P(x_i)x_i$  
得到一般情况下的期望风险函数$R_e = \int_{X Y} L(y,f(x))P(x,y)dxdy$   
而往往$P(x,y)$我们是无法得知的，所以通常用经验风险来表示模型的平均损失：$R_{emp}(f) = \cfrac{1}{N} \sum_{i=1}^N L(y_i,f(x_i))$  

> 损失函数顾名思义，便是预测值或者打分同实际值之间的差别。风险函数相当于把该损失函数应用于所有的实例来看这个模型好不好。  


## 待定内容  
### 待定内容 










