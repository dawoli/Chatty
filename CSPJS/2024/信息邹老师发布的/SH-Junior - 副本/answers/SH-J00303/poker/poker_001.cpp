#include<bits/stdc++.h>
using namespace std;
int n;
char a[55][2];
int b[5][15];
//C S H D
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i][0]=='C'){
			if(a[i][1]>='2'&&a[i][1]<='9'){
				b[1][(a[i][1])-48]++;
			}
			else{
				if(a[i][1]=='A'){
					b[1][1]++;
				}
				if(a[i][1]=='T'){
					b[1][10]++;
				}
				if(a[i][1]=='J'){
					b[1][11]++;
				}
				if(a[i][1]=='Q'){
					b[1][12]++;
				}
				if(a[i][1]=='K'){
					b[1][13]++;
				}
			}
		}
		if(a[i][0]=='S'){
			if(a[i][1]>='2'&&a[i][1]<='9'){
				b[2][(a[i][1])-48]++;
			}
			else{
				if(a[i][1]=='A'){
					b[2][1]++;
				}
				if(a[i][1]=='T'){
					b[2][10]++;
				}
				if(a[i][1]=='J'){
					b[2][11]++;
				}
				if(a[i][1]=='Q'){
					b[2][12]++;
				}
				if(a[i][1]=='K'){
					b[2][13]++;
				}
			}
		}
		if(a[i][0]=='H'){
			if(a[i][1]>='2'&&a[i][1]<='9'){
				b[3][(a[i][1])-48]++;
			}
			else{
				if(a[i][1]=='A'){
					b[3][1]++;
				}
				if(a[i][1]=='T'){
					b[3][10]++;
				}
				if(a[i][1]=='J'){
					b[3][11]++;
				}
				if(a[i][1]=='Q'){
					b[3][12]++;
				}
				if(a[i][1]=='K'){
					b[3][13]++;
				}
			}
		}
		if(a[i][0]=='D'){
			if(a[i][1]>='2'&&a[i][1]<='9'){
				b[4][(a[i][1])-48]++;
			}
			else{
				if(a[i][1]=='A'){
					b[4][1]++;
				}
				if(a[i][1]=='T'){
					b[4][10]++;
				}
				if(a[i][1]=='J'){
					b[4][11]++;
				}
				if(a[i][1]=='Q'){
					b[4][12]++;
				}
				if(a[i][1]=='K'){
					b[4][13]++;
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(b[i][j]==0){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
