#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,r[N],id,cnt[N],sur;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	sort(r+1,r+n+1);
	id=1,cnt[1]=1;
	int t=r[1];
	for(int i=2;i<=n;i++)
		if(r[i]!=t)id++,cnt[id]++,t=r[i];
		else cnt[id]++;
	if(id==1){
		cout<<n;
		return 0;
	}
	else{
		int ii=2;
		sur=cnt[1];
		while(ii<=id)
			if(cnt[ii]>sur) sur=cnt[ii],ii++;
			else ii++;
		cout<<sur;
		return 0;
	}
}
