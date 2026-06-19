#include<bits/stdc++.h>
using namespace std;
int a[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	char huase,dianshu;
	for(int i=1;i<=n;++i){
		cin>>huase>>dianshu;
		if(huase=='D'){
			if(dianshu>='2'&&dianshu<='9'){
				a[1][dianshu-'0']++;
			}
			else if(dianshu=='A'){
				a[1][1]++;
			}
			else if(dianshu=='T'){
				a[1][10]++;
			}
			else if(dianshu=='J'){
				a[1][11]++;
			}
			else if(dianshu=='Q'){
				a[1][12]++;
			}
			else if(dianshu=='K'){
				a[1][13]++;
			}
		}
		if(huase=='C'){
			if(dianshu>='2'&&dianshu<='9'){
				a[2][dianshu-'0']++;
			}
			else if(dianshu=='A'){
				a[2][1]++;
			}
			else if(dianshu=='T'){
				a[2][10]++;
			}
			else if(dianshu=='J'){
				a[2][11]++;
			}
			else if(dianshu=='Q'){
				a[2][12]++;
			}
			else if(dianshu=='K'){
				a[2][13]++;
			}
		}
		if(huase=='H'){
			if(dianshu>='2'&&dianshu<='9'){
				a[3][dianshu-'0']++;
			}
			else if(dianshu=='A'){
				a[3][1]++;
			}
			else if(dianshu=='T'){
				a[3][10]++;
			}
			else if(dianshu=='J'){
				a[3][11]++;
			}
			else if(dianshu=='Q'){
				a[3][12]++;
			}
			else if(dianshu=='K'){
				a[3][13]++;
			}
		}
		if(huase=='S'){
			if(dianshu>='2'&&dianshu<='9'){
				a[4][dianshu-'0']++;
			}
			else if(dianshu=='A'){
				a[4][1]++;
			}
			else if(dianshu=='T'){
				a[4][10]++;
			}
			else if(dianshu=='J'){
				a[4][11]++;
			}
			else if(dianshu=='Q'){
				a[4][12]++;
			}
			else if(dianshu=='K'){
				a[4][13]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=4;++i){
		for(int j=1;j<=13;++j){
			if(a[i][j]==0){
				ans++;
			}
		}
	}
	cout<<ans; 
	return 0;
}
