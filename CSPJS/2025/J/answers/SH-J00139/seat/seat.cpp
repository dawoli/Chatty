#include<bits/stdc++.h>
using namespace std;
bool f[123],infr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[123],l,pai=0,x=1,y=1;
	cin>>n>>m;
	l=n*m;
	for(int i=0;i<l;i++){
		cin>>a[i];
		f[a[i]]=true;
	}
	for(int i=100;i>=0;i--){
		if(f[i]){
			pai++;
		}
		if(i==a[0]){
			break;
		}
	}
	while(pai>1){
		if(!infr){
			if(y==n){
				x++;
				infr=true;
			}
			else{
				y++;
			}
		}
		else{
			if(y==1){
				x++;
				infr=false;
			}
			else{
				y--;
			}
		}
		pai--;
	}
	cout<<x<<" "<<y;
} 
