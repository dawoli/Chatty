#include <bits/stdc++.h>
using namespace std;
int n,f;
int ans;
long long s,k;
long long a[500010];
int vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) ans++,vis[i]=1;
	}for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		s=a[i];
		int j=i+1;
		for(j;j<=n;j++){
			//if(vis[j]) break;
			vis[j]++;
			s^=a[j];
			cout << s << " ";
			if(s==k){
				cout << endl;
				ans++;
				f=1;
				break;
			}
		}if(!f){
			for(int l=i+1;l<j;l++){
				vis[l]--;
			}
		}
	}
	cout << ans;		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
