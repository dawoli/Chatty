#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=0;ii<t;ii++){
		int ans=0;
		map<int,int>mp;
		vector<int>v;
		int n;
		cin>>n;
		int l[n];
		for(int i=0;i<n;i++)
		cin>>l[i];
		for(int i=0;i<n;i++)
			mp[l[i]]++;
		for(int i=0;i<n;i++)
			if(mp[l[i]]>1)
				ans+=l[i];
		cout<<ans;
		
	}
}
