#include<bits/stdc++.h>
using namespace std;
int n,ans,a,head;
int r[100010],nex[100010]={},fl[100010]={};
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	cin>>a;r[a]++;fl[a]=1;
	head=a;
	cin>>a;r[a]++;fl[a]=1;
	nex[head]=a;
	for(int i=1;i<n-1;i++) {
		cin>>a;r[a]++;
		if(fl[a]) continue;
		fl[a]=1;
		if(a<head)
			{nex[a]=head;head=a;}
		if(a>head) {
			if(a>nex[head]) nex[nex[head]]=a;
			if(a<nex[head]) {
				nex[a]=nex[head];
				nex[head]=a;
			}
		}
	}
	while(nex[head]) {
		if(r[head]<=r[nex[head]]) {
			ans-=r[head];
			head=nex[head];
		}
		if(r[head]>r[nex[head]]) {
			ans-=r[nex[head]];
			nex[head]=nex[nex[head]];
		}
	}
	cout<<ans<<endl;
	return 0;
}
