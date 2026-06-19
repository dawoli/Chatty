#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freoprn("seat.out","w",stdout);
	int n,m;
	int Rans,personalans[n][m],Ransseat;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>personalans[i][j];
			personalans[i][j]=Rans;	
			if(personalans[i][j]>personalans[i][j]){
				swap(personalans[i+1][j+1],personalans[i][j]);
				Ransseat=personalans[i][j];
			}	
		}
	
	
	}

	cout<<Ransseat;
	
} 
