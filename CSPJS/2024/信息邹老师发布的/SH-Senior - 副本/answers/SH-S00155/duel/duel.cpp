#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,r[N],cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n; cnt=n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+1+n);
	int last=1;
	for(int i=2;i<=n;i++){
		if(r[i]>r[last]) cnt--,last++;
	}
	cout<<cnt;
	return 0;
}
