---
title: 推送博客配置及笔记至github
date: 2023-02-18 21:08:49
categories: 
- Blog
tags: 
- Blog
- Web
toc: true
---
# 推送博客配置及笔记至github   
内容来自知乎：[https://zhuanlan.zhihu.com/p/187435941](https://zhuanlan.zhihu.com/p/187435941)     
此项笔记仅仅是为防丢。
若没有这样的措施，换台电脑就非常麻烦，什么都要重新弄。  

## 原理   
1. `github.io`站点只是展示`master`上的静态文件，我们可以再在这个仓库里创建新的分支，然后将本地的源代码推送至该分支即可。  
2. 运行`hexo d`时，生成的静态代码（在public文件夹中）会被自动push到远程仓库的maser分支。  

## 操作   
1. 解决.gitgnore文件中的忽略项，一般情况下包含以下内容:  
`.DS_Store, Thumbs.db, db.json, *.log, node_modules/, public/, .deploy*/
`  
去除掉`db.json,
Thumbs.db, 
node-modules/,`  
这3项包含hexo相关插件的重要信息，因此无需被忽略。  
2. 完成后执行`git add * ; git commit -m "first commit"`  
3. 若没有关联远程仓库，则`git checkout -b source; git remote add github 远程仓库地址; git push -u github source`  
4. 此时，我们最好去github上的远程仓库上，将远程仓库的主分支设置为source分支（默认为master分支）。（因为主分支不容易被删除。当我们意外删除主分支的时候，github会提醒我们这是主分支，这可以防止我们不小心删除source分支。并且，当我们在另一台电脑上从远程仓库clone时，本地仓库默认所在的分支是source分支。）  

## 后记   
一个仓库两个分支，默认情况下github pages服务展示的是master分支的静态代码，而笔记文件和配置的其他东西手动可推送至另一分支。  