#include <bits/stdc++.h>
using namespace std;
int n,m,a[121],s[11][11];
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.ans","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	int b=a[0];
	for(int i=1;i<n*m;i++) cin>>a[i];
	sort(a,a+n*m);
	int t=n*m-1;
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				s[i][j]=a[t],t--;
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				s[i][j]=a[t],t--;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]==b){
				cout<<i+1<<" "<<j+1;
				return 0; 
			}
		}
	}
}
