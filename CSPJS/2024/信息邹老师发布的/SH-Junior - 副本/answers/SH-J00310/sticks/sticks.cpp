#include<bits/stdc++.h>
using namespace std;
string ans;
int t,n,c[10]{6,2,5,5,4,5,6,3,7,6},p[10]{8,0,6,9,2,3,5,4,7,1};
bool cmp(string s,int n){
	if(ans=="") return false;
	if(n==0&&s>=ans) return true;
	if(s.size()+(n/7)>ans.size()) return true;
}
void dfs(int n,string s,bool flag){
	if(n<0) return;
	if(ans!=""&&cmp(s,n)) return;
	if(n==0){
		if(ans=="") ans=s;
		else ans=min(ans,s);
		return;
	}
	if(n%7==0){
		for(int i=1;i*7<=n;++i) s+='8';
		if(ans=="") ans=s;
		else ans=min(ans,s);
		return;
	}
	for(int i=0;i<10;++i){
		if(n>=c[p[i]]&&(p[i]!=0||flag)){
			dfs(n-c[p[i]],s+char(p[i]|'0'),1);
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<=40){
			dfs(n,"",0);
			if(ans=="") ans="-1";
			cout<<ans<<"\n"; ans="";
			continue;
		}else if(n%7==1) putchar('1'),putchar('0'),n-=8;
		else if(n%7==2) putchar('1');
		else if(n%7==3) putchar('2'),putchar('0'),putchar('0'),n-=17;
		else if(n%7==4) putchar('2'),putchar('0'),n-=11;
		else if(n%7==5) putchar('2');
		else if(n%7==6) putchar('6');
		for(int i=1;i*7<=n;++i) putchar('8');
		putchar('\n');
	}
	return 0;
}
