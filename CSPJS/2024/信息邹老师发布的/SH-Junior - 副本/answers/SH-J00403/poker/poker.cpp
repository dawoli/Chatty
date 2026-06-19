#include<bits/stdc++.h>
using namespace std;
int a[6][15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s[0]=='D'){
			if(s[1]=='A'){
				a[1][1]++;
			}
			else if(s[1]>='2'&&s[1]<='9'){
				a[1][s[1]-'1']++;
			}
			else if(s[1]=='T'){
				a[1][10]++;
			}
			else if(s[1]=='J'){
				a[1][11]++;
			}
			else if(s[1]=='Q'){
				a[1][12]++;
			}
			else if(s[1]=='K'){
				a[1][13]++;
			}
		}
		if(s[0]=='C'){
			if(s[1]=='A'){
				a[2][1]++;
			}
			else if(s[1]>='2'&&s[1]<='9'){
				a[2][s[1]-'1']++;
			}
			else if(s[1]=='T'){
				a[2][10]++;
			}
			else if(s[1]=='J'){
				a[2][11]++;
			}
			else if(s[1]=='Q'){
				a[2][12]++;
			}
			else if(s[1]=='K'){
				a[2][13]++;
			}
		}
		if(s[0]=='H'){
			if(s[1]=='A'){
				a[3][1]++;
			}
			else if(s[1]>='2'&&s[1]<='9'){
				a[3][s[1]-'1']++;
			}
			else if(s[1]=='T'){
				a[3][10]++;
			}
			else if(s[1]=='J'){
				a[3][11]++;
			}
			else if(s[1]=='Q'){
				a[3][12]++;
			}
			else if(s[1]=='K'){
				a[3][13]++;
			}
		}
		if(s[0]=='S'){
			if(s[1]=='A'){
				a[4][1]++;
			}
			else if(s[1]>='2'&&s[1]<='9'){
				a[4][s[1]-'1']++;
			}
			else if(s[1]=='T'){
				a[4][10]++;
			}
			else if(s[1]=='J'){
				a[4][11]++;
			}
			else if(s[1]=='Q'){
				a[4][12]++;
			}
			else if(s[1]=='K'){
				a[4][13]++;
			}
		}
	}
	for(int i=1;i<5;i++){
		for(int j=1;j<14;j++){
			if(a[i][j]==0){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
