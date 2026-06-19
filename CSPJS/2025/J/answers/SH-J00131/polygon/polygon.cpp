//polygon
#include<bits/stdc++.h>
typedef long long ll;
#define mod 998244353  
using namespace std;
int n;
int a[5010]; 
int cnt=0;
void dfs(int k,vector<int> vec){
	if(k>=n){
		if(vec.size()<3) return;
		int maxn=vec[0];
		int sum=0;
		for(int i=0;i<vec.size();i++){
			sum+=vec[i];
			if(sum>2*maxn){
//				cout<<"debug:";
//				for(int j=0;j<vec.size();j++){
//					cout<<vec[j]<<" ";
//				}
//				cout<<endl;
				cnt++;
				cnt%=mod;
				return;
			}
		}
	}
	else{
		dfs(k+1,vec);
		vec.push_back(a[k]);
		dfs(k+1,vec);
		return;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	if(a[0]==1){
		ll ans=1;
		for(int i=0;i<n;i++){
			ans*=2;
			ans%=mod;
		}
		ll ans2=(ll)n*(n-1)/2;
		cout<<ans-(ll)n-1-ans2<<endl;
		return 0;
	}
	dfs(0,{});
	cout<<cnt;
	return 0;	
}
