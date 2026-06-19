#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
int a[1000010];
int ls,lm,lh;
string lasts = "";
void dfs(int now,int xia_biao,int sum,int maxn,int how_many,string s){
	if(xia_biao > n){
		if(how_many >= 3 && sum > maxn * 2){
			if(s != lasts){
				cnt++;
				lasts = s;
				cnt %= 998244353;
			}
		}
		return;
	}
	sum += a[xia_biao];
	how_many++;
	maxn = max(maxn,a[xia_biao]);
	s += char(xia_biao + '0');
	for(int i = 1;i <= n;i++){
		dfs(a[xia_biao + i],xia_biao + i,sum,maxn,how_many,s);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n - 2;i++){
		dfs(a[i],i,0,-INT_MAX,1,"");
	}
	cout << cnt << endl;
	return 0;
}
