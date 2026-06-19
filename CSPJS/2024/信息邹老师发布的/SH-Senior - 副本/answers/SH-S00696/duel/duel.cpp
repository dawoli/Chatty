#include<bits/stdc++.h>
using namespace std;
int N,a[1000000],b,c[1000000],f;
int read(){
	char c;int s;
	c=getchar();
	while(c<'0'||c>'9') c= getchar();
	s=c-'0';
	c=getchar();
	while(c>='0'&&c<='9'){
		s=c-'0'+s*10;
		c=getchar();
	}
	return s;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	N=read();
	int maxn=0;
	for(int i=1;i<=N;i++){
		int n=read();
		a[n]++;//jingong
		c[n]++;//fangshou
		maxn=max(maxn,n);
	}
	for(int i=1;i<=maxn;i++){
		if(c[i]==0) continue;
		if(f!=0||i==maxn) b+=c[i];
		else
			for(int j=i+1;j<=maxn;j++){
				if(a[j]==0) continue;
				if(a[j]>=c[i])				
					a[j]-=c[i],c[i]=0;
				else c[i]-=a[j],a[j]=0;
				if(a[maxn]==0){
					f=1;
					b=c[i];
					break;
				}
			}
	}
	cout<<b<<'\n';
	return 0;
}
