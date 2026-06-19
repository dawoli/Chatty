#include<bits/stdc++.h>
using namespace std;
int n,x=0,ans;
int num[100005],cnt[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&num[i]);
	sort(num,num+n);
	cnt[0]=1;
	for(int i=1;i<n;i++){
		if(num[i]==num[i-1]) cnt[x]++;
		else x++,cnt[x]++;
	}
	for(int i=1;i<=x;i++)
		if(cnt[i-1]>=cnt[i]) cnt[i]=cnt[i-1];
	printf("%d",cnt[x]);
	return 0;
}
