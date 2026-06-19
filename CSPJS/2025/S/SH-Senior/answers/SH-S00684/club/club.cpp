#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
struct node{
	int a,b,c;
}x[N];
int tot[5],ans;
vector<int>G[5];
int cnt,f[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
		}
		int maxn;
		for(int i=1;i<=n;i++){
			maxn=max(x[i].a,max(x[i].b,x[i].c));
			if(x[i].a==maxn){
				tot[1]++;
				G[1].push_back(i);
				ans+=x[i].a;
			}
			else if(x[i].b==maxn){
				tot[2]++;
				G[2].push_back(i);
				ans+=x[i].b;
			}
			else{
				tot[3]++;
				G[3].push_back(i);
				ans+=x[i].c;
			}
		}
		int flag=0;
		if(tot[1]>n/2)	flag=1;
		if(tot[2]>n/2)	flag=2;
		if(tot[3]>n/2)	flag=3;
		//cout<<flag<<" "<<tot[flag]<<endl;
		if(flag==0){
			cout<<ans<<endl;
		}
		else{
			int v;
			for(int i:G[flag]){
				if(flag==1)	v=x[i].a-max(x[i].c,x[i].b);
				else if(flag==2)	v=x[i].b-max(x[i].a,x[i].c);
				else	v=x[i].c-max(x[i].a,x[i].b);
				f[++cnt]=v;
				//cout<<i<<" "<<v<<endl;
			}
			sort(f+1,f+cnt+1);
			for(int i=1;i<=cnt-n/2;i++){
				ans-=f[i];
			}
			cout<<ans<<endl;
		}
		cnt=ans=0;
		for(int i=1;i<=3;i++){
			G[i].clear();
			tot[i]=0;
		}
	}
	return 0;
} 
