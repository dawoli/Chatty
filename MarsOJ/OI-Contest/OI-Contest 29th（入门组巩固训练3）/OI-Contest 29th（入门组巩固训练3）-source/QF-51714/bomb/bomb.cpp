#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int main()
{
	freopen("bomb.in",r,stdin);
	freopen("bomb.out",w,stdout);
	while(T--){
		cin>>n>>m;
		string s[1001][1001];
		int mu=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
				if(s[i][j]=="$")mu++;
			}
		}
		if(n==1){
			cout<<mu<<" "<<m-1<<endl;
			continue;
		}
		if(mu==0){
			cout<<0<<" ";
			int lx=n+m-2;
			cout<<lx<<endl;
		}
	}
}
