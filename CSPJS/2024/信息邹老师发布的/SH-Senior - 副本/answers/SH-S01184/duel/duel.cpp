#include<bits/stdc++.h>
using namespace std;
long long n;
int r[10000001];
bool v[10000001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r,r+n+1);
	memset(v,1,sizeof(v));
	for(int i=1;i<=n;i++){
		if(v[i]==0)continue;
		int minn=100001,mi=-1;
		for(int j=1;j<=i;j++){
			if(v[j]==0)continue;
			if(i==j)continue;
			if(r[i]-r[j]<minn&&r[i]-r[j]>0){
				minn=r[i]-r[j];
				mi=j;
			}
		}
		if(mi==-1)continue;
		v[mi]=0;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(v[i]==1)sum++;
	}
	cout<<sum;
	return 0;
}

