#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,v,st[1000009],ed[1000009],s[1000009],dif[1000009],cam[1000009],c2[100009];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>l>>v;
		fill(dif,dif+l+1,0);
		fill(s,s+l+1,0);
		fill(c2,c2+n+1,0);
		for(int i=1;i<=n;i++){
			int d,v0,a;
			cin>>d>>v0>>a;
			if(a>0)st[i]=d+(v0<=v?(v*v-v0*v0)/(2*a)+1:0),ed[i]=l;
			if(a==0)if(v0>v)st[i]=d,ed[i]=l;else ed[i]=-1;
			if(a<0){
				if(v0<=v)ed[i]=-1;
				else st[i]=d,ed[i]=d+(v0*v0-v*v-1)/(-2*a);
			}
		}
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			if(ed[i]>l)ed[i]=l;
//			cout<<i<<":st="<<st[i]<<" ed:"<<ed[i]<<endl;
			if(!(0<=st[i]&&st[i]<=l&&0<=ed[i]&&ed[i]<=l))continue;
			dif[st[i]]++,dif[ed[i]+1]--;
		}
		s[0]=dif[0];
//		cout<<s[0]<<" ";
		for(int i=1;i<=l;i++)s[i]=s[i-1]+dif[i]/*,cout<<s[i]<<" "*/;
		set<int>mp;
		
//		cout<<endl;
		for(int i=1;i<=m;i++)cin>>cam[i];
		for(int i=1;i<=n;i++){
			if(!(0<=st[i]&&st[i]<=l&&0<=ed[i]&&ed[i]<=l))continue;
			int up=upper_bound(cam+1,cam+m+1,ed[i])-cam;
			int dn=lower_bound(cam+1,cam+m+1,st[i])-cam;
			if(up==m)up++;
			if(up-dn<1)continue;
			ans1++;
			int mx;
			for(int j=dn;j<up;j++)if(j==dn||s[cam[j]]>s[cam[mx]])mx=j;
			mp.insert(mx);
		}
//		for(int i=1;i<=m;i++){
//			for(auto j:mp[i])if(!)
//		}
		cout<<ans1<<" "<<m-mp.size()<<endl;
	}
	return 0;
}
