#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,cnt1,cnt2,cnt3,ch;
long long f[maxn],ans;
bool flag[maxn][5];
priority_queue<long long>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		while(!q.empty())q.pop();
		memset(f,0,sizeof(f));
		memset(flag,0,sizeof(flag));
		ch=cnt1=cnt2=cnt3=0;ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			long long a,b,c,maxa;cin>>a>>b>>c;
			maxa=max(max(a,b),c);
			ans+=maxa;
			if(a==maxa){
				f[i]=maxa-max(b,c);
				cnt1++;
				flag[i][1]=true;
			}
			else if(b==maxa){
				f[i]=maxa-max(a,c);
				cnt2++;
				flag[i][2]=true;
			}
			else{
				f[i]=maxa-max(a,b);
				cnt3++;
				flag[i][3]=true;
			}
		}
		int maxc=max(max(cnt1,cnt2),cnt3);
		if(maxc<=n/2)cout<<ans<<endl;
		else{
			if(maxc==cnt1)ch=1;
			else if(maxc==cnt2)ch=2;
			else ch=3;
			for(int i=1;i<=n;i++)
				if(flag[i][ch])q.push(-f[i]);
			for(int i=1;i<=maxc-n/2;i++){
				ans+=q.top();
				q.pop();
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
