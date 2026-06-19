#include<bits/stdc++.h>
using namespace std;
int t,n,Q,k,d[200001][101],s[300001],z,c[2][200001],ans;
queue<int>q[2];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>Q;
		int cnt=0;
		for(int i=1;i<=n;i++){
			int l;cin>>l;s[++cnt]=-i;
			for(int j=1;j<=l;j++)
				cin>>s[++cnt];
		}
		memset(d,0,sizeof(d));
		memset(c,-1,sizeof(c));
		while(!q[1].empty())q[1].pop();
		while(!q[0].empty())q[0].pop();
		q[1].push(1);c[1][1]=0;z=1;ans=0;
		while(!q[z].empty()&&ans<100){
			ans++;
			int f=0,g=0,h=0,p=0;
			for(int i=1;i<=cnt;i++){
				if(s[i]<0){
					f=0,g=-s[i],h=0,p=0;
					continue;
				}
				if(h>0||(f>0&&g!=p)){
					if(c[!z][s[i]]==-1){
						q[!z].push(s[i]);
						c[!z][s[i]]=g;
						d[s[i]][ans]=1;
					}else if(c[!z][s[i]]!=g){
						c[!z][s[i]]=0;
					}
				}
				if(c[z][s[i]]!=-1){
					if(f>0&&p!=c[z][s[i]])h=f;
					f=k,p=c[z][s[i]];
				}
				f--,h--;
			}
			while(!q[z].empty()){
				c[z][q[z].front()]=-1;
				q[z].pop();
			}
			z=!z;
		}
		for(int i=1;i<=Q;i++){
			int r,C;cin>>r>>C;
			cout<<d[C][r]<<endl;
		}
	}
	return 0;
}
