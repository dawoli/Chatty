#include <iostream>
using namespace std;
int a[500005];
bool vis[500005];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int t=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[j]){
				break;
			}
			t=t^a[j];
			if(t==k){
				for(int q=i;q<=j;q++){
					vis[q]=1;
				}
				ans++;
				break;
			}
		}
		t=0;
	}
	cout << ans;
	return 0;
}
