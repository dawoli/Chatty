#include<bits/stdc++.h>
using namespace std;

int n,m;
int r,x;
int l=1,w=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<n*m;i++){
		if(l%2!=0&&w==m+1) l++;
		else if(l%2==0&&w==1) l++;
		cin>>x;
		if(x<r) continue;
		else{
			if(l%2!=0) w++;
			else w--;
		}
	}
	cout<<l<<" "<<w;
	return 0;
}
