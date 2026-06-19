#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string s;
bool a[10][20];
int mtc[200];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	mtc['A']=1,mtc['T']=10,mtc['J']=11,mtc['Q']=12,mtc['K']=13,mtc['D']=1,mtc['C']=2,mtc['H']=3,mtc['S']=4;
	for(int i='2';i<='9';i++){
		mtc[i]=i-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>s;
		a[mtc[s[0]]][mtc[s[1]]]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			ans-=a[i][j];
		}
	}
	cout<<ans;
	return 0;
}
