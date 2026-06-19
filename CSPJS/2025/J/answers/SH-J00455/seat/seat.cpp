#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>=b;
}
int a[11][11];
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int c=b[1];
	sort(b+1,b+n*m+1,cmp);
	int nowi=1,nowj=1,nowb=1;
	for (int j=1;j<=m;j++){
		for (int i=1;i<=n;i++){
			a[nowi][nowj]=b[nowb];
			if (j%2==1){
				nowi++;
			}
			else{
				nowi--;
			}
			nowb++;
		}
		nowj++;
		if (j%2==1){
			nowi--;
		}
		else{
			nowi++;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]==c){
				cout<<j<<" "<<i;
				break;
			}
			
		}
		cout<<endl;
	}
	return 0;
}
