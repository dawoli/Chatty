#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
const int INF=1e6;
const int d[19]={6,2,5,5,4,5,6,3,7,6};
/*
0 6
1 2
2 5
3 5
4 4
5 5
6 6
7 3
8 7
9 6
*/
int f[N],p[N],appear19[N];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=0;i<=1e5;i++) f[i]=1e6;
	for(int i=0;i<=1e5;i++) p[i]=1e6;
	f[0]=0;
	for(int i=1;i<=1e5;i++){
		if(i>=d[0]){
			if(appear19[i-d[0]]==1&&(f[i-d[0]]+1<f[i]||(f[i-d[0]]+1==f[i]&&0<p[i]))){
				f[i]=f[i-d[0]]+1;
				p[i]=0;
			}
		}
		for(int now=1;now<=10;now++){
			if(i>=d[now]){
				if(f[i-d[now]]+1<f[i]||(f[i-d[now]]+1==f[i]&&now<p[i])){
					f[i]=f[i-d[now]]+1;
					p[i]=now;
					appear19[i]=1;
				}
			}
		}
	}
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		if(f[n]==INF) puts("-1");
		else{
			vector<int> t;
			while(n!=0){
				t.push_back(p[n]);
				n-=d[p[n]];
			}
			sort(t.begin(),t.end());
			int temp=-1;
			for(int i=0;i<t.size();i++){
				if(t[i]!=0){
					temp=t[i];
					break;
				}
				else continue;
			}
			printf("%d",temp);
			for(int i=0;i<t.size();i++){
				if(t[i]==temp){
					temp=-1;
					continue;
				}
				else printf("%d",t[i]);
			}
			puts("");
		}
	}
	return 0;
}
