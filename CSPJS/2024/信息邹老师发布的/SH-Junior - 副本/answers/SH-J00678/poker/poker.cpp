#include <iostream>
using namespace std;

int n,ans;
bool pok[5][20];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin >> n;
	for(int i=0;i<n;i++){
		char col,poi;
		int ic,ip;
		cin >> col >> poi;
		if(col=='D'){
			ic=1;
		}
		if(col=='C'){
			ic=2;
		}
		if(col=='H'){
			ic=3;
		}
		if(col=='S'){
			ic=4;
		}
		if(poi=='A'){
			ip=1;
		}else if(poi=='T'){
			ip=10;
		}else if(poi=='J'){
			ip=11;
		}else if(poi=='Q'){
			ip=12;
		}else if(poi=='K'){
			ip=13;
		}else{
			ip=poi-'0';
		}
		pok[ic][ip]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!pok[i][j]) ans++;
		}
	}
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
