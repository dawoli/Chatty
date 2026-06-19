#include<bits/stdc++.h>
using namespace std;
string sx[202020],sy[202020];
string qx,qy;
int n,q;
string x[202020],y[202020];

string sub(string s,int l,int r){
	string ret="";
	for(;l<=r;l++)ret+=s[l];
	return ret;
}
bool chkB(){
	for(int i = 1;i<=n;i++){
		int cnt1=0,cnt2=0;
		for(int j = 0;j<sx[i].size();j++){
			if(sx[i][j]=='b')cnt1++;
			else if(sx[i][j]!='a')return 0;
			if(sy[i][j]=='b')cnt2++;
			else if(sy[i][j]!='a')return 0;
		}
		if(cnt1!=1 or cnt2!=1)return 0;
	}
	for(int i = 1;i<=q;i++){
		int cnt1=0,cnt2=0;
		for(int j = 0;j<x[i].size();j++){
			if(x[i][j]=='b')cnt1++;
			else if(x[i][j]!='a')return 0;
			if(y[i][j]=='b')cnt2++;
			else if(y[i][j]!='a')return 0;
		}
		if(cnt1!=1 or cnt2!=1)return 0;
	}
	return 1;
}
int s1q[202020],s1h[202020],s2q[202020],s2h[202020],xq[202020],xh[202020],yq[202020],yh[202020];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>sx[i]>>sy[i];
	for(int i = 1;i<=q;i++)cin>>x[i]>>y[i];
	
	if(n<=2000 and q<=2000){
		while(q--){
			int ans=0;
			qx=x[i],qy=y[i];
			
			for(int l = 0;l<qx.size();l++){
				for(int i = 1;i<=n;i++){
					int sz=sx[i].size();
					string s=sx[i],t=sy[i];
					if(sub(qx,l,l+sz-1)==s and sub(qy,l,l+sz-1)==t and sub(qx,1,l-1)==sub(qy,1,l-1) and sub(qx,l+
					sz,qx.size()-1)==sub(qy,l+sz,qy.size()-1))
						ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	
	else if(chkB()){
		for(int i = 1;i<=q;i++){
			int j=0;
			while(x[i][j]!='b')xq[i]++,j++;
			j++;
			while(x[i][j]<x[i].size())xh[i]++,j++;
			j=0;
			while(y[i][j]!='b')yq[i]++,j++;
			j++;
			while(y[i][j]<y[i].size())yh[i]++,j++;
		}
		for(int i = 1;i<=n;i++){
			int j=0;
			while(sx[i][j]!='b')s1q[i]++,j++;
			j++;
			while(sx[i][j]<sx[i].size())s1h[i]++,j++;
			j=0;
			while(sy[i][j]!='b')s2q[i]++,j++;
			j++;
			while(sy[i][j]<sy[i].size())s2h[i]++,j++;
		}
		for(int i = 1;i<=q;i++){
			int ans=0;
			for(int j = 1;j<=n;j++){
				if(s1q[j]>xq[i] or s1h[j]>xh[i] or s2q[j]>yq[i] or s2h[j]>yh[i])continue;
				int st1=xq[i]-s1q[j],st2=yq[i]-s2q[j];
				if(st1!=st2)continue;
				if(xq[i]-yq[i]!=s1q[j]-s2q[j] or xh[i]-yh[i]!=s1h[j]-s2h[j])continue;
				ans++;
			}
			cout<<ans<<endl;
		}
	}
}
