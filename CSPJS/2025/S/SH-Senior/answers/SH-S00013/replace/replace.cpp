#include<bits/stdc++.h> //³¬Ê± 
using namespace std;
const int maxn=200005;
int n,q;
string s[maxn][3];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int ans=0;
		string tmp;
		for(int j=1;j<=n;j++){
			if(t1.find(s[j][1])!=-1){
				tmp=t1;
				int k;
				for(k=t1.find(s[j][1]);k<t1.find(s[j][1])+s[j][2].length();k++){
					tmp[k]=s[j][2][k-t1.find(s[j][1])];
				}
				if(tmp==t2) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
