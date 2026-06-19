#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
} q[100009];
int t;
int n,m,l,vl,tmp,ans,p[1000009];
bool vis[100009];
vector<int> ch[100009];
int cnt1(int x){
	int qq=x,cnt=0;
	while(qq!=0){
		qq=qq&(qq-1);
		cnt++;
	}
	return cnt;
}
int solve(int sto){
	for(int i=1;i<=tmp;i++){
		vis[i]=0;
	}
	int k=sto;
	while(k!=0){
		int ll=k-(k&(k-1)),kk=0;
		k=k&(k-1);
		while(ll!=0){
			ll/=2;
			kk++;
		}
		for(int i=0;i<ch[kk].size();i++){
			vis[ch[kk][i]]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=tmp;i++){
		if(vis[i]==1)cnt++;
	}
	if(cnt>=ans)return 1;
	else return 0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>l>>vl;//车数，测速仪数，长度，限速 
		for(int i=1;i<=n;i++){
			int d,v,a;
			cin>>d>>v>>a;
			int lim=(vl*vl-v*v)/(2*a)+d;
			if(a==0){
				if(v>vl){
					q[++tmp].l=d;
					q[tmp].r=l; 
				}
			}
			if(a>0){
				if(v>vl){
					q[++tmp].l=d;
					q[tmp].r=l;
				}
				else if(v==vl){
					if(d<l){
						q[++tmp].l=d+1;
						q[tmp].r=l;
					}
				}
				else if(lim+1<=l){
					q[++tmp].l=lim+1;
					q[tmp].r=l;
				}
			}
			if(a<0){
				int flag=1;
				if(2*a*(lim-d)!=(vl*vl-v*v)){
					flag=0;
				}
				if(v>vl){
					q[++tmp].l=d;
					q[tmp].r=min(lim-flag,l);
				}
			}
		}
		for(int i=1;i<=m;i++){
			int x;
			cin>>x;
			p[x]=i;
		}
		for(int i=1;i<=tmp;i++){
			bool flag=0;
			for(int j=q[i].l;j<=q[i].r;j++){
				if(p[j]>0){
					ans++;
					break;
				}
			}
		}
		if(ans!=0)
		cout<<ans<<" "<<m-1<<endl;
		else
		cout<<ans<<" "<<0<<endl;
		continue;
//        int anss=1e9;
//		for(int i=1;i<=(1<<m)-1;i++){
//			if(solve(i))anss=min(anss,cnt1(i));
//		}
//		cout<<m-anss<<endl;
	}
	return 0;
}
