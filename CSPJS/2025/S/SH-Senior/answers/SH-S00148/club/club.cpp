#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
long long ans;
int cha[N],like[N],top[N],a,b,c,pre[5];
int res;
priority_queue<int> Q;
void solve(){
	if(pre[1]<=n/2&&pre[2]<=n/2&&pre[3]<=n/2){
		for(int i=1;i<=n;i++){
			ans+=top[i];
		}
		cout<<ans<<endl;
	}
	else{
		int target;
		if(pre[1]>n/2)
			target=1;
		else if(pre[2]>n/2)
			target=2;
		else if(pre[3]>n/2)
			target=3;
		for(int i=1;i<=n;i++){
			ans+=top[i];
			if(like[i]==target){
				Q.push(-cha[i]);
				res++;
				if(res>n/2){
					int f=Q.top();
					Q.pop();
					ans+=f;
					res--;
				}
			}
		}
		cout<<ans<<endl;
	}
	while(!Q.empty()){
		Q.pop();
	}
	for(int i=1;i<=n;i++){
		cha[i]=like[i]=top[i]=0;
	}
	res=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				like[i]=1;
				top[i]=a;
				cha[i]=b+c-min(b,c);
				cha[i]=top[i]-cha[i];
				pre[1]++;
			}
			else if(b>=a&&b>=c){
				like[i]=2;
				top[i]=b;
				cha[i]=a+c-min(a,c);
				cha[i]=top[i]-cha[i];
				pre[2]++;
			}
			else if(c>=b&&c>=a){
				like[i]=3;
				top[i]=c;
				cha[i]=a+b-min(b,a);
				cha[i]=top[i]-cha[i];
				pre[3]++;
			}
		}
		solve();
		pre[1]=0;
		pre[2]=0;
		pre[3]=0;
	}
	return 0;
}
