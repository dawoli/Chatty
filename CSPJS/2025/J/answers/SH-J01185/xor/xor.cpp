#include<bits/stdc++.h>

using namespace std;

struct node{
	int l;
	int r;
}b[500050];
int n,k,a[500050],s[500050],cnt,ans;
vector<int>es[500050];
inline int calc(int x,int y){
	return s[y]^s[x-1];
}
inline int fd(int lm,int rm,int num){
	int ll = 0,rr = es[num].size()-1;
	while(ll < rr){
		int mid = ll+rr>>1;
		if(es[num][mid] >= lm && es[num][mid] <= rm) rr = mid;
		else ll = mid+1;
	}
	return ll;
}
bool cmp(node x,node y){
	if(x.r == y.r) return x.l > y.l;
	return x.r < y.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;++i) cin>>a[i];
	for(int i = 1;i <= n;++i){
		s[i] = s[i-1]^a[i];
		es[s[i]].push_back(i);
	}
	if(n <= 1000){
		for(int i = 1;i <= n;++i){
			for(int j = i;j <= n;++j){
				if(calc(i,j) == k){
					b[++cnt].l = i;
					b[cnt].r = j;
					break;
				}
			}
		}
	}
	else{
		for(int i = 1;i <= n;++i){
			int aim = (s[i-1]^k);
			if(es[aim].size() == 0) continue;
			if(es[aim][es[aim].size()-1] < i) continue;
			int pos = es[aim][fd(i,n,aim)];
			if(i <= pos && pos <= n && s[pos] == aim){
				b[++cnt].l = i;
				b[cnt].r = pos;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	int nw = 0;
	for(int i = 1;i <= cnt;++i){
		if(b[i].l > nw){
			++ans;
			nw = b[i].r;
		}
	}
	cout<<ans;
	return 0;
}
