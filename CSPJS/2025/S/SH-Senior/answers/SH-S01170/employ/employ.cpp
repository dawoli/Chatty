#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[1500];
int rec[1500];//CS:1
int ans=0;
void dfs(int x, int lc){
	//cout << '*' << x;
	if (x==n+1){
		//cout << lc;
		//cout << "!" << lc;
		if (lc>=m){
			ans++;
		}
	}
	for (int i=1; i<=n; i++){
		if (rec[i]==0){
			rec[i]=1;
			if (s[i-1]=='0' || (x-1-lc)>=c[i]){
				rec[i]=1;
				dfs(x+1,lc);
				rec[i]=0;
			}else{
				rec[i]=1;
				dfs(x+1,lc+1);
				rec[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i=1; i<=n; i++){
		cin >> c[i];
	}
	dfs(1,0);//Now People lc People
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}
/*
15:30 Start this. That is so hard First DFS(20) Why this is giving So little AAAAA
15:56 DFS Finished
Only 40+16+20.. I will AFO... Or Not?
*/
