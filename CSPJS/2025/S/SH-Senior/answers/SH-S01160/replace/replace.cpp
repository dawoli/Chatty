#include <bits/stdc++.h>
using namespace std;
int n,q;
string ss1[200010],ss2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ss1[i]>>ss2[i];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int l=0;l<t1.size();l++){
				for(int r=l;r<t1.size();r++){
					if(t1.substr(l,r-l+1)==ss1[i]){
						string ks1;
						ks1=t1.substr(0,l)+ss2[i]+t1.substr(r+1,n-r+1);
						if(ks1==t2) cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0; 
}
