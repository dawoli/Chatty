#include<bits/stdc++.h>
using namespace std;

bool a[4][13];
int n,rst;
string s;

int huase(char n)
{
	if(n == 'D') return 0;
	if(n == 'C') return 1;
	if(n == 'H') return 2;
	if(n == 'S') return 3;
}

int shuzi(char n)
{
	if(isdigit(n)) return n-'0';
	if(n=='A') return 1;
	if(n=='T') return 10;
	if(n=='J') return 11;
	if(n=='Q') return 12;
	if(n=='K') return 13;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>s;
		a[huase(s[0])][shuzi(s[1])-1] = 1;
	}
	for(int i = 0;i<4;i++){
		for(int j = 0;j<13;j++){
			if (a[i][j]==0) rst++;
		}
	}
	cout<<rst<<endl;
	return 0;
	
}


