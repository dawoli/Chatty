#include<bits/stdc++.h>
using namespace std;

// 我给不起
int a[500005], pre[500005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k, x, cnt=0;
	cin>>n>>k;
	bool flag=true, flag2=true;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)flag2=false;
		if(a[i]!=1)flag=false;
		pre[i]=pre[i-1]^a[i];
//		cout<<pre[i]<<endl;
	}
	if(flag) {
		cout<<n/2;
		return 0;
	} else if(flag2) {
		int onecnt=0, zerocnt=0, qj=0;
		if(k==1) {
			for(int i=1; i<=n; i++) {
				if(a[i]==1)onecnt++;
			}
			cout<<onecnt;
		}else{
			for(int i=1; i<=n; i++) {
				if(a[i]==0)zerocnt++;
				else if(a[i+1]==1){
				qj++;i++;}
			}
			cout<<zerocnt + qj;
		}
		return 0;
	}


	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if((pre[j]^pre[i-1])==k) {
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
// 我给不起
