#include<bits/stdc++.h>
using namespace std;
int n,m; 
int sc[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
	}
	int temp=sc[1];
	sort(sc+1,sc+n*m+1);
	int treat[150];
	for(int i=1,j=m*n;i<=m*n,j>=0;i++,j--){
		treat[i]=sc[j];
	}
	int i=1,j=1,cnt=n*m,idx=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(treat[idx]==temp){
				if(i%2==1){
					cout<<i<<" "<<j;
					return 0;
				}else{
					cout<<i<<" "<<n-j+1;
					return 0;
				}
			}
			idx++;
		}
	}
	
	return 0;
}
//csh
