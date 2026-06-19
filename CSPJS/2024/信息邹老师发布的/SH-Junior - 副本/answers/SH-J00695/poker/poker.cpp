#include<bits/stdc++.h>
using namespace std;
int n;
int a[6][20];
string s;
int x,y;
int ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	ans = 52;
	for(int i = 1;i <= n;i++){
		cin >>s;
		if(s[1] == 'A'){
			y = 1;
		}
		else if(s[1] == 'T'){
			y = 10;
		}
		else if(s[1] == 'J'){
			y = 11;
		}
		else if(s[1] == 'Q'){
			y = 12;
		}
		else if(s[1] == 'K'){
			y = 13;
		}
		else{
			y = s[1] - '0';
		}
		if(s[0] == 'D'){
			x = 1;
		}
		else if(s[0] == 'C'){
			x = 2;
		}
		else if(s[0] == 'H'){
			x = 3;
		}
		else if(s[0] == 'S'){
			x = 4;
		}
		if(!a[x][y]){
			a[x][y] = 1;
			ans--;
		}
	}
	printf("%d",ans);
	return 0;
} 
