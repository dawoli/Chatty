#include<bits/stdc++.h>
using namespace std;

int t,n,s[100030][3],maxx,num[3],ans;

void dfs(int x,int b){
	if(x==n){
		maxx=max(maxx,ans);
	}else{
		for(int i=1; i<=3; i++){
			if(num[i]+1<=n/2){
				num[i]++;
				ans+=s[x+1][i];
				dfs(x+1,i);	
			}
		}
	}
	num[b]--;
	ans-=s[x][b];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> s[i][1] >> s[i][2] >> s[i][3];
		}
		maxx=0;
		ans=0;
		memset(num,0,sizeof(num));
		dfs(0,0);
		cout << maxx;
	}
	return 0;
} 
