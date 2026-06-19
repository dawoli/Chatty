#include<iostream>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=t1.length()-s1[i].length();j++){
				bool flag=1;
				string t3=t1;
				for(int k=j;k<j+s1[i].length();k++){
					if(t1[k]!=s1[i][k-j]){
						flag=0;
						break;
					}
					t3[k]=s2[i][k];
				}
				if(flag){
					if(t3==t2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
