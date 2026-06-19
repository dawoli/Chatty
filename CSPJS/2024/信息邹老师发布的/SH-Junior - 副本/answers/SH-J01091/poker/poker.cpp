#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
bool a[10][30];
int n,cnt;
char c1,c2;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	m['D']=1,m['C']=2,m['H']=3,m['S']=4;
	m['A']=1,m['2']=2,m['3']=3,m['4']=4,m['5']=5,m['6']=6,m['7']=7,m['8']=8,m['9']=9,m['T']=10,m['J']=11,m['Q']=12,m['K']=13;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c1>>c2;
		a[m[c1]][m[c2]]=1;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			cnt+=(a[i][j]==0);
	cout<<cnt;
	return 0;
} 
