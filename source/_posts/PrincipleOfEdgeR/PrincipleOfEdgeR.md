---
title: EdgeR原理探究
date: 2021-09-27
categories: 
- 生信
tags: 
- RNA-Seq
- DE-Analysis
- EdgeR
- 原理
---
## 概视
EdgeR包采用了两种统计学方法，一种是所谓的精确统计，另一种是基于广义线性模型（glm）的统计。从官方文档来看，官方更为推崇glm。  
这两种方法都采用了经验贝叶斯方法来估计特定基因的生物变异。  
![](1.png)  

