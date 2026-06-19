#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tong[5][15];
int main(){
	freopen ("poker.in","r",stdin);
	freopen ("poker.out","w",stdout);
	int n;
	cin>>n;
	char a,b;
	for (int i=0;i<n;i++){
		cin>>a;
		int x;
		if (a=='D'){
			x=0;
			cin>>b;
			if (b=='A'){
				tong[x][0]++;
			}
			else if (b=='2'){
				tong[x][1]++;
			}
			else if (b=='3'){
				tong[x][2]++;
			}
			else if (b=='4'){
				tong[x][3]++;
			}
			else if (b=='5'){
				tong[x][4]++;
			}
			else if (b=='6'){
				tong[x][5]++;
			}
			else if (b=='7'){
				tong[x][6]++;
			}
			else if (b=='8'){
				tong[x][7]++;
			}
			else if (b=='9'){
				tong[x][8]++;
			}
			else if (b=='T'){
				tong[x][9]++;
			}
			else if (b=='J'){
				tong[x][10]++;
			}
			else if (b=='Q'){
				tong[x][11]++;
			}
			else if (b=='K'){
				tong[x][12]++;
			}
		}
		else if (a=='H'){
			x=2;
			cin>>b;
			if (b=='A'){
				tong[x][0]++;
			}
			else if (b=='2'){
				tong[x][1]++;
			}
			else if (b=='3'){
				tong[x][2]++;
			}
			else if (b=='4'){
				tong[x][3]++;
			}
			else if (b=='5'){
				tong[x][4]++;
			}
			else if (b=='6'){
				tong[x][5]++;
			}
			else if (b=='7'){
				tong[x][6]++;
			}
			else if (b=='8'){
				tong[x][7]++;
			}
			else if (b=='9'){
				tong[x][8]++;
			}
			else if (b=='T'){
				tong[x][9]++;
			}
			else if (b=='J'){
				tong[x][10]++;
			}
			else if (b=='Q'){
				tong[x][11]++;
			}
			else if (b=='K'){
				tong[x][12]++;
			}
		}
		else if (a=='S'){
			x=3;
			cin>>b;
			if (b=='A'){
				tong[x][0]++;
			}
			else if (b=='2'){
				tong[x][1]++;
			}
			else if (b=='3'){
				tong[x][2]++;
			}
			else if (b=='4'){
				tong[x][3]++;
			}
			else if (b=='5'){
				tong[x][4]++;
			}
			else if (b=='6'){
				tong[x][5]++;
			}
			else if (b=='7'){
				tong[x][6]++;
			}
			else if (b=='8'){
				tong[x][7]++;
			}
			else if (b=='9'){
				tong[x][8]++;
			}
			else if (b=='T'){
				tong[x][9]++;
			}
			else if (b=='J'){
				tong[x][10]++;
			}
			else if (b=='Q'){
				tong[x][11]++;
			}
			else if (b=='K'){
				tong[x][12]++;
			}
		}
		else if (a=='C'){
			x=1;
			cin>>b;
			if (b=='A'){
				tong[x][0]++;
			}
			else if (b=='2'){
				tong[x][1]++;
			}
			else if (b=='3'){
				tong[x][2]++;
			}
			else if (b=='4'){
				tong[x][3]++;
			}
			else if (b=='5'){
				tong[x][4]++;
			}
			else if (b=='6'){
				tong[x][5]++;
			}
			else if (b=='7'){
				tong[x][6]++;
			}
			else if (b=='8'){
				tong[x][7]++;
			}
			else if (b=='9'){
				tong[x][8]++;
			}
			else if (b=='T'){
				tong[x][9]++;
			}
			else if (b=='J'){
				tong[x][10]++;
			}
			else if (b=='Q'){
				tong[x][11]++;
			}
			else if (b=='K'){
				tong[x][12]++;
			}
		}
	}
	int ans=0;
	for (int i=0;i<4;i++){
		for (int j=0;j<13;j++){
			if (tong[i][j]==0){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
