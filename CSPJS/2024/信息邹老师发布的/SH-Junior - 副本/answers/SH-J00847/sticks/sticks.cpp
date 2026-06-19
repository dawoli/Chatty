#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int t,n;
int sticks[N]={6,2,5,5,4,5,6,3,7,6};//每个数字需要多少根木棍 
int number[N]={0,1,2,3,4,5,6,7,8,9};//搜索顺序 
bool found;//是否被找到 
string ans,empty_string="";
inline bool cmp(int x,int y)
{
	//按小木棍数量从大到小排序 
	if(sticks[x]==sticks[y]) return x<y;
	return sticks[x]>sticks[y];
}
inline bool cmp1(string x,string y)
{
	if(x.length()==y.length()) return x<y;
	return x.length()<y.length();
}
inline void init()
{
	//排序number使dfs函数运行速度更快，并保证不会出现答案错误 
	sort(number,number+10,cmp);
}
inline void dfs(int n,int last,string str)
{
	//n:剩余木棍数 
	//str:正整数表示答案 
	//last:上一个数字 
	if(n<0) return;
	if(n==0){
		if(found) ans=min(ans,str,cmp1);
		else{
			ans=str;
			found=true;
		}
		return;
	}
	if(str.size()==1) dfs(n-sticks[0],0,str+'0');
	for(int i=0;i<=9;++i){
		int x=number[i];
		if(x<last) continue;
		//if(x==0) continue;
		dfs(n-sticks[x],x,str+char(x+'0'));
	}
}
inline void clear()
{
	//多测清空 
	found=false;
}
inline void solve()
{
	cin>>n;
	if(n%7==0){
		for(int i=1,tmp=n/7;i<=tmp;++i) cout<<"8";
		cout<<endl;
		return;
	}
	if(n!=1&&n%7==1){
		cout<<"10";
		for(int i=1,tmp=n/7-1;i<=tmp;++i) cout<<"8";
		cout<<endl;
		return;
	}
	clear();
	for(int i=0;i<=9;++i){
		int x=number[i];
		if(x==0) continue;
		dfs(n-sticks[x],x,empty_string+char(x+'0'));
	}
	if(found) cout<<ans<<endl;
	else cout<<"-1"<<endl;
}
inline void Main()
{
	//abcdefghijklmnopqrstuvwxyz
	init();
	cin>>t;
	for(int i=1;i<=t;++i) solve();
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Main();
	fclose(stdin);
	fclose(stdout);
 	return 0;
}

