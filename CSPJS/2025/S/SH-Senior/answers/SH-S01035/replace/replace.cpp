#include<bits/stdc++.h>
using namespace std;
#define int long long
string a[200005][3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(q--){
		int cnt=0;
		string t1,t2;
		cin>>t1>>t2;
		string tt1=t1;
		for(int k=1;k<=n;k++){
			t1=tt1;
			for(int i=0;i<t1.size();i++){
				if(t1[i]==a[k][1][0]&&i+a[k][1].size()-1<t1.size()){
					int f=0;
					for(int j=i;j<i+a[k][1].size();j++){
						if(a[k][1][j-i]!=t1[j]){
							f=1;
						}
					}
					if(f==0){
						for(int j=i;j<i+a[k][1].size();j++){
							t1[j]=a[k][2][j-i];
						}
						if(t1==t2){
							cnt++;
							break;
						}
						t1=tt1;
					}
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
