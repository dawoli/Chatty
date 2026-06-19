#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c,d1,d2,d3;
}s[100009];
bool cmp1(const node& x,const node& y){
	return x.d1>y.d1;
}
bool cmp2(const node& x,const node& y){
	return x.a>y.a;
}
bool cmp3(const node& x,const node& y){
	return x.d2>y.d2;
}
bool cmp4(const node& x,const node& y){
	return x.d3>y.d3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=100000;i++){
			s[i].a=s[i].b=s[i].c=s[i].d1=s[i].d2=s[i].d3=0;
		}
		bool f1=1,f2=1;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].d1=s[i].a-s[i].b;
			s[i].d2=s[i].b-s[i].c;
			s[i].d3=s[i].c-s[i].a;
			if(s[i].b||s[i].c)f1=0;
			if(s[i].c)f2=0;
		}
		if(f1){
			sort(s+1,s+1+n,cmp2);
			for(int i=1;i<=n/2;i++)ans+=s[i].a;
		}else if(f2){
			sort(s+1,s+1+n,cmp1);
			for(int i=1;i<=n/2;i++)ans+=s[i].a;
			for(int i=n/2+1;i<=n;i++)ans+=s[i].b;
		}else{
			sort(s+1,s+1+n,cmp1);
			long long cnt1=0,cnt2=0,cnt3=0,cur1=0,cur2=0,cur3=0;
			for(int i=1;i<=n/2;i++)cnt1+=s[i].a;
			for(int i=n/2+1;i<=n;i++)cnt1+=max(s[i].b,s[i].c);
			for(int i=n;i>n/2;i--)cur1+=s[i].b;
			for(int i=n/2;i>=1;i--)cur1+=max(s[i].a,s[i].c);
			cnt1=max(cnt1,cur1); 
			sort(s+1,s+1+n,cmp3);
			for(int i=1;i<=n/2;i++)cnt2+=s[i].b;
			for(int i=n/2+1;i<=n;i++)cnt2+=max(s[i].c,s[i].a);
			for(int i=n;i>n/2;i--)cur2+=s[i].c;
			for(int i=n/2;i>=1;i--)cur2+=max(s[i].a,s[i].b);
			cnt2=max(cnt2,cur2);
			sort(s+1,s+1+n,cmp4);
			for(int i=1;i<=n/2;i++)cnt3+=s[i].c;
			for(int i=n/2+1;i<=n;i++)cnt3+=max(s[i].a,s[i].b);
			for(int i=n;i>n/2;i--)cur3+=s[i].a;
			for(int i=n/2;i>=1;i--)cur3+=max(s[i].b,s[i].c);
			cnt3=max(cnt3,cur3);
			ans=max(cnt1,max(cnt2,cnt3));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
