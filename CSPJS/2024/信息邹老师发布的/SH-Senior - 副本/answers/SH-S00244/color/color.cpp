#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x-x;
	if(x>10)write(x/10);
	putchar(x%10+'0');
}
const int N=6005;
int f[N][N],a[N],s[N],T,n;
/*
设v(i,j)为a[i]*a[i]==a[j]
s数组为v(i-1,i)的前缀和 
f[j][i]表示当前块为[j,i]时, 前i个数的最大得分
转移方程枚举上上块的块尾k
f[j][i] =max{f[k+1][j-1]+v(k,j)+sum{v(x-1,x)}(x∈[j+1,i])}
		=max{f[k+1][j-1]+v(k,j)+s[i]-s[j]}
*/
int main(){
	file();
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]*(a[i-1]==a[i]);
		for(int i=1;i<=n;i++){
			f[1][i]=s[i];
			for(int j=2;j<=i;j++){
				f[j][i]=0;
				for(int k=0;k<=j-2;k++)
					f[j][i]=max(f[j][i],f[k+1][j-1]+a[j]*(a[k]==a[j])+s[i]-s[j]);
			}
		}
		int res=0;
		for(int j=1;j<=n;j++)res=max(res,f[j][n]);
		write(res),puts("");
	}
	return 0;
}
