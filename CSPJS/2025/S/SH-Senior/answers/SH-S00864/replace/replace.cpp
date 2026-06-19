#include <bits/stdc++.h>
using namespace std;
int n,q,cnt;
string x[100003];
string ya[100003],yb[100003];
string z[100003];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;	cin>>a>>b;
		int l=0;
		for(;l<min(a.size(),b.size());l++)
			if(a[l]!=b[l]) break;
		int r=a.size()-1,r1=b.size()-1;
		for(;r>=0&&r1>=0;r--,r1--)
			if(a[r]!=b[r1])break;
		x[i]=a.substr(0,l);
		ya[i]=a.substr(l,r-l+1);
		yb[i]=b.substr(l,r1-l+1);
		z[i]=a.substr(r+1,a.size()-r-1);
		
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		string x1,x2;cin>>x1>>x2;
		int l=0;
		for(;l<min(x1.size(),x2.size());l++)
			if(x1[l]!=x2[l]) break;
		int r=x1.size()-1,r1=x2.size()-1;
		for(;r>=0&&r1>=0;r--,r1--)
			if(x1[r]!=x2[r1])break;
		string g=x1.substr(0,l);
		string s1=x1.substr(l,r-l+1);
		string s2=x2.substr(l,r1-l+1);
		string t=x1.substr(r+1,x1.size()-r-1);
		for(int j=1;j<=n;j++){
			if((g.find(x[j])!=-1||x[j]=="")&&ya[j]==s1&&yb[j]==s2&&(t.find(z[j])!=-1||z[j]==""))
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
