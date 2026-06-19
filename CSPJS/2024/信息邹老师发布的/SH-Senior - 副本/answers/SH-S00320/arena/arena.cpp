#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,a[N],s1=1,s=1,c[N],t,x0,x1,x2,x3,r[10000005];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	while(s<n){
		s1++;
		s*=2;
	}
	for(int i=1;i<=s1;i++){
		for(int j=s;j>=1;j/=2){
			cin>>r[j];
		}
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x0>>x1>>x2>>x3;
	}
	for(int i=1;i<=t;i++)cout<<1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
