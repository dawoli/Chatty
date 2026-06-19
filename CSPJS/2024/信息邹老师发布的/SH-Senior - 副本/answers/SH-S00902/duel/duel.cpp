#include<bits/stdc++.h>

using namespace std;

ifstream fin("duel.in");
ofstream fout("duel.out");
#define cin fin
#define cout fout

int main(){
	int n,ans=0;
	cin>>n;
	
	map<int,int> mp;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		mp[x]++;
		ans=max(ans,mp[x]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
