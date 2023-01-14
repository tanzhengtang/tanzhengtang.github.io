---
title: clusterProfiler进行GO、KEGG以及相应的可视化
date: 2021-10-09
categories: 
- 生信
tags: 
- RNA-Seq
- DE-Analysis
- clusterProfiler
---
# clusterProfiler进行GO、KEGG以及相应的可视化  
内容主要来源：  
[https://guangchuangyu.github.io/software/clusterProfiler/documentation/](https://guangchuangyu.github.io/software/clusterProfiler/documentation/)（官方使用文档)  
## 数据来源  
**差异基因列表：**`NCI-H460`癌症细胞同正常组织之间的差异基因。  
承接自这篇笔记中:[EdgeR查找差异表达基因](https://tanzhengtang.github.io/2021/09/27/EdgeR/)  

## 过程  
### GO分析  
**代码:**  
`ego <- enrichGO(gene = idt,OrgDb = org.Hs.eg.db,keyType = 'ENSEMBL',ont = "ALL",pAdjustMethod = "BH",pvalueCutoff = 0.01,qvalueCutoff  = 0.05,readable = T)`  
**gene是得到的差异基因列表.  
keyType指定基因ID的类型,默认为ENTREZID.  
OrgDb指定该物种对应的org包的名字.  
ont代表GO的3大类别，BP, CC, MF,而ALL是将该3类一起包含.  
pAdjustMethod指定多重假设检验矫正的方法.  
cufoff指定对应的阈值.  
readable=TRUE将基因ID转换为gene symbol.**  
_idt_ 差异基因列表:  
![](/clusterProfiler/1.png)  
<!--more-->  
这样就可以直接出图了。  
`dotplot(ego,showCategory = 10)`   
![](/clusterProfiler/2.png)   
`barplot(ego,showCategory = 10)`  
![](/clusterProfiler/3.png)  

### KEGG分析  
在代码方面同GO分析差不多:  
`kk=enrichKEGG(te$entrzid,organism="hsa",
pvalueCutoff=0.05,pAdjustMethod="BH",qvalueCutoff=0.1)`  
`kk=setReadable(kk,OrgDb = org.Hs.eg.db,keyType = 'ENTREZID')`  
经尝试，KEGG分析似乎不支持ENSEMBL的ID，所以运行上面之前先转换成ENTRZID:  
`en=mapIds(x = org.Hs.eg.db,keys = ed$symbol,keytype = "SYMBOL",column = "ENTREZID")`  
`ed$entrzid=en`  
`te=na.omit(ed)`  
出图：  
`barplot(kk,ddrop=T,showCategory =10,title="KEGG Enrichment Pathways")`  
![](/clusterProfiler/4.png)  

**额外的pathview图：**  
内容来源:  
[https://cloud.tencent.com/developer/article/1539928](https://cloud.tencent.com/developer/article/1539928)  
`genem=tee$logFC`  
`names(genem)=row.names(tee)`  
`pathview(gene.data = genem,pathway.id = '04514',species = 'hsa')`  
`pathway.id`是信号通路的id，如04514意味着Cell adhesion molecules通路，画出的是该样本在某通路上的基因表达量变化。  
`gene.data`是样本的表达量，这个可以是foldchange,也可以是cpm等等。   
`genem`的行名须是ENTRZID.  
`species`是种类。  
![](/clusterProfiler/5.png)  

## 后续
1.原理（长期）。