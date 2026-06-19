/*========employ==========*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
/*========employ==========*/

bitset<500> difficulty;
vector<int> ability;
vector<int> order;
int n,m;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char ch;
		cin>>ch;
		difficulty[i]=ch=='1';
	}
	if(difficulty.count()<m){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		ability.push_back(0);order.push_back(i);
		cin>>ability[i];
	}
	int ans=0;
	do{
		ans%=998244353;
		int death_count=0;
		int success=0;
		for(int i=0;i<n;i++){
			int x=order[i];
			if(difficulty[i]==0||ability[x]<=death_count) death_count++;
			else success++;
		}
		if(success>=m)ans++;
	}while(next_permutation(order.begin(),order.end()));
	cout<<ans%998244353<<endl;
	return 0;
}
