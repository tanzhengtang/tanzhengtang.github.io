---
title: 基数排序
date: 2021-10-09
categories: 
- Algorithm
tags: 
- Algorithm
- Math
---
# 基数排序  
内容主要来源：  
[https://oi-wiki.org/basic/radix-sort/](https://oi-wiki.org/basic/radix-sort/)（OI Wiki）
[https://www.runoob.com/w3cnote/radix-sort.html](https://www.runoob.com/w3cnote/radix-sort.html)（菜鸟教程）  
## 简介  
基数排序（英语：Radix sort）是一种非比较型的排序算法，最早用于解决卡片排序的问题。

它的工作原理是将待排序的元素拆分为  个关键字（比较两个元素时，先比较第一关键字，如果相同再比较第二关键字……），然后先对第  关键字进行稳定排序，再对第  关键字进行稳定排序，再对第  关键字进行稳定排序……最后对第一关键字进行稳定排序，这样就完成了对整个待排序序列的稳定排序。  

**基数排序 vs 计数排序 vs 桶排序**  
基数排序有两种方法：
这三种排序算法都利用了桶的概念，但对桶的使用方法上有明显差异。  
**基数排序：** 根据键值的每位数字来分配桶；  
**计数排序：** 每个桶只存储单一键值；  
**桶排序：** 每个桶存储一定范围的数值。  
## 代码


## 后续
1.原理（长期）。









