#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],t,cnt,u,ans,j;
struct p{
	int start;
	int end;
}g[500005];
bool cmp(p a,p b){
	return a.end < b.end;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		t = a[i];
		j = i+1;
		if(t == k){
			cnt++;
			g[cnt].start = i;
			g[cnt].end = i;
		}
		while(t != k && j <= n){
			t ^= a[j];
			j++;
		}
		if(t == k){
			cnt++;
			g[cnt].start = i;
			g[cnt].end = j-1;
		}
	}
	sort(g+1,g+cnt+1,cmp);
	for(int i = 1;i <= cnt;){
		ans++;
		u = g[i].end;
		while(g[i].start <= u){
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
