#include <bits/stdc++.h>
using namespace std;
int b[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int tmp=b[1];
	int ans=1;
	for(int i=2;i<=n*m;i++){
		if(tmp<=b[i]) ans++;
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				cnt++;
				if(ans==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else {
			for(int j=1;j<=n;j++){
				cnt++;
				if(ans==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
