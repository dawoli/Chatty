#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*w;
}
const int MAXN=1e5+10;
int n,r[MAXN];
bool vis[MAXN];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		r[i]=read();
	} 
	sort(r+1,r+n+1);
	int sum=0;
	r[0]=MAXN;
	r[n+1]=0;
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(vis[i]==false&&r[j]<r[i]){
				r[j]=MAXN;
				vis[i]=true;
				sum++;
				}
			}	
		if(r[i]<r[i+1]&&vis[i+1]==false){
			sum++;
			vis[i+1]=true;
			r[i]=MAXN;
		}
	} 
	cout<<n-sum<<endl;
	return 0;
}

