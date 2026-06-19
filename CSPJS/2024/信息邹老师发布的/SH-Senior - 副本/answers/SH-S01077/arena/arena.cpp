#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x^=x;
	int f=1;
	char a=getchar();
	while('0'>a||a>'9'){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x*=10;
		x+=a-'0';
		a=getchar();
	}
	x*=f;
	return ;
}
const int SIZE=100009;
struct node{
	int id,a;
}a[SIZE];
int n,m,A[SIZE],c[SIZE],T,x[4],d[SIZE],ans[SIZE],res,D[SIZE];
int work(node *num,int len,int t){
	int i,j,v,v0,top=0,temp=d[t];
	node stk[SIZE];
	for(i=len,j=2*len-1;i>=1,j>=1;i--,j-=2){
		if(d[t]%10==1)v=j+1,v0=j;
		else v=j,v0=j+1;
		d[t]/=10;
		top++;
		if(t<=num[v].a)stk[top]=num[v];
		else stk[top]=num[v0];
	}
	d[t]=temp;
	if(top==1)return stk[top].id;
	return work(stk,top,t*2);
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	read(n);
	read(m);
	int i;
	for(i=1;i<=n;i++)read(A[i]);
	for(i=1;i<=m;i++)read(c[i]);
	for(i=1;i<=n;i*=2)read(d[i]),D[n-i+1]=i;
	read(T);
	while(T--){
		for(i=0;i<4;i++)read(x[i]);
		for(i=1;i<=n;i++){
			a[i]=(node){i,A[i]^x[i%4]};
		}
		res^=res;
		for(i=1;i<=n;i*=2)ans[i]=work(a,D[n-i+1],i);
		for(i=1;i<=m;i++)res^=(i*ans[c[i]]);
		printf("%d\n",res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
