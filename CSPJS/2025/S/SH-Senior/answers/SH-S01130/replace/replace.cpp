#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,q;
string s[maxn][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i = 1;i <= n;i ++){
		cin >> s[i][0] >> s[i][1];
	}
	for(int i = 1;i <= q;i ++){
		int cnt = 0;
		string a,b;
		cin >> a >> b;
		for(int j = 1;j <= n;j ++){
			if(a.find(s[j][0]) == -1)	continue;
			int pos = 0; 
			while(a.find(s[j][0],pos) != -1){
				int p = a.find(s[j][0],pos);
				string x = a.substr(0,p),y = a.substr(p + s[j][0].length(),a.length() - p - s[j][0].length());
				pos = p + 1;
				string pp = x +s[j][1] + y;
				if(pp == b)	cnt ++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
