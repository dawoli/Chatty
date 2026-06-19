#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int si,s1[3],s2[3];
}s[200010];
int pw1[5000010],pw2[5000010],n,Q,h1[3][5000010],h2[3][5000010],p3=13,Mod3=998244853,p1=11,p2=7,Mod1=998244353,Mod2=1000000007;
bool cmp(node x,node y){
	return x.si<y.si;
}
bool check(int id,int l,int r){
//	int tmp1[3],tmp2[3];
	int tmp1[4]={0,(h1[1][r]-h1[1][l-1]*pw1[r-l+1]%Mod1+Mod1)%Mod1,(h2[1][r]-h2[1][l-1]*pw2[r-l+1]%Mod2+Mod2)%Mod2};
	int tmp2[4]={0,(h1[2][r]-h1[2][l-1]*pw1[r-l+1]%Mod1+Mod1)%Mod1,(h2[2][r]-h2[2][l-1]*pw2[r-l+1]%Mod2+Mod2)%Mod2};
//	cout<<"!!!"<<id<<" "<<l<<" "<<r<<"\n";
//	cout<<tmp1[1]<<" "<<s[id].s1[1]<<"\n";
//	cout<<tmp1[2]<<" "<<s[id].s2[1]<<"\n";
//	cout<<tmp2[1]<<" "<<s[id].s1[2]<<"\n";
//	cout<<tmp2[2]<<" "<<s[id].s2[2]<<"\n";
	if(tmp1[1]==s[id].s1[1]&&tmp1[2]==s[id].s2[1]&&tmp2[1]==s[id].s1[2]&&tmp2[2]==s[id].s2[2])
		return true;
	return false;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=5000000;i++)
		pw1[i]=pw1[i-1]*p1%Mod1,pw2[i]=pw2[i-1]*p2%Mod2;
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[i].si=s1.size();
		for(int j=0;j<s1.size();j++){
			s[i].s1[1]=(s[i].s1[1]*p1%Mod1+(s1[j]-'a'))%Mod1;
			s[i].s2[1]=(s[i].s2[1]*p2%Mod2+(s1[j]-'a'))%Mod2;
			s[i].s1[2]=(s[i].s1[2]*p1%Mod1+(s2[j]-'a'))%Mod1;
			s[i].s2[2]=(s[i].s2[2]*p2%Mod2+(s2[j]-'a'))%Mod2;
		}
	}
	sort(s+1,s+n+1,cmp);
	while(Q--){
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=t1.size();i++){
			h1[1][i]=(h1[1][i-1]*p1%Mod1+(t1[i-1]-'a'))%Mod1;
			h2[1][i]=(h2[1][i-1]*p2%Mod2+(t1[i-1]-'a'))%Mod2;
			h1[2][i]=(h1[2][i-1]*p1%Mod1+(t2[i-1]-'a'))%Mod1;
			h2[2][i]=(h2[2][i-1]*p2%Mod2+(t2[i-1]-'a'))%Mod2;
		}
		int l=0,r=n,lst=0,L=0,R=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(s[mid].si>t1.size())
				r=mid-1;
			else
				l=mid+1,lst=max(lst,mid);
		}
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				L=i;
				break;
			}
		}
		for(int i=t1.size()-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				R=i;
				break;
			}
		}
//		cout<<lst<<" "<<L<<" "<<R<<"\n";
		int ans=0;
		for(int i=1;i<=lst;i++){
			for(int j=R-s[i].si+1;j<=L;j++){
				if(check(i,j+1,j+s[i].si))
					ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
