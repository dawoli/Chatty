#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,q;
struct node{
	string x,y;
	int z;
}a[200005];
 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i=1;i <= n;i++){
		string x,y;
		cin >> x >> y;
		a[i].x = x,a[i].y = y,a[i].z = x.size();
	}
	while(q--){
		string s1,s2;
		cin >> s1 >> s2;
		if(s1.size()!=s2.size()){
			cout << "0\n";
			continue;
		}
		int t = s1.size(),ans = 0;
		for(int i=1;i <= n;i++){
			for(int j=0;j < t-a[i].z+1;j++){
				string t1 = s1.substr(j,a[i].z);
				string t2 = s2.substr(j,a[i].z);
				string t3 = s1.substr(0,j);
				string t4 = s2.substr(0,j);
				string t5 = s1.substr(j+a[i].z,t-(j+a[i].z-1));
				string t6 = s2.substr(j+a[i].z,t-(j+a[i].z-1));
//				for(int k=j;k <= j+a[i].z-1;k++){
//					char x[1] = {t1[k]};
//					t1 += x;
//				}
				if(t1==a[i].x&&t2==a[i].y&&t3==t4&&t5==t6){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//wo1bu2hu3iz4uo5zh6ed7ao8ti9



























//phigrOSÍòËê£¡OIÍòËê£¡
