#include<bits/stdc++.h>
using namespace std;
int n,q[100010],cnt,c;
 map<int,int>mp;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int ans=n;
	for(int i=1,a;i<=n;i++){
		cin>>a;
		mp[a]++;
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();){
		int b1=it->second;
		it++;
		int b2=it->second;
		
		if(b1<=b2)ans-=b1;
		else q[++cnt]=b1,c=max(c,b1);
	}
	for(int i=1;i<=cnt;i++)ans-=q[i];
	cout<<ans+c;
}
