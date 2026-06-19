#include<bits/stdc++.h>
using namespace std;
int x[100010],ab[100010],bc[100010],ac[100010];
int t,n,ans,ans1,ans2,ans3;
struct staff{
	int a,b,c;
} s[100010];
bool cmp1(staff x,staff y){
	return x.a>y.a;
}
bool cmp2(staff x,staff y){
	return x.b>y.b;
}
bool cmp3(staff x,staff y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=t;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			cin>>s[j].a>>s[j].b>>s[j].c;
			ab[j]=abs(s[j].a-s[j].b);
			bc[j]=abs(s[j].c-s[j].b);
			ac[j]=abs(s[j].a-s[j].c);
			x[j]=max(max(s[j].a,s[j].b),s[j].c);
		}
		if(n==2){
			ans=max(max(max(max(max(s[1].a+s[2].b,s[1].a+s[2].c),s[1].b+s[2].a),
			s[1].b+s[2].c),s[1].c+s[2].a),s[1].c+s[2].b);
		}
		else if(n>=4&&n<=30){
			for(int k=1;k<=)
		} 
		else if(n>30){
			for(int j=1;j<=n;j++)
				ans+=x[j];
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
