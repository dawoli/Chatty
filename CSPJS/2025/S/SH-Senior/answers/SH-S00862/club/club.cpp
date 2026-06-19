#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int a[N][4],c[N],n,ans=-1;
struct node{
	int num[4];
	int now=0;
}st[N];
struct pii{
	int id,w;
	bool operator < (const pii &x) const
	{
		return x.w<w;
	}
};
struct node2{
	priority_queue<pii> q;
	int cnt=0;
};
void dfs(int i,int a1,int a2,int a3,int sum){
	if(a1>n/2||a2>n/2||a3>n/2) return ;
	if(a1+a2+a3==n){
		ans=max(ans,sum);
		return ;
	}
	dfs(i+1,a1+1,a2,a3,sum+a[i][1]);
	dfs(i+1,a1,a2+1,a3,sum+a[i][2]);
	dfs(i+1,a1,a2,a3+1,sum+a[i][3]);
}
signed main(){
	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		node2 b[4];
		cin>>n;
		for(int i=1;i<=n;i++) {
			st[i].now=0;
			for(int j=1;j<=3;j++) st[i].num[j]=1;
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			c[i]=a[i][1];
			if(a[i][2]!=0||a[i][3]!=0) flag=1;
			int maxx=max(a[i][1],max(a[i][2],a[i][3]));
	    	int minn=min(a[i][1],min(a[i][2],a[i][3]));
	    	int max2;
	    	for(int j=1;j<=3;j++){
	    		if(a[i][j]!=maxx&&a[i][j]!=minn){
	    			max2=a[i][j];
	    			st[i].num[2]=j;
				}
				else if(a[i][j]==maxx) st[i].num[1]=j;
				else st[i].num[3]=j;
			}
		}
		if(flag==0){
			int sum=0;
			sort(c+1,c+1+n);
			for(int i=n;i>n/2;i--) sum+=c[i];
			cout<<sum<<endl;
			continue;
		}
		if(n<=30){
			ans=-1;
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			st[i].now=1;
			b[st[i].num[st[i].now]].q.push({i,a[i][st[i].num[st[i].now]]});
			b[st[i].num[st[i].now]].cnt++;
			if(b[st[i].num[st[i].now]].cnt>n/2){
				int id=b[st[i].num[st[i].now]].q.top().id;
				b[st[i].num[st[i].now]].q.pop();
				b[st[i].num[st[i].now]].cnt--;
				st[id].now++;
				b[st[id].num[st[id].now]].q.push({i,a[id][st[id].num[st[id].now]]});
			    b[st[id].num[st[id].now]].cnt++;
			    if(b[st[id].num[st[id].now]].cnt>n/2){
					int idd=b[st[id].num[st[id].now]].q.top().id;
					b[st[id].num[st[id].now]].q.pop();
					b[st[id].num[st[id].now]].cnt--;
					st[idd].now++;
					b[st[idd].num[st[idd].now]].q.push({i,a[idd][st[idd].num[st[idd].now]]});
				    b[st[idd].num[st[idd].now]].cnt++;
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i][st[i].num[st[i].now]];
		}
		cout<<sum<<endl;
	}
	return 0;
}
