#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
struct pa{
	int l,r,v;
}p[N];
bool cmp(pa a,pa b){
	return a.v>b.v;
}
int T,n,a[N],c[N],ans,pos[N];
vector<int> s[N];
int cal(){
	int sum=0;
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(c[i]==c[j]){
				if(a[i]==a[j]) sum+=a[i];
				break;
			}
		}
	}
	return sum;
}
void solve(int x){
	if(x==n+1){
		//for(int i=1;i<=n;i++){
		//	cout<<c[i]<<" ";
	//	}
		//cout<<cal()<<endl;
		ans=max(cal(),ans);
		return;
	}
	c[x]=1;
	solve(x+1);
	c[x]=0;
	solve(x+1);
} 
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		ans=0;
		cin>>n;
		if(n<=30){
			c[1]=0;
			for(int j=1;j<=n;j++)
				cin>>a[j];
			solve(2);
			cout<<ans<<endl;	
		}
		else{
			memset(pos,0,sizeof(pos));
			int cnt=0;
			for(int j=1;j<=n;j++){
				cin>>a[j];
				if(pos[a[j]]==0) pos[a[j]]=j;
				else{
					p[cnt++]=(pa){pos[a[j]],j,a[j]};
					pos[a[j]]=j;
				}
			}
			memset(s,0,sizeof(s));
			//cout<<cnt<<endl;
			for(int j=0;j<cnt;j++){
				for(int k=j+1;k<cnt;k++){
					if(p[j].l>p[k].l&&p[j].l<p[k].r&&p[k].r-p[j].l>1){
						s[j].push_back(k);
						s[k].push_back(j);
					}
					else if(p[j].r>p[k].l&&p[j].r<p[k].r&&p[k].r-p[j].r>1){
						s[j].push_back(k);
						s[k].push_back(j); 
					}
				}
			}
			sort(p,p+cnt,cmp);
			bool no[N];
			memset(no,0,sizeof(no));
			for(int j=0;j<cnt;j++){
				if(!no[j]) {
					//cout<<p[j].l<<" "<<p[j].r<<" "<<p[j].v<<endl;
					ans+=p[j].v;
				}
				for(int k=0;k<s[j].size();k++){
					no[s[j][k]]=1;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
