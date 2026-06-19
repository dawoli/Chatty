#include<bits/stdc++.h>
#define N 200005
using namespace std;
int T,n;
int a[N];
int red,blue,maxn;
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
}
void dfs(int st,int sum){
//	printf("%d %d %d %d\n",st,sum,red,blue);
	int tmp;
	if(st==n){
		maxn=max(maxn,sum);
		return;
	}
	int add=0;
	if(red && a[red]==a[st+1])
		add=a[red];
	tmp=red;
	red=st+1;
	dfs(st+1,sum+add);
	red=tmp;
	add=0;
	
	if(blue && a[blue]==a[st+1])
		add=a[blue];
	tmp=blue;
	blue=st+1;
	dfs(st+1,sum+add);
	blue=tmp;
}
void init(){
	red=0; blue=0;
	maxn=0;
}
void output(int i){
	printf("%d",maxn);
	if(i!=T) printf("\n");
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		input();
		init();
		dfs(0,0);
		output(i);
	}
	return 0;
}

