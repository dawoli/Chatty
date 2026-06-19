#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,cd[5005],dbx[5001],zz=1,cnt=0;
vector<vector<int> > r;
void store(int n,int dq[]){
	vector<int> tmp;
	for(int i=1;i<=n;i++)tmp.push_back(dq[i]);
	r.push_back(tmp);
	unique(r.begin(),r.end());
}
int check(vector<vector<int> > a){
	for(int i=0;i<a.size();i++){
		int num,maxn=-1;
		for(int j=1;j<=a[i].size();j++){
			if(a[i][j]>maxn)maxn=a[i][j];
			num+=a[i][j];
		}
		if(num>maxn*2)cnt++;
	}
	return cnt;
}
void dfs(int num,int dq[]){
	if(dq[num]>n)return;
	store(n,dq);
	for(int i=num;i>=1;i--){
		dq[i]++;
		dfs(i,dq);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>cd[i];
	for(int i=3;i<=n;i++){
		memset(dbx,0,sizeof(dbx));
		for(int j=1;j<=i;j++)dbx[j]=j;
		dfs(i,dbx);
	}
	cnt=check(r);
	cout<<cnt%mod<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
