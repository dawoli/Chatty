#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[110][110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,x,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				cnt++;
				b[j][i]=cnt;
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				cnt++;
				b[j][i]=cnt;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	int ans=0;
	for(int i=n*m;i>=1;i--){
		ans++;
		if(a[i]==x){
			x=ans;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==x){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
