#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;

int n,a[10005];
long long sum=0,maxn=-100;
long long ans=0;

vector<int> v;

void dfs(int k,int w,int step){
	if(step==k){
		//for(int i=0;i<k;i++) cout << v[i] << " ";
		//cout << endl;
		if(sum>maxn*2){
			ans++;
			ans%=MOD;
			return;
		}
	}
	for(int i=w+1;i<=n;i++){
		v.push_back(a[i]);
		sum+=a[i];
		int Max=maxn;
		maxn=max(maxn,(long long)a[i]);
		dfs(k,i,step+1);
		maxn=Max;
		sum-=a[i];
		v.pop_back();//»ØËÝ 
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			v.push_back(a[j]);
			sum+=a[j];
			dfs(i,j,1);
			v.clear();
			sum=0;
			maxn=-100;
		}
	}
	cout << ans%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

