---
title: Mac下Hexo和Github免费搭建个人网站
date: 2021-09-24 21:08:49
comment: 
categories: 
- Blog
tags: 
- Blog
---
# 前言:  
**1. 这篇文章写来试试效果，99%的内容来自于自网上的教程以及官网的文档，包括但不限于以下链接:**  
***[https://zhuanlan.zhihu.com/p/111614119](https://zhuanlan.zhihu.com/p/111614119)（主要来源，非常厉害的教程，windows可以直接按照此文进行搭建）  
[https://hexo.io/zh-cn/docs/](https://hexo.io/zh-cn/docs/)（hexo官方文档，中文版）  
[http://nodejs.cn/](http://nodejs.cn/)(node.js的中文官网)  
[https://docs.npmjs.com/](https://docs.npmjs.com/)（npm的官方文档）  
[https://github.com/](https://github.com/)（github官网）***

**2. 整个过程以Mac系统进行说明。**  

# 正文：  
## GitHub与Git  

### GitHub的账号注册  

**进入官网([https://github.com/](https://github.com/))后，用邮箱注册一个即可。**  

### 创建GitHub仓库  

打开GitHub网页，登陆账号后，网页右上角有个➕的一个图标，点击它后再点击`New repository`。  
![](blog1.png)   

这样会出来一个全新的页面，你需要在这个页面上的`Repository name`一栏填入*xxxxxx.github.io*。*xxxxxxx*就是你的GitHub账户名，**整个必须完全一致才行**。然后在`Add a README file`一栏进行打勾勾选，再点击`Create repository`进行创建。  
![blog2](./blog2.png)  

创建完毕后，访问*xxxxxx.github.io*应该会出现类似于下面这种页面：  

![](blog3.jpeg)  

### Git的安装与设置 
> Git是一个分布式版本控制系统，本质上就是通过这个软件将所要存储的东西上传至GitHub账户中存储起来，当然也可以在一台全新的电脑上将存储在GitHub中的东西下载下来。推荐廖雪峰大佬的Git教程：https://www.liaoxuefeng.com/wiki/896043488029600。  

**安装：**  
Mac中该软件应是自带。如果没有，请按照此链接[https://git-scm.com/download/mac](https://git-scm.com/download/mac)中的内容进行安装。  
**设置：**  
1. 需要在终端对Git进行设置，输入命令`git config --global user.name "Your Name"`以及`git config --global user.email "email@example.com"`  
第一个命令最后面是GitHub的用户名，第二个命令最后是GitHub注册时的邮箱。  
_设置完成后此时仍不能使用Git传输数据到GitHub上，因为传输需要加密。_  
2. 继续在终端中输入命令`ssh-keygen -t rsa -C "youremail@example.com"`，邮件地址为注册账户时的邮件地址。输入该命令后，终端中会出现一些可输入选项，不用理会，一路回车即可。  
3. 上一个命令完成后，此时家目录中会生成名为`.ssh`的文件夹，输出该目录下的i`d_rsa.pub`文件中的内容，它会是类似下面这种东西：  
![](blog6.png)  
4. 这是所需要的密匙，打开GitHub网站并登录，点击右上角的个人头像，并点击`Settings`。  
![](blog7.png)  
1. 在新出现的_Account settings_页面中点击`SSH and GPG keys`，再点击右上角绿色的`new SSH key`。  
![](blog8.png)  
1. 在key一栏中填入`id_rsa.pub`文件中的内容，title一栏中的内容可随意自取（一般来说是填办公地点）。内容填完后，点击绿色`Add SSH key`。  
![](blog9.png)  

---  

## Hexo  
> Hexo是一款基于Node.js的静态博客框架，依赖少易于安装使用，可以方便的生成静态网页托管在GitHub和Heroku，是搭建博客的首选框架。
> 实际上就是通过Hexo这个软件将你写的笔记自动地转换成前端页面，“漂亮”地把md文件展示出来。  

### 安装  
在安装Hexo之前，需要先安装`Node.js`软件。点击[https://nodejs.org/en/](https://nodejs.org/en/)，下载LTS版本的pkg文件进行安装。安装完成后此时在终端中可使用npm命令，输入`npm install hexo-cli -g`进行全局安装Hexo。如在这一步时出现了***EACCES***权限错误，可根据Hexo官方文档：
![](blog4.png)  
进入[https://docs.npmjs.com/resolving-eacces-permissions-errors-when-installing-packages-globally](https://docs.npmjs.com/resolving-eacces-permissions-errors-when-installing-packages-globally)，根据页面上的方法进行修复。  
npm官方提供了两种修复方式，一是*Reinstall npm with a node version manager*；二是*Manually change npm's default directory*。如采用第二种方式（如未能按此方法修复，可在[https://hexo.io/zh-cn/docs/](https://hexo.io/zh-cn/docs/)评论区中寻找类似情况并解决。）：  
![](blog5.png)  
在终端中做完这5个步骤后，再使用`npm install hexo-cli -g`进行安装。  
安装完成后，可使用`npx hexo <command>`调用Hexo。也可先使用`echo PATH=$PATH:./node_modules/.bin >> ~/.profile`命令将 Hexo 所在的目录下的 node_modules 添加到环境变量之中，这样可直接使用 `hexo <command>`  

> 实际上在Mac下，把`export PATH=~/.npm-global/bin:$PATH`以及`export PATH="$PATH:./node_modules/.bin"`放在`~/.bashrc`更为友好。若放在`~/.profile`中，仍需手动`source ~/.profile`才可生效。  
  
### 设置  
输入`hexo -v`可检查版本，测试是否安装成功。  
家目录下创建名为blog的目录。在此目录下打开终端，依次输入`hexo init`以及`npm install`进行本地hexo的初始化。  
![blog10](blog10.png)  
依次使用`hexo g（生成静态网页）` `hexo s（将网页部署到本地）`,然后访问本地[http://localhost:4000/](http://localhost:4000/)，可查看测试网页。  
![](blog11.png)  

> hexo s等价于 hexo server #Hexo 会监视文件变动并自动更新，除修改站点配置文件外,无须重启服务器,直接刷新网页即可生效。  
> hexo g 等价于 hexo generate #生成静态网页 (执行 $ hexo g 后会在站点根目录下生成public>文件夹, hexo会将"<font /blog/source/" 下面的.md后缀的文件编译为.html后缀的文件,存放在"/blog/public/ " 路径下)  
> hexo d 等价于 hexo deploy #将本地数据部署到远端服务器(如github)  
> hexo clean #清除缓存 ,网页正常情况下可以忽略此条命令,执行该指令后,会删掉站点根目录下的public文件夹.  

停止测试网页，打开blog文件，打开其中的_config.yml文件，修改其中下面两段。  
![](blog12.png)  
![](blog13.png)  
若需要将该blog文件上传至GitHub，还需安装扩展，输入`npm i hexo-deployer-git`进行安装。  
输入`hexo new post "article title"`新建一篇md文章。在该文章中编写一些内容后，输入`hexo g`生成静态网页文件，再`hexo d`将blog文件推送至GitHub上。推送完毕后，如无意外，访问`https://用户名.github.io`，将会看到新的网页。  

## 结语  
**1.Hexo面向md文件进行转化，所以还需学习如何编写md文件。  
2.Hexo有很多开发好的网页主题，官网上就有许多推荐的主题，可自行取用。  
3.搭建好的个人网站域名也可更改，谷歌一下即可解决。**