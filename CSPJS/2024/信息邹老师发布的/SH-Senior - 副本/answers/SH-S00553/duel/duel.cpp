#include <bits/stdc++.h>
using namespace std;
int r[100005],vis[100005],flag[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) scanf("%d",&r[i]);
	sort(r+1,r+n+1);
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(vis[j]==0&&r[j]>r[i]){
				vis[j]=1,flag[j]=1;
				break;
			}
		}
	}
	int cnt=0;
	for(int i = 1;i <= n;i++){
		if(flag[i]==0) cnt++;
	}
	cout << cnt;
	return 0;
} 
