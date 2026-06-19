#include <bits/stdc++.h> 
using namespace std;

int n,k,a[500005],cnt = 0;
int ans = 0,to = -1e9,stt,endd;
struct node{
	int x,y;
};
bool cmp(node a,node b){
	return a.x < b.x;
}
vector<node>ab;
bool flags = true;
int flag[500005],flag2[500005];
void con(int start,int now){
	ans = max(ans,now);
	if(to >= start){
		return;
	}
	for(int tb = start;tb <= cnt;tb++){
		to = tb;
		if(ab[tb].x > endd){
			endd = ab[tb].y;
			con(tb+1,now+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	for(int i = 1;i <= n;i++){
		flags = true;
		for(int j = i;j <= n && flags;j++){
			int ct = 0;
			for(int k = i;k <= j;k++){
				ct = ct ^ a[k];
			}
			if(ct == k){
				flags = false;
				ab.push_back({i,j});
				cnt++;
			}
		}
	}
	for(int i = 0;i < cnt;i++){
		if(to >= i){
			break;
		}
		to = i;
		stt = ab[i].x,endd = ab[i].y;
		con(i+1,1);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
