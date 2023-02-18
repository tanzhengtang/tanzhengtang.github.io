---
title: 排序算法
date: 2022-4-25
mathjax: true
toc: true
categories: 
- Algorithm
tags: 
- Algorithm
---  

# 排序  
均为笔记，内容来自:  
https://oi-wiki.org/basic/sort-intro/  

## 归并排序  
https://blog.csdn.net/k_koris/article/details/80508543  
归并排序是一种稳定的排序算法。  
归并排序的最优时间复杂度、平均时间复杂度和最坏时间复杂度均为$O(nLogn)$。  
归并排序的空间复杂度为$O(n)$。  

* 分而治之的思想    
1. 分解原问题为结构相同的子问题。  
2. 分解到某个容易求解的边界之后，进行递归求解。  
3. 将子问题的解合并成原问题的解。  

* 递归  
递归的基本思想是某个函数直接或者间接地调用自身，这样原问题的求解就转换为了许多性质相同但是规模更小的子问题。求解时只需要关注如何把原问题划分成符合条件的子问题，而不需要过分关注这个子问题是如何被解决的。  

如：  
```  
int k(int a[],int i){
    if(i <= 0){ return 0; }
    i = i - 1;
    return k(a,i) + 1;
}
``` 
**重点:明白一个函数的作用并相信它能完成这个任务，千万不要跳进这个函数里面企图探究更多细节。**  

### 步骤  
考虑如下简单列表:  
[5,4,10,3]  
那么按照分而治之的思想，我们可将其划分成两个小的列表，[5,4]以及[10,3]，对他们各自排好序后再次进行归并。  
排好序后的[4,5]以及[3,10]，归并的时候是两个有序的列表，这儿我们可以采用有序列表的合并算法进行合并。实际上，[4,5]中的[5]以及[4]也是按照有序列表进行合并的。  
如果按照上述的思维，我们可将一个很大的列表进行循环递增分割至最小的列表，然后按照有序列表进行合并。  
用别人精炼的语言，即:  
1. 将数列划分为两部分；  
2. 递归地分别对两个子序列进行归并排序；  
3. 合并两个子序列。  

将重点放在第3步上，合并两个有序的子序列。 

```
//a = [4,5]
//b = [3,10]
int* merge_sort(int a[],int b[]){
    int a_size = sizeof(a)/sizeof(int);
    int b_size = sizeof(b)/sizeof(int);
    int tmp_size = a_size + b_size;
    int tmp[tmp_size];
    int s = 0;
    int a_s = 0;
    int b_s = 0;
    int a_e = a_size - 1;
    int b_e = b_size - 1;
    //从头开始将每个列表进行比较。
    //类似插入排序，两个列表中小的元素插入新的数组前面。由于是都是有序的序列，
    //插入后只需将其中一个的指针往后移动，然后再进行比较。
    while(a_s <= a_e && b_s <= b_e){
        if(a[a_s] > b[b_s]){
            tmp[s++] = a[a_s++];
        }
        else{
            tmp[s++] = b[b_s++];
        }
    }
    while(a_s <= a_e){
        tmp[s++] = a[a_s++];
    }
    while(b_s <= b_e){
        tmp[s++] = b[b_s++];
    }
    return tmp;
}
```

上述的所花费的时间，即b_size + a_size，而这两个是由原先的列表所分割而成，即原列表的元素数量大小。  
再来对1、2两步进行实现。  

```
void merge(int a[],int t[],int start,int end){
    //终止条件即分割后的列表中最少存在1个元素。
    if(start - end <= 1){return;}
    int mid = start + ((start - end) >>  1);
    //递归
    merge(a,t,start,mid);
    merge(a,t,mid,end);
    //合并序列，所采用的思想同merge_sort中是一样的，但需进行一定改写，
    //因为此处是自身的分割序列，为了减小开销，我们并未真正的开辟了两个数组进行比较。
    int s = start;
    int s1 = start;
    int ed1 = mid;
    int s2 = mid + 1;
    int ed2 = end;
    while(s1 <= ed1 && s2 <= ed2){
        if(a[s1] > a[s2]){
            t[s++] = a[s2++];
        }
        else{
            t[s++] = a[s1++];
        }
    }
    while(s1 <= ed1){
        t[s++] = a[s1++];
    }
    while(s2 <= ed2){
        t[s++] = a[s2++];
    }
}
```  

我们知道从各个子部分中间分割的话，所需的时间为$LogN$，而随着每一次递归，我们都进行了一次合并，乘以合并所需的时间即$NlogN$。  

## 快速排序  
内容待定