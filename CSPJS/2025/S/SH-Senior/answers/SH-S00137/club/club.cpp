#include<bits/stdc++.h>
using namespace std;
int T;
struct s{
	int t1,t2,t3,ma,mf;
};
bool cmp(s a,s b){
	return a.ma>b.ma;
}

int ans11=0;
s st[100010];
int n;
void dfs(int a,int b,int c,int cnt,int p){
	if(a>n/2||b>n/2||c>n/2) return;
	if(p==n){
		ans11=max(ans11,cnt);
	}
	else{
		dfs(a+1,b,c,cnt+st[p].t1,p+1);
		dfs(a,b+1,c,cnt+st[p].t2,p+1);
		dfs(a,b,c+1,cnt+st[p].t3,p+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int test_group=0;test_group<T;test_group++){
		cin>>n;
		if(n==2){
			int a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			int tmpp[]={a+e,a+f,b+d,b+f,c+d,c+e};
			sort(tmpp,tmpp+6,greater<int>());
			cout<<tmpp[0]<<endl;
			continue;
		}
		else if(n<=10){
			for(int i=0;i<n;i++){
				cin>>st[i].t1>>st[i].t2>>st[i].t3;
			}
			ans11=0;
			dfs(0,0,0,0,0);
			cout<<ans11<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			cin>>st[i].t1>>st[i].t2>>st[i].t3;
			st[i].ma=max(st[i].t1,max(st[i].t2,st[i].t3));
			if(st[i].ma==st[i].t1) st[i].mf=1;
			else if(st[i].ma==st[i].t2) st[i].mf=2;
			else st[i].mf=3;
		}
		int ans=0;
		int f3[3]={0,0,0};
		sort(st,st+n,cmp); 
		for(int i=0;i<n;i++){
			ans+=st[i].ma;
			f3[st[i].mf-1]++;
		}
		if(f3[0]<=n/2&&f3[1]<=n/2&&f3[2]<=n/2){
			cout<<ans<<endl;
		}
		else{
			if(f3[1]>n/2){
				ans=0;
				int tmp=0;
				for(int i=0;i<n;i++){
					if(st[i].mf==2){
						tmp++;
						if(tmp<=n/2){
							ans+=st[i].ma;
						}
						st[i].ma=0;
					}
				}
				//剩余重选 
				sort(st,st+n,cmp); 
				for(int i=0;i<n/2;i++){
					ans+=st[i].ma;
					f3[st[i].mf-1]++;
				}
				cout<<ans<<endl;
			}
			else if(f3[0]>n/2){
				ans=0;
				int tmp=0;
				for(int i=0;i<n;i++){
					if(st[i].mf==1){
						tmp++;
						if(tmp<=n/2){
							ans+=st[i].ma;
						}
						st[i].ma=0;
					}
				}
				//剩余重选 
				sort(st,st+n,cmp); 
				for(int i=0;i<n/2;i++){
					ans+=st[i].ma;
					f3[st[i].mf-1]++;
				}
				cout<<ans<<endl;
			}
			else{
				ans=0;
				int tmp=0;
				for(int i=0;i<n;i++){
					if(st[i].mf==3){
						tmp++;
						if(tmp<=n/2){
							ans+=st[i].ma;
						}
						st[i].ma=0;
					}
				}
				//剩余重选 
				sort(st,st+n,cmp); 
				for(int i=0;i<n/2;i++){
					ans+=st[i].ma;
					f3[st[i].mf-1]++;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
} 
