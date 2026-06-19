#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,ls,lst,a[100010],g[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;m=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1])g[i]=g[i-1]+1;
		else g[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			int k=min(g[i],ls);
			//cout<<a[i]<<' '<<g[i]<<' '<<ls<<endl;
			ls+=g[i];
			ls-=k;
			m-=k;
		}
	}cout<<m<<endl;
	return 0;
}

