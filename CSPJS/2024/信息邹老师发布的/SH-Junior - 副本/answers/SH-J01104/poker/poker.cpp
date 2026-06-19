#include<bits/stdc++.h>
using namespace std;
long long maxn=-2147483648,minn=2147483647,ans=0;
char a,b;
int aa[1005][4];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		b=s[0];
		a=s[1];
		int c;
		if(b=='D'){
			c=1;
		}
		if(b=='C'){
			c=2;
		}
		if(b=='H'){
			c=3;
		}
		if(b=='S'){
			c=4;
		}
		if(a=='T'){
			aa[10][c]++;
		}
		else if(a=='J'){
			aa[11][c]++;
		}
		else if(a=='Q'){
			aa[12][c]++;
		}
		else if(a=='K'){
			aa[13][c]++;
		}
		else if(a=='A'){
			aa[1][c]++;
		}
		else{
			aa[a-'0'][c]++;
		}
	}
	for(int i=1;i<=13;i++){
		for(int j=1;j<=4;j++){
			if(!aa[i][j]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
