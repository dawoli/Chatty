#include <bits/stdc++.h>
using namespace std;
int n=0,m=0; 
int main(){
	freopen("pocker.in","r",stdin);
	freopen("pocker.out","w",stdout);
	cin >> n;
	char p[120];
	for (int i=0;i<2*n;i++){
		cin >> p[i];
	}
	for (int i=0;i<2*n;i+=2){
		for(int j=i+2;j<2*n;i+=2){
			if(p[i]==p[j]){
				cout << 1 << endl;
				if(p[i+1]==p[j+1]){
					m++;
				}
			}
		}
	}

	for (int i=0;i<2*n;i+=2){
		cout << p[i] ;
		cout << p[i+1] << endl;
	}

	return 0;
}
