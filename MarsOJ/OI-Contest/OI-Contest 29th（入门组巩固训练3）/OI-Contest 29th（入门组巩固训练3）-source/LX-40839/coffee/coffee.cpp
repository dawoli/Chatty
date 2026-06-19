#include<bits/stdc++.h>
using namespace std;
int q;
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>q;
	while(q--){
		long long d[10];
		for(int i=0;i<10;i++) d[i]=0;
		for(int i=0;i<5;i++){
			for(int j=1;j<=8;j++){
				string s;
				cin>>s;
				if(s[0]=='m') d[i]++;
			}
		}
		long long n,m;
		cin>>n>>m;
		long long w=n/7,t=n%7,sum=0;
		for(long long i=0;i<5;i++) sum+=d[i];
		long long ans=w*sum;
		if(t!=0){
			for(long long i=m-1;i<t+m-1;i++){
				ans+=d[i%7];
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
} 
