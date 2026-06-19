#include<bits/stdc++.h>
using namespace std;
int a[100010],n,ans,tmp;
int main(){
	cin>>n;
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),++a[x];
	for(int i=1;i<=100000;++i)
	    if(a[i])
	    	ans-=min(a[i],a[tmp]),tmp=i;
	cout<<ans+n;
}
