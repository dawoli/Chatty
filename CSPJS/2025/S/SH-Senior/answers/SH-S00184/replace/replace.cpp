#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string s1[N],s2[N];
int st[N],ed[N],size[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		size[i]=s1[i].size();
	}
//	cout<<"a";
	for(int j=1;j<=n;j++){
		for(int i=0;i<size[j];i++){
			if(s1[j][i]!=s2[j][i])
				st[j]=i;
		}
	//	cout<<"1";
		for(int i=size[j]-1;i>=0;i--){
	//		cout<<"3";
			if(s1[j][i]!=s2[j][i])
				ed[j]=i;
				
			
		}
	//	cout<<"2";
	}
//	cout<<"A";
	for(int j=1;j<=q;j++){
		int ans=0;
		string q1,q2;
		cin>>q1>>q2;
		if(q1.size()!=q2.size()){cout<<0<<endl;continue;}
		int s=0,e=0;
		for(int i=0;i<q1.size();i++){
			if(q1[i]!=q2[i])
				s=i;
		}
		for(int i=q1.size()-1;i>=0;i--){
			if(q1[i]!=q2[i])
				e=i;
		}
		for(int i=1;i<=n;i++){
			if(e-s!=ed[i]-st[i])continue;
			if(size[i]>q1.size())continue;
			if(s-st[i]<0||e+size[i]-ed[i]>q1.size())continue;
			bool b=0;
			for(int p1=st[i],p2=s;p1<=ed[i],p2<=e;p1++,p2++){
				if(s1[i][p1]!=q1[p2]){b=1;break;}if(s2[i][p1]!=q2[p2]){b=1;break;}
			}
			if(b){continue;}
			for(int p1=0,p2=s-st[i];p1<size[i];p1++,p2++){
				if(s1[i][p1]!=q1[p2]){b=1;break;}if(s2[i][p1]!=q2[p2]){b=1;break;}
			}
			if(b){continue;}
			ans++;
	//		if(ans!=0)
		//		cout<<i<<endl;
		}
		cout<<ans<<endl;
	}
}
