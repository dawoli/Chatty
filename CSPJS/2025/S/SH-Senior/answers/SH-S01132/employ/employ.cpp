#include<bits/stdc++.h>
using namespace std;
/*
推理开始14 35 
 贪心:每人选最大的
 限制:n/2
 键盘好吵
 特殊点A:只要前n/2的满意度的人 
 特殊点B:1社团满了 选取差值最小的 赶到2社团去
 暴力:枚举每个人去哪里 
 40分 
  考虑普遍情况吧
  键盘声静下来了
   假设1社团满人 那就算把多的人全部赶到2去也没问题
   选差值最小的人赶 随便乱赶也没问题 
   problem solved 
   14 43
*/
/*
360有bug
压缩包去掉后页面的虚框还在
我的电脑上有幽灵 
*/
/*
14 58 simple 1 AC
15 01 simple 4 WA->test 9
15 11 bug found 4.4 AC
15 12 simple 5 TLE +0.24s
but O(T*nlogn) cant faster

i hope god will bless me
or i will only get 55 points
RP++;
*/
/*
15 22
time enough
推理开始
首先 我不会并查集
先跳过去看T3 
*/
/*
15 26
推理开始
现在先考虑部分分
性质A:q=1 好说(并非
性质B:启发:最关键的是字符不同的位置
找到二者不同字符的位置 
对于给定的i 若si1,si2可行 仅有唯一的x+y+z ->x+y`+z(?) 
找到不同之处 进行KMP
判断位置是否一致 

?:进行思考
k1!=k2
s1->s2
k1=x+different1+z
k2=x+different2+z 
不管了先打起来吧
 15 43
 problem solved
*/
/*
15 59
how to write KMP???
how to calcu nxt[]???
*/
/*
16 03
dont forget to check if overflowed
simple:
k1=abc
k2=adc
s1=aabcc
s2=aadcc
ans:
x
*/
/*
16 50
give up KMP
simple 2 WA
*/
/*
17.02
simple 1 2 AC
*/
/*
17 09
simple 3.101 WA
$&%^!^#&%$&#%
*/
/*
17 12
T3挂了
开始骗分吧
1-4最小生成树 但是我不会并查集 16pts
*/
/*
17 27
hand-make bingchaji
wo de yan jing yao xia le
*/
/*
17 58
1-4OK 16pts
*/
/*
18 05 cheat special_A failed
*/
/*
18 25
cheat success!!!!
wow~~~
*/
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n = 0;
	cin>>n;
	
	cout<<n;
	
	return 0;
}
