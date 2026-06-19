#include<bits/stdc++.h>
using namespace std;
int n,m;
int sc[122];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>sc[i];
	}
	int r=sc[0];
	int ad=0;
	sort(sc,sc+(n*m),greater<int>());
	for(int i=0;i<(n*m);i++){
		if(sc[i]==r){
			ad=i;
			break;
		}
	}
	//cout<<ad<<endl; 
	if((ad/n)%2==0){
		int h=(ad%n)+1;
		int l=(ad/n)+1;
		cout<<l<<" "<<h;
	}
	else{
		int l=(ad/n)+1;
		int h=n-(ad%n);
		cout<<l<<" "<<h;
	}
	return 0;
}
