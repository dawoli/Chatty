#include<bits/stdc++.h>
using namespace std;
/*
#define MOD1 998244353
#define MOD2 1000000007
int n,q,s,s2;
int hash1(string f){
	int ans=1;
	for(int i=0;i<f.length();i++){
		ans=(ans*26+f[i]-'a')%MOD1
	}
	return ans;
}
int hash2(string f){
	int ans=1;
	for(int i=0;i<f.length();i++){
		ans=(ans*26+f[i]-'a')%MOD2
	}
	return ans;
}
int fin1[200005],fin2[200005],fout1[200005],fout2[200005],len[200005];
*/
int n,q;
string s1[200005],s2[200005],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		/*
		cin>>s;
		fin1[i]=hash1(s);
		fin2[i]=hash2(s);
		cin>>s;
		fout1[i]=hash1(s);
		fout2[i]=hash2(s);
		len[i]=s.length();
		*/
		cin>>s1[i]>>s2[i];
	}
	for(int _=0;_<q;_++){
		cin>>x>>y;
		if(x.length()!=y.length()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=0;i<x.length();i++){
			for(int j=i;j<x.length();j++){
				string p1="",p2="";
				for(int k=i;k<=j;k++){
					p1+=x[k];
				}
				for(int k=i;k<=j;k++){
					p2+=y[k];
				}
				cout<<p1<<" "<<p2<<"\n";
				for(int k=1;k<=n;k++){
					if(p1==s1[k]&&p2==s2[k]){
						string u;
						for(int l=0;l<=y.length();l++)u+=y[l];
						for(int l=i;l<=j;l++){
							u[l]=x[l];
						}
						bool flag=1;
						for(int l=0;l<=x.length();l++){
							flag&=(x[l]==u[l]);
						}
						ans+=flag;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
