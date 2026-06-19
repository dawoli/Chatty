#include<bits/stdc++.h>
using namespace std;
long long n,q,s1l[100100],s1r[100100],s2l[100100],s2r[100100],t1l[100100],t2l[100100],t1r[100100],t2r[100100],s1c,s2c,t1c,t2c,lc,rc,ans;
string s1[100100],s2[100100],t1[100100],t2[100100];
bool w[100100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1c=s1[i].length();
		for(int j=0;j<s1c;j++){
			if(s1[i][j]=='b'){
				s1l[i]=j;
				s1r[i]=s1c-j-1; 
				
			}
			if(s2[i][j]=='b'){
				s2l[i]=j;
				s2r[i]=s1c-j-1; 
			}
		}
//		cout<<s1l[i]<<"!"<<s1r[i]<<endl;
//		cout<<s2l[i]<<"!"<<s2r[i]<<endl;
	}
	for(int j=1;j<=q;j++){
		cin>>t1[j]>>t2[j];
		t1c=t1[j].length();
		t2c=t2[j].length();
		if(t1c!=t2c){
			w[j]=1;
		}
		for(int k=0;k<t1c;k++){
			if(t1[j][k]=='b'){
				t1l[j]=k;
				t1r[j]=t1c-k-1; 
			}
			if(t2[j][k]=='b'){
				t2l[j]=k;
				t2r[j]=t1c-k-1; 
			}
		}
//		cout<<t1l[j]<<"!"<<t1r[j]<<endl;
//		cout<<t2l[j]<<"!"<<t2r[j]<<endl;
	}
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=1;j<=q;j++){
			if(w[j]!=1&&s1l[i]>=t1l[j]&&s1r[i]>=t1r[j]){
				lc=s1l[i]-t1l[j]+t2l[j];
				rc=s1r[i]-t1r[j]+t2r[j];
				if(lc==s2l[i]&&rc==s2r[i]){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
