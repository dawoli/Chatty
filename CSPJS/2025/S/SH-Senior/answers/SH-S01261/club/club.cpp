#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,n,a[100005][3],chs[100005],ans,cnt[3],C;
int stk[100005],pt1;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int mxm=max(max(a[i][0],a[i][1]),a[i][2]);
			if(a[i][0]==mxm){chs[i]=0;cnt[0]++;}
			else if(a[i][1]==mxm){chs[i]=1;cnt[1]++;}
			else{chs[i]=2;cnt[2]++;}
			ans+=mxm;
		}
		C=-1;
		if(cnt[0]*2>n)C=0;
		if(cnt[1]*2>n)C=1;
		if(cnt[2]*2>n)C=2;
		if(C!=-1){
			for(int i=1;i<=n;i++)if(chs[i]==C)stk[++pt1]=a[i][C]-max(a[i][(C+1)%3],a[i][(C+2)%3]);
			sort(stk+1,stk+pt1+1);
			for(int i=1;i<=cnt[C]-n/2;i++)ans-=stk[i];
		}
		cout<<ans<<'\n';ans=pt1=0;
		cnt[0]=cnt[1]=cnt[2]=0;
	}
	return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
