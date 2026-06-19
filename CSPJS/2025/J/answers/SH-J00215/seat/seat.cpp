#include<bits/stdc++.h>
using namespace std;
int a[107];
int ans[17][17];
int main(){
	freopen("seat,in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		a[i]=-a[i];
	}
	int pos=-a[0];
	sort(a,a+n*m);
	int idx=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				ans[j][i]=-a[idx];
				idx++;
			}
		}
		else{
			for(int j=m-1;j>=0;j--){
				ans[j][i]=-a[idx];
				idx++;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(ans[i][j]==pos){
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	return 0;
}
