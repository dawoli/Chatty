#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

long long n,m,ans=1,k,pl;
long long a[1005];
string s;


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	k=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;k<=n;i++){
		while(pl>=a[k]){
			pl++;
			k++;
			if(k>n){
				break;
			}
		}
		if(k<=n){
			ans*=i;
			ans%=mod;
			k++;
		}
		
	}
	cout<<ans;
	
	
	
	
	return 0;
}
