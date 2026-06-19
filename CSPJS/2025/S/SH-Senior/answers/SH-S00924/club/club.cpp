#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n,m,t,cnt[3],ans;
struct Node{
	int a[3],mx,mn,id;
};
Node s[N];
bool cmp(Node x,Node y){
	return x.mn<y.mn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		scanf("%d",&n);
		for(int i=1,x,y,z;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			s[i].a[0]=x;
			s[i].a[1]=y;
			s[i].a[2]=z;
			s[i].mx=max(x,max(y,z));
			if(s[i].mx==x){
				s[i].id=0;
				s[i].mn=min(x-y,x-z);
			}
			else{
				if(s[i].mx==y){
					s[i].id=1;
					s[i].mn=min(y-x,y-z);
				}
				else{
					s[i].id=2;
					s[i].mn=min(z-x,z-y);
				}
			}
		}
		for(int i=1;i<=n;i++){
			cnt[s[i].id]++;
			ans+=s[i].mx;
		}
		int wc=-1;
		if(cnt[0]>(n/2)) wc=0;
		if(cnt[1]>(n/2)) wc=1;
		if(cnt[2]>(n/2)) wc=2;
		if(wc==-1){
			cout<<ans<<endl;
			continue;
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(s[i].id==wc){
				cnt[wc]--;
				ans-=s[i].mn;
			}
			if(cnt[wc]<=(n/2)) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
