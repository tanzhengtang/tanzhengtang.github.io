---
title: EdgeR查找差异表达基因(二)
date: 2021-10-22
categories: 
- 生信
tags: 
- RNA-Seq
- DE-Analysis
- EdgeR
---
# EdgeR查找差异表达基因(二)  
## 前言  
第一篇有关于EdgeR处理差异基因的过程中有瑕疵的，这篇文章一是要提出上次过程中没写出的问题，二是要写出有关EdgeR原理方面的东西。  
## 数据来源  
癌症细胞：`Encode`上`HepG2`癌症细胞系`total RNA-Seq`的基因定量文件。  
正常细胞：`Encode`上正常肝组织的`total RNA-Seq`的基因定量文件。  

## 流程中的问题  
### 基因定量信息  
上次使用了`Encode`的基因定量文件中`gene_id`和`expected_count`两列组成EdgeR的输入数据文件。这样直接使用是粗糙的。  
`下载的ENSG数据中常常有小数点，小数点后面的表示的版本类型，在进行匹配时需要删除小数点后面的，一般情况下ENSG一共是15位，所有保留前15位字符就可以了.`  
**读入数据:**  

> rep1=read.table("./ENCFF944RFV.tsv",header=T)  
> rep2=read.table("./ENCFF529HSE.tsv",header=T)  
> rep3=read.table("./ENCFF396FZT.tsv",header=T)  
> rep4=read.table("./ENCFF103FSL.tsv",header=T)  
> norm1=read.table("~/Project/Normal_tissue/Liver/RNA/ENCFF780YUS.tsv",header = T)  
> norm2=read.table("~/Project/Normal_tissue/Liver/RNA/ENCFF846SOK.tsv",header = T)  
<!--more-->  
**处理gene_id:**  
以rep1为例:  

> rep1 = rep1[grep('ENSG',test\$gene_id,invert = F),]    
> rep1\$gene_id = substr(rep1\$gene_id,1,15)  
> rep1 = aggregate(expected_count ~ gene_id , data = rep1,sum)  

将其他的rep和norm作同样的处理  

**得到矩阵:**  

> count=data.frame(rep1\$gene_id,rep1\$expected_count,rep2\$expected_count,rep3\$expected_count,rep4\$expected_count,norm1\$expected_count,norm2\$expected_count)  
> colnames(count)=c('gene_id','rep1','rep2','rep3','rep4','norm1','norm2')  
> rownames(count)=count$gene_id  
> count = count[,-c(1)]  

原始矩阵count:  

![](/EdgeR(2)/1.png)  

**分组:**  

`分组`步骤同后面的流程息息相关。  
它会影响`过滤低表达基因`和`检验差异基因`。  
1.在`过滤表达基因`部分:  
`The filtering should be based on the grouping factors or treatment factors that will be involved in the differential expression teststested for, rather than on blocking variables that are not of scientific interest in themselves.`  
2.在`检验差异基因`部分:  
(1) 单因子分组实验:`The classic edgeR pipeline`--->`edgeR uses the quantile-adjusted conditional maximum likelihood (qCML) method for experiments with single factor.`  
(2) 多因子复杂分组:`More complex experiments (glm functionality)`--->`Generalized linear models (GLMs) are an extension of classical linear models to nonnormally distributed response data`  