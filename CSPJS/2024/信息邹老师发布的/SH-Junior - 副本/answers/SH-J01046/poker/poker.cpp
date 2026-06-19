#include<bits/stdc++.h>
using namespace std;
const int maxn = 5,maxm = 15;
map<char,int> mp;
bool poker[maxn][maxm];
int n,ans = 52;

void init(){
	mp['A'] = 1;
	mp['T'] = 10;
	mp['J'] = 11;
	mp['Q'] = 12;
	mp['K'] = 13;

	mp['D'] = 1;
	mp['C'] = 2;
	mp['H'] = 3;
	mp['S'] = 4;
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	init();
	scanf("%d\n",&n);
	for(int i = 1;i <= n;i ++){
		char a,b;
		int x,y;
		scanf("%c%c\n",&a,&b);
		x = mp[a];
		if('2' <= b && b <= '9')	y = b - '0';
		else	y = mp[b];
		if(!poker[x][y]){
			poker[x][y] = true;
			ans --;
		}
	}
	printf("%d",ans);
	return 0;
}
