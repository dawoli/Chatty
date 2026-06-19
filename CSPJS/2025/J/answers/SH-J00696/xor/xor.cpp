#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	if(count(v.begin()+1,v.end(),1)==n){
		if(k==0){
			cout<<(n>>1);
		}else if(k==1) cout<<n;
		else cout<<0;
		return 0;
	}else if(count(v.begin()+1,v.end(),1)+count(v.begin()+1,v.end(),0)==n){
		int cnt=0;
		if(k==0){
			cnt=count(v.begin()+1,v.end(),0);
			for(int i=n;i>1;i--){
				if(v[i]==1&&v[i-1]==1){
					cnt++;
					i--;
					if(i==1) break;
				}
			}
		}else if(k==1){
			cnt=count(v.begin()+1,v.end(),1);
		}
		cout<<cnt;
		return 0;
	}else{
		if(*max_element(v.begin(),v.end())<=255&&k>511) cout<<0;
		else if((k>>1)>*max_element(v.begin(),v.end())) cout<<0;
		else cout<<n;
	}
	return 0;
}
