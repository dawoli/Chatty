#include<bits/stdc++.h>
using namespace std;
int T,n;
struct{
	int a[100005],w;
}ans[100];
int main(){
	//freopen("sticks.in","r",stdin);
	//freopen("sticks.out","w",stdout);
	cin>>T;
	
	for(int i = 1;i<=T;++i){
		cin>>n;
		if(n%7==0){
			ans[i].a[0]=8;
			ans[i].w+=(n/7-1);
			for(int j = 1;j<n/7;++j)
				ans[i].a[j]=8;
		}
		if(n%7==1&&n>1){
			ans[i].a[0]=16;
			ans[i].w+=(n-8)/7;
			for(int j = 1;j<=(n-8)/7;++j)
				ans[i].a[j]=8;
		}
		if(n<2)
			ans[i].a[0]=-1;
	}
	for(int i = 1;i<=T;++i){
		for(int j = 0;j<=ans[i].w;++j)
			cout<<ans[i].a[j];
		cout<<endl;
	}
	return 0;	
}
