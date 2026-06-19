#include<bits/stdc++.h>
using namespace std;
const int H=26707;
int n,q;
string s[200010],t[200010];
int ss[1010][210],tt[1010][210];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i]>>t[i];
		for(int j=1;j<=s[i].length();++j)
			ss[i][j]=ss[i][j-1]*H+s[i][j-1],tt[i][j]=tt[i][j-1]*H+t[i][j-1],cout<<j<<" "<<ss[i][j]<<" "<<tt[i][j]<<endl;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int lb,rb;
		for(int i=0;i<a.length();++i)
			if(a[i]!=b[i]){
				lb=i;
				break;
			}
		for(int i=a.length()-1;i>=0;--i)
			if(a[i]!=b[i]){
				rb=i;
				break;
			}
		int HA=0,HB=0;
		for(int i=lb;i<=rb;++i)
			HA=HA*H+a[i],HB=HB*H+b[i];
		int cnt=0;
		for(int i=1;i<=n;++i){
			int Ha=HA,Hb=HB;
			for(int j=0,k=rb-lb;k<s[i].length();++j,++k){
				int sss=ss[i][k+1]-ss[i][j],ttt=tt[i][k+1]-tt[i][j];
				Ha*=H; Hb*=H;
				if(Ha==sss)	++cnt;
			}
		}
		cout<<cnt<<endl;
	}
}
