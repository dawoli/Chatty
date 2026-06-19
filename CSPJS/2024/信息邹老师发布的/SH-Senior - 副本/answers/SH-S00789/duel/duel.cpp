#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,r[N],cnt=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	r[0]=0;
	sort(r+1,r+n+1);
	for(int i=1,j;i<=n;i=j){
		j=i;
		while(r[j]==r[i]) j++;
		cnt=max(cnt,j-i);
	}
	cout<<cnt;
	return 0;
}

