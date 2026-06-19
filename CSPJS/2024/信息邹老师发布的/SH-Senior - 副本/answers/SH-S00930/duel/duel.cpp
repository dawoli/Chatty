#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int n,r[100010],cnt[100010],nownum,cntbef,diffnum,ans;
bool fl;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>r[i];
	sort(r,r+n);
	//	cs
//	for(int i=0;i<n;i++)cout<<r[i]<<" ";
//	cout<<endl;
	//	ce
	nownum=r[0];diffnum=1;cnt[1]++;
	for(int i=1;i<n;i++){
		if(r[i]>nownum){
			diffnum++;
			nownum=r[i];
		}
		cnt[diffnum]++;
	}
	//	cs
//	for(int i=1;i<=diffnum;i++)cout<<cnt[i]<<" ";
//	cout<<endl;
	//	ce
	for(int i=2;i<=diffnum;i++){
		cntbef+=cnt[i-1];
		if(cnt[i]-cntbef<=0){
			ans+=cnt[i];
			cntbef-=cnt[i];
		}else{
			ans+=cntbef;
			cntbef=0;
		}
	}
	cout<<n-ans;
	return 0;
}

