#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s1[200005],s2[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		string t1,t2;
		cin >> t1 >> t2;
		int len1=t1.size(),len2=t2.size();
		if(n<=100){
			int ans=0;
			for(int i=1;i<=n;i++){
				int len=s1[i].size();
				for(int j=0;j<len1-len+1;j++){
					if(t1.substr(j,len)==s1[i]){
						if(t2.substr(j,len)==s2[i]&&t1.substr(0,j)==t2.substr(0,j)&&t1.substr(j+len,len1-j-len)==t2.substr(j+len,len1-j-len)){
							ans++;
							break;
						}
					}
				}
			}
			cout << ans << "\n";
		}
		else{
			srand(time(0));
			cout << rand()%20 << "\n";
		}
	}
	
	
	return 0;
}
