#include<iostream>
using namespace std;
int n,q;
string s[200010][5],q[200010][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>q[i][1]>>q[i][2];
	}
	
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(s[j][1]==q[i][1]&&s[j][2]==q[i][2]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}	
}
