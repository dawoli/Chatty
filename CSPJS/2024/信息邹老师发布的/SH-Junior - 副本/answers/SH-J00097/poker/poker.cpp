#include <bits/stdc++.h>
using namespace std;
	bool p[4][13];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int ans=52;
	int n;
	cin>>n;
		for (int i=0;i<n;i++){
		
		char x[3]={""};
		cin>>x[1]>>x[2];
		if (('2'<=x[2])&&(x[2]<='9')){
			if (x[1]=='D'){
				p[0][x[2]-'0'-1]=1;
			}
			else if (x[1]=='C'){
				p[1][x[2]-'0'-1]=1;
			}
			else if (x[1]=='H'){
				p[2][x[2]-'0'-1]=1;
			}
			else if (x[1]=='S'){
				p[3][x[2]-'0'-1]=1;
			}
		}
		else{
			if (x[2]=='A'){
				if (x[1]=='D'){
					p[0][0]=1;
				}
				else if (x[1]=='C'){
					p[1][0]=1;
				}
				else if (x[1]=='H'){
					p[2][0]=1;
				}
				else if (x[1]=='S'){
					p[3][0]=1;
				}
			}
			if (x[2]=='T'){
				if (x[1]=='D'){
					p[0][9]=1;
				}
				else if (x[1]=='C'){
					p[1][9]=1;
				}
				else if (x[1]=='H'){
					p[2][9]=1;
				}
				else if (x[1]=='S'){
					p[3][9]=1;
				}
			}
			if (x[2]=='J'){
				if (x[1]=='D'){
					p[0][10]=1;
				}
				else if (x[1]=='C'){
					p[1][10]=1;
				}
				else if (x[1]=='H'){
					p[2][10]=1;
				}
				else if (x[1]=='S'){
					p[3][10]=1;
				}
			}
			if (x[2]=='Q'){
				if (x[1]=='D'){
					p[0][11]=1;
				}
				else if (x[1]=='C'){
					p[1][11]=1;
				}
				else if (x[1]=='H'){
					p[2][11]=1;
				}
				else if (x[1]=='S'){
					p[3][11]=1;
				}
			}
			if (x[2]=='K'){
				if (x[1]=='D'){
					p[0][12]=1;
				}
				else if (x[1]=='C'){
					p[1][12]=1;
				}
				else if (x[1]=='H'){
					p[2][12]=1;
				}
				else if (x[1]=='S'){
					p[3][12]=1;
				}
			}
		}
		}
	
	for (int i=0;i<4;i++){
		for (int j=0;j<13;j++){
			ans-=p[i][j];
		}
	}
	cout<<ans;
	return 0;
}
