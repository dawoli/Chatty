#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
bool vis[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	mp['D']=1;
	mp['C']=2;
	mp['H']=3;
	mp['S']=4;
	mp['A']=1;
	mp['2']=2;
	mp['3']=3;
	mp['4']=4;
	mp['5']=5;
	mp['6']=6;
	mp['7']=7;
	mp['8']=8;
	mp['9']=9;
	mp['T']=10;
	mp['J']=11;
	mp['Q']=12;
	mp['K']=13;
	while(n--){
		char l,r;
		cin>>l>>r;
		vis[mp[l]][mp[r]]=1;
	}
	int ans=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!vis[i][j]){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
