#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,num=1,hang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1)continue;
			cin>>b;
			if(a<b)num++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				num--;
				if(num==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				num--;
				if(num==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	cout<<m<<" "<<n;
	return 0;
} 
