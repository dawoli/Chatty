#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n;
int r[maxn][2],maxri=0,minri=INT_MAX,cnt;
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		r[a][0]++;
		r[a][1]++;
		maxri=max(maxri,a);
		minri=min(minri,a);
	}
	int prev=minri;
	for(int i=minri+1;i<=maxri;i++){
		if(r[i][0]!=0){
			if(r[i][0]>=r[prev][1]){
				cnt-=r[prev][1];
				r[i][0]-=r[prev][1];
				r[prev][1]=0;
				prev=i;
			}
			else{
				cnt-=r[i][0];
				r[i][0]=0;
				r[prev][1]-=r[i][0];
			}
		}
	}
	cout<<cnt;
	return 0;
}
