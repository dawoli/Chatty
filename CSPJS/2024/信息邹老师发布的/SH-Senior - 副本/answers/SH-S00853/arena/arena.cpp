/*【输入格式】
从文件 arena.in 中读入数据。
本题的测试点包 含 有 多 组 测 试 数 据 ，但不同测试数据只是通过修改a1, a2,..., an 得到，
其他内容均保持不变，请参考以下格式。其中 ^ 代表异或运算符，a % b 代表 a除以 b 的余数。

输入的第一行包含两个正整数 n, m，表示报名的选手数量和询问的数量。
输入的第二行包含 n 个非负整数 a′1, a′2,..., a′n，这列数将用来计算真正的能力值。
输入的第三行包含 m 个正整数 c1, c2,..., cm，表示询问。
设 K 是使得 2**K ≥ n 的最小的非负整数，接下来的 K 行当中，第R行包含 2**(K-R)个数（无空格），
其中第 G 个数表示第 R 轮的第 G 场比赛抽签得到的 d(R,G) = 0/1。
*由于询问只是将人数凑齐到 2**k ≥ ci，这里的 k ≤ K，因此你未必会用到全部的输入值。
接下来一行包含一个正整数 T，表示有 T 组测试数据。
接下来共 T 行，每行描述一组数据，包含 4 个非负整数 X0, X1, X2, X3，
该组数据的能力值 ai = a′i ^ X(i % 4)，其中 1 ≤ i ≤ n。
【输出格式】
输出到文件 arena.out 中。
共输出 T 行，对于每组数据，设 Ai 为第 i（1 ≤ i ≤ m）组询问的答案，
你只需要输出一行包含一个整数，表示 (1 * A1) ^ (2 * A2) ^...^ (m * Am) 的结果。
【样例 1 输入】
5 5
0 0 0 0 0
5 4 1 2 3
1001
10
1
4
2 1 0 0
1 2 1 0
0 2 3 1
2 2 0 1
【样例 1 输出】
5
19
7
1

HF#24THMC
Z*L#LH%9
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,G=70000;
int n,m,r=1,g=1,t;
char ch;
int al[N],a[N],c[N],ax[4];
bool drg[17][G];
int main(){
  freopen("arena.in","r",stdin);
  freopen("arena.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
  	scanf("%d",&al[i]);
  	a[i]=al[i];
  }
  for(int i=1;i<=m;i++){
  	scanf("%d",&c[i]);
  }
  while(ch=getchar()){
  	if(ch!='0'&&ch!='1'&&ch!='\n') break;
  	if(ch=='\n'){
  	  r++;
  	  g=1;
  	  continue;
	}
	drg[r][g]=ch-'0';
	g++;
  }
  t=ch-'0';
  while(t--){
  	for(int i=0;i<4;i++){
  	  scanf("%d",&ax[i]);
	}
  	for(int i=1;i<=n;i++){
  	  a[i]=al[i];
  	  a[i]^=ax[i%4];
    }
  }
  return 0;
}
