#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],sum,cnt=1,r,s[15][15];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	sum=n*m;
	for (int i=1;i<=sum;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a,a+sum+1);
	int now=sum;
	for (int i=1;i<=m;i++){
		
		if (i%2==1){
			for (int j=1;j<=n;j++){
				s[j][i]=a[now];
				now--;
			}
		}
		else{
			for (int j=n;j>=1;j--){
				s[j][i]=a[now];
				now--;
			}
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (s[j][i]==r){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
