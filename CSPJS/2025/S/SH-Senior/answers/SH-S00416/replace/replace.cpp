#include<iostream>
#include<vector>
using namespace std;
string sa[200005],sb[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i];
	}
	for(int i=1;i<=q;i++){
		string sc,sd;
		cin>>sc>>sd;
		int cnt=0;
		for(int j=0;j<=sc.size();j++){
			if(sc[j]!=sd[j])cnt++;
		}
		int ans=0;
		for(int j=0;j<sc.size();j++){
			for(int m=1;m<=n;m++){
				bool flag=0;
				for(int k=j;k<j+sa[m].size();k++){
					if(sc[k]!=sa[m][k-j]||sd[k]!=sb[m][k-j]||cnt>sa[m].size())flag=1;
				}
				if(flag)continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
