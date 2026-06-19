#include<bits/stdc++.h>
using namespace std;
int inn,mee;
int n,m,bigger(0),nn,mm;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>mee;
	for (int i=1;i<n*m;i++){
		cin>>inn;
		if (inn>mee){
			bigger++;
		}
	}
	nn=bigger/m+1;
	if (nn%2==0){
		mm=m-bigger%m;
	}
	else{
		mm=bigger%m+1;
	}
	cout<<nn<<' '<<mm<<endl;
	return 0;
}
