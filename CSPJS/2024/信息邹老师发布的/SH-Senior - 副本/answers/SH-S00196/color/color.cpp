#include<bits/stdc++.h>
using namespace std;
bool dp[2008][2008];
long long a[2008],n,anss,ans,t;
queue<long long> fi,se;
//string ;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n<=15){
			long long turns=pow(2,n+1);
			for(long long i=0;i<turns;i+=2){
				anss=0;
				for(long long j=1;j<=n;j++){
					long long mp=pow(2,j);
					if(i & mp ) fi.push(a[j]);
					else se.push(a[j]);
				}
				while(fi.size()>=2){
					int l=fi.front();fi.pop();int r=fi.front();
					if(l==r) anss+=l;
					//cout<<l<<' '; 
				}
				fi.pop();
				//cout<<"-------";
				while(se.size()>=2){
					int l=se.front();se.pop();int r=se.front();
					if(l==r) anss+=l;
					//cout<<l<<' ';
				}
				se.pop();
				ans=max(anss,ans);
				//cout<<'\n';
			}
			cout<<ans<<'\n';
			ans=0;
			continue;
		}else{
			
		}
	}
	return 0;
} //pdf pwd Z*L#LH%9
//rp++ lllllllllllllllllll
