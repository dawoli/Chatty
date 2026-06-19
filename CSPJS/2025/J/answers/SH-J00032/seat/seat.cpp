#include<bits/stdc++.h>
using namespace std;
int n,m,a[1009],cnt=1,a1,r,hang=1,lie,cnt1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a1==a[i]) break;
		cnt++;
	}
	cnt1=cnt;
	while(1){
		if(cnt1-n>0) cnt1-=n,hang++;
		else{
			r=cnt1;
			break;
		}
	}
	if(hang%2==1) lie=r;
	if(hang%2==0) lie=n+1-r;
	cout<<hang<<" "<<lie;
	return 0;
}
