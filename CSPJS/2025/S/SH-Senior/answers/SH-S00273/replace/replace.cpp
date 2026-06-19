#include<bits/stdc++.h>
#define int long long
#define ar4 array<int,4> 
using namespace std;
const int N=5000005,inf=1ll<<30,mod=1e9+7,base=131;
int add(int x,int y){
	x+=y;
	if(x>=mod)x-=mod;
	return x;
}
int mul(int x,int y){
	return 1ll*x*y%mod;
}
int sub(int x,int y){
	x-=y;
	if(x<0)x+=mod;
	return x;
}
int a[N];
int n,q,cnt;
map<int,vector<ar4>> mp;
int b[N],qq[N];
int cal(int l,int r){
	if(l>r)return 0;
	if(l==0)return b[r];
	return sub(b[r],mul(b[l-1],qq[r-l+1]));
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	qq[0]=1;
	for(int i=1;i<=N-5;i++){
		qq[i]=mul(qq[i-1],base);
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int siz=s1.size();
		int l=0,r=siz-1;
		while(l<siz&&s1[l]==s2[l])l++;
		while(r>=0&&s1[r]==s2[r])r--;
		if(l>r)continue;
		for(int i=0;i<siz;i++){
			b[i]=s1[i];
			if(i>0)b[i]=add(b[i],mul(b[i-1],base)); 
		}
		int ans=0;
		for(int j=l;j<=r;j++){
			ans=add(mul(ans,base),s1[j]);
			ans=add(mul(ans,base),s2[j]); 
		}
		mp[ans].push_back({l,siz-r-1,cal(0,l-1),cal(r+1,siz-1)});
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int siz=s1.size();
		int l=0,r=siz-1;
		while(l<siz&&s1[l]==s2[l])l++;
		while(r>=0&&s1[r]==s2[r])r--;
		for(int i=0;i<siz;i++){
			b[i]=s1[i];
			if(i>0)b[i]=add(b[i],mul(b[i-1],base)); 
		}
		int ans=0;
		for(int j=l;j<=r;j++){
			ans=add(mul(ans,base),s1[j]);
			ans=add(mul(ans,base),s2[j]); 
		}
		vector<ar4> ve=mp[ans];
		int cnt=0;
		for(auto o:ve){
			int x=o[0],y=o[1],xx=o[2],yy=o[3];
			if(l-x<0||r+y>=siz)continue;
//			if(ve.size()==360)printf("kkk %d %d %d %d\n",cal(l-x,l-1),xx,cal(r+1,r+y),yy);
			if(cal(l-x,l-1)==xx&&cal(r+1,r+y)==yy){
				cnt++;
			}
		} 
		printf("%d\n",cnt);
	}
	return 0;
} 

