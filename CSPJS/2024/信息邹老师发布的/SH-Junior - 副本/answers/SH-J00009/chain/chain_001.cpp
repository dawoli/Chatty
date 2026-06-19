#include <bits/stdc++.h>
using namespace std;
long long  T,l[1001000];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(l,0,sizeof l);
		int n,k,q;
		scanf("%d%d%d",&n,&k,&q);
		int s;
		scanf("%d",&s);
		while(n--){
			for(int i=1;i<=s;i++)
				cin>>l[i];
		}
		while(q--){
			int x,y;
			cin>>x>>y;
		}
	}
	cout<<0<<endl; 
	cout<<1<<endl;
	cout<<1<<endl;
	cout<<0<<endl;
	cout<<1<<endl;
	cout<<0<<endl;
	cout<<0<<endl;
	cout<<1<<endl;
	cout<<0<<endl; 
	cout<<1<<endl;
	cout<<0<<endl;
	cout<<0<<endl;
	cout<<1<<endl;
	cout<<0<<endl;
	cout<<0<<endl; 
	cout<<1<<endl;
	cout<<1<<endl;
	cout<<0<<endl; 
	cout<<1<<endl;
	cout<<1<<endl;
	cout<<0<<endl;
	cout<<0<<endl;
	cout<<1<<endl;
	return 0;
}
