#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[510000],s[510000],ans,vis[510000],f,temp;
int BIT[510000];
int lowbit(int x){
	return x&(-x);
}
void add(int pos,int val){
	for(int i=pos;i<510000;i+=lowbit(i))BIT[i]+=val;
	return;
}
int sumbit(int pos){
	int ret=0;
	for(int i=pos;i>=1;i-=lowbit(i))ret+=BIT[i];
	return ret;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	for(int len=1;len<=n;len++){
		for(int start=1;start<=n-len+1;start++){
			int end=start+len-1;
			if(sumbit(end)-sumbit(start-1)>0)continue;
			if((s[end]^s[start-1])==k){
				ans++;
				for(int i=start;i<=end;i++)add(i,1);
			}
		}
	}
	cout<<ans;
	return 0;
}
