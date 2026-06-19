#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
vector <int> ls[N];//val1~3
vector <int> ls1,ls2,ls3;
int n;
map <vector<int>,int> vis;
bool flag1,flag2,flag3;
//int read(){
//	int x = 0,f = 1;
//	char c = getchar();
//	while(c<'0' and c>'9'){
//		if(c == '-')f=-1;
//		c = getchar();
//	}
//	while(c>='0' and c<='9'){
//		x = x*10+c-'0';
//		c = getchar();
//	}
//	return x*f;
//}
bool cmp(int a,int b){
	return a>b;
}
int dfs(int pos,int cnt1,int cnt2,int cnt3,int res){
	if(pos>n)return res;
	int ret=res;
	vector<int> postot(3);
	postot[0] = cnt1;postot[1] = cnt2;postot[2] = cnt3;
	if(cnt1<(n>>1) and !flag1){
		postot[0]++;
		if(vis.find(postot)!=vis.end()){
			if(vis[postot]<res+ls[pos][0]){
				vis[postot] = res+ls[pos][0];
				ret = max(ret,dfs(pos+1,cnt1+1,cnt2,cnt3,res+ls[pos][0]));
			}
		}
		else{
			vis[postot] = res+ls[pos][0];
			ret = max(ret,dfs(pos+1,cnt1+1,cnt2,cnt3,res+ls[pos][0]));
		}
		postot[0]--;
	}
	if(cnt2<(n>>1) and !flag2){
		postot[1]++;
		if(vis.find(postot)!=vis.end()){
			if(vis[postot]<res+ls[pos][1]){
				vis[postot] = res+ls[pos][1];
				ret = max(ret,dfs(pos+1,cnt1,cnt2+1,cnt3,res+ls[pos][1]));
			}
		}
		else{
			vis[postot] = res+ls[pos][1];
			ret = max(ret,dfs(pos+1,cnt1,cnt2+1,cnt3,res+ls[pos][1]));
		}
		postot[1]--;
	}
	if(cnt3<(n>>1) and !flag3){
		postot[2]++;
		if(vis.find(postot)!=vis.end()){
			if(vis[postot]<res+ls[pos][2]){
				vis[postot] = res+ls[pos][2];
				ret = max(ret,dfs(pos+1,cnt1,cnt2,cnt3+1,res+ls[pos][2]));
			}
		}
		else{
			vis[postot] = res+ls[pos][2];
			ret = max(ret,dfs(pos+1,cnt1,cnt2,cnt3+1,res+ls[pos][2]));
		}
		postot[2]--;
	}
	return ret;
}
void solve(){
	flag1 = flag2 = flag3 = 1;
	vis.clear();
	ls1.clear();
	ls2.clear();
	int a,b,c;
	cin>>n;
	vector <int> k;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		if(a != 0)flag1 = 0;
		if(b != 0)flag2 = 0;
		if(c != 0)flag3 = 0;
		ls1.push_back(a);
		ls2.push_back(b);
		ls3.push_back(c);
		k.clear();
		k.push_back(a);
		k.push_back(b);
		k.push_back(c);
		ls[i] = k;
	}
	if(flag3 and flag2){
		sort(ls1.begin(),ls1.end(),cmp);
		int tot1=0;
		for(int i=0;i<(n>>1);i++)tot1+=ls1[i];
		cout<<tot1<<"\n";
	}
	else if(flag3 and flag1){
		sort(ls2.begin(),ls2.end(),cmp);
		int tot1=0;
		for(int i=0;i<(n>>1);i++)tot1+=ls2[i];
		cout<<tot1<<"\n";
	}
	else if(flag1 and flag2){
		sort(ls3.begin(),ls3.end(),cmp);
		int tot1=0;
		for(int i=0;i<(n>>1);i++)tot1+=ls3[i];
		cout<<tot1<<"\n";
	}
	else cout<<dfs(1,0,0,0,0)<<"\n";
	return;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
