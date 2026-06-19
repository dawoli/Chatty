#include<bits/stdc++.h>
using namespace std;
int n,w[4][13],ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string a;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		int j,k;
		if(a[0]=='D') k=0;
		else if(a[0]=='C') k=1;
		else if(a[0]=='H') k=2;
		else if(a[0]=='S') k=3;
		if(a[1]=='A') j=0;
		else if(a[1]=='T') j=9;
		else if(a[1]=='J') j=10;
		else if(a[1]=='Q') j=11;
		else if(a[1]=='K') j=12;
		else j=a[1]-49; 
		if(w[k][j]==0){
			w[k][j]=1;
			ans--;
		}
	}
	cout << ans;
	return 0;
}
