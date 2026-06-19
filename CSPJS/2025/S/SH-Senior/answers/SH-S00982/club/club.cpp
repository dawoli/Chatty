#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stu{
	ll p,q,r;
};
ll n,T,k,h;
stu d[200009];
ll chs[200009],c1[200009],c2[200009],c3[200009];
ll cnt1,cnt2,cnt3;
ll ans,ans1,ans2,ans3;
bool cmp(const stu&a,const stu&b){
	return (a.p>b.p)||((a.p==b.p)&&(a.q>b.q))||((a.p==b.p)&&(a.q==b.q)&&(a.r>b.r));
}
void dfs(ll step,ll now){
	if(step==n+1){
		if(max(cnt1,max(cnt2,cnt3))<=n/2){
			ans=max(ans,now);
		}
		return;
	}
	cnt1++;
	dfs(step+1,now+d[step].p);
	cnt1--;
	cnt2++;
	dfs(step+1,now+d[step].q);
	cnt2--;
	cnt3++;
	dfs(step+1,now+d[step].r);
	cnt3--;
}
void solve1(){
	dfs(1,0);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnt1=0;
		cnt2=0;
		cnt3=0;
		ans1=0;
		ans2=0;
		ans3=0;
		ans=0;
		cin>>n;
		fill(chs,chs+1+n,0);
		fill(c1,c1+1+n,0);
		fill(c2,c2+1+n,0);
		fill(c3,c3+1+n,0);
		for(ll i=1;i<=n;i++){
			cin>>d[i].p>>d[i].q>>d[i].r;
		}
		if(n<=13){
			solve1();
			continue;
		}
		sort(d+1,d+1+n,cmp);
		for(ll i=1;i<=n;i++){
			if(d[i].p>=d[i].q&&d[i].p>=d[i].r){
				chs[i]=1;
				cnt1++;
				c1[cnt1]=i;
				ans1+=d[i].p;
			}
			else if(d[i].q>=d[i].p&&d[i].q>=d[i].r){
				chs[i]=2;
				cnt2++;
				c2[cnt2]=i;
				ans2+=d[i].q;
			}
			else{
				chs[i]=3;
				cnt3++;
				c3[cnt3]=i;
				ans3+=d[i].r;
			}
		}
		ans=ans1+ans2+ans3;
		if(max(cnt1,max(cnt2,cnt3))<=n/2){
			cout<<ans<<endl;
			continue;
		}
		k=max(cnt1,max(cnt2,cnt3))-n/2;
		if(cnt1>n/2){
			h=1;
		}
		else if(cnt2>n/2){
			h=2;
		}
		else{
			h=3;
		}
		if(h==1){
			for(ll i=n;i>=n-k+1;i--){
				ans-=d[k].p-d[k].q;
			}
		}
		if(h==2){
			for(ll i=n;i>=n-k+1;i--){
				ans-=d[k].q-d[k].p;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
