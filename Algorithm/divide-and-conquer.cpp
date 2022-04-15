/*
 * @Author: Tang
 * @Date: 2021-04-14 14:53:45
 * @LastEditors: Tang
 * @LastEditTime: 2021-04-15 13:58:39
 * @Description: 
 * @FilePath: 
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*

给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
二叉树不超过 1000 个节点，且节点数值范围是[-1000000,1000000]的整数。
示例： 
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有：
1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

/*
 * 二叉树结点的定义
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

/*
写递归的要点
明白一个函数的作用并相信它能完成这个任务，千万不要跳进这个函数里面企图探究更多细节， 否则就会陷入无穷的细节无法自拔，人脑能压几个栈啊。
*/

//上面这道题，找出有多少个等于8的路径，找出有3个，所以最后结果等于3。
class Solution{
    public: 
    //首先就是要计算递归时节点内的和。
    

};
int main(int argc, char const *argv[])
{
    cout<<12%10<<endl;
    return 0;
}
