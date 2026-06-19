#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
int di[100005],vi[100005],ai[100005],pi[100005] = {0},qi[100005] = {0},sum = 0;
int find(int di,int vi,int ai,int l,int v){
	int yes = 1,no = 0;
	for(int i = di;i <= l;i+=vi){
		if(vi > v){
			return yes;
		}
		vi += ai;
		if(vi < 0){
			return no;
		}
	}
	return no;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n >> m >> l >> v;
		for(int j = 1;j <= n;j++){
			cin >> di[j] >> vi[j] >> ai[j]; 
		}
		for(int k = 1;k <= m;k++){
			int tmp;
			cin >> tmp;
			pi[tmp] = 1;
		}
		for(int g = 1;g <= n;g++){
			 sum += find(di[g],vi[g],ai[g],l,v);
		}
	}
	cout << sum;
	return 0;
}
