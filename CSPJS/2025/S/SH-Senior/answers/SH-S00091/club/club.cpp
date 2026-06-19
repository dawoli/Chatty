#include <bits/stdc++.h>
using namespace std;
struct stu{
	int a,b,c;
}s[100010];
bool cmp(const stu& X,const stu& Y){
	return max(X.a,max(X.b,X.c))>max(Y.a,max(Y.b,Y.c));
}
int t,n,cnt1,cnt2,cnt3,ans;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
	}
	sort(s+1,s+n+1,cmp);
	cnt1=cnt2=cnt3=ans=0;
	for(int i=1;i<=n;i++){
		if(s[i].a>=max(s[i].b,s[i].c)){
			if((cnt1+1<<1)<=n) cnt1++,ans+=s[i].a;
			else{
				if((cnt2+1<<1)<=n){
					if(s[i].b>s[i].c||(cnt3+1<<1)>n){
						cnt2++,ans+=s[i].b;
					}
					else{
						cnt3++,ans+=s[i].c;
					}
				}
				else{
					cnt3++,ans+=s[i].c;
				}
			}
		}
		else if(s[i].b>=max(s[i].a,s[i].c)){
			if((cnt2+1<<1)<=n) cnt2++,ans+=s[i].b;
			else{
				if((cnt1+1<<1)<=n){
					if(s[i].a>s[i].c||(cnt3+1<<1)>n){
						cnt1++,ans+=s[i].a;
					}
					else{
						cnt3++,ans+=s[i].c;
					}
				}
				else{
					cnt3++,ans+=s[i].c;
				}
			}
		}
		else if(s[i].c>=max(s[i].a,s[i].b)){
			if((cnt3+1<<1)<=n) cnt3++,ans+=s[i].c;
			else{
				if((cnt1+1<<1)<=n){
					if(s[i].a>s[i].b||(cnt2+1<<1)>n){
						cnt1++,ans+=s[i].a;
					}
					else{
						cnt2++,ans+=s[i].b;
					}
				}
				else{
					cnt2++,ans+=s[i].b;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
} 
