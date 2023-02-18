---
title: Hexo博客插入图片
date: 2021-09-24 21:08:49
categories: 
- Blog
tags: 
- Blog
---
# Hexo博客插入图片问题  
*推送博客时遇到一个问题，图片无法顺利在网站中展现。*  
百度解决方法，内容来源：[https://zhuanlan.zhihu.com/p/265077468](https://zhuanlan.zhihu.com/p/265077468)  
[https://hexo.io/zh-cn/docs/asset-folders](https://hexo.io/zh-cn/docs/asset-folders)     
**在md文件中只需要`![]()`并在`()`中填写本地图片路径，图片即可插入。**  

***解决办法：***  
1. 在`_congfig.yaml`文件中将`post_asset_folder: false`改为`post_asset_folder: true`。  

> 由于项目会生成新的文件目录，同时会解析Markdown中的图片路径，会导致一个问题。
> 如在一个文件目录下，博客名为1.md，相应的存在一个1文件夹存放图片image.jpg。
> 在Typora编辑器中，普通的md文件使用`![](1/image.jpg)`能在编辑器中正常显示图片。
> 在hexo中，按理说应该是使用`![](image.jpg)`，但网页中却无法正常显示。
> 此时应该使用这样的方式来引入图片:`{% asset_img image.jpg 这是一张图片 %} `  
2.解决`{% asset_img image.jpg 这是一张图片 %} `这种难写的语法。`npm install hexo-renderer-marked`安装插件，并在`_config.yaml`中更改配置:  

>post_asset_folder: true  
>marked:  
>prependRoot: true  
>postAsset: true  

3.如果采用`![](image.jpg)`的方式，此时md文件和相应图片处于同一目录下，但是直接上传仍然无法成功在网站上插入图片，而是需要将md文件拿到上级目录，像这样  
![](insert.png)  
如此的话，我们编写的时候可将md文件置于同一文件夹，编写完成时需将md文件拿到上级目录即可。  