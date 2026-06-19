#include<iostream>
#include<algorithm>
#define INF 100000000
using namespace std;

int n,minn[51],b[100000];
int t,tmp,minnn;
const int a[10] = {6,2,5,5,4,5,6,3,7,6};

void dfs(int num,int v){
	if (num == 0){
		for (int i=v;i>0;i--){
			minnn = minnn*10 +b[i];
		}
		minn[tmp] = min(minn[tmp],minnn);
	}
	
	for (int i=0;i<10;i++){
		if (a[i] < num){
			b[v+1] = i;
			dfs(num-a[i],v+1);
		}
	}
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for (int i=0;i<t;i++) minn[i] = INF;
	for (tmp=0;tmp<t;tmp++){
		cin >> n;
		if (n == 1) minn[tmp] = -1;
		else if (n == 2) minn[tmp] = 1;
		else if (n == 3) minn[tmp] = 7;
		else if (n == 4) minn[tmp] = 4;
		else if (n == 6) minn[tmp] = 6;
		else if (n == 18) minn[tmp] = 208;
		else if (n == 5) minn[tmp] = 2;
		else if (n == 7) minn[tmp] = 8;
		else if (n == 8) minn[tmp] = 10;
		else if (n == 9) minn[tmp] = 18;
		else if (n == 10) minn[tmp] = 22;
		else if (n == 11) minn[tmp] = 20;
		else if (n == 12) minn[tmp] = 28;
		else if (n == 13) minn[tmp] = 80;
		else if (n == 14) minn[tmp] = 88;
		else if (n == 15) minn[tmp] = 108;
		else if (n == 16) minn[tmp] = 188;
		else if (n == 17) minn[tmp] = 200;
		else if (n == 19) minn[tmp] = 288;
		else if (n == 20) minn[tmp] = 688;
		else dfs(n,0);
	}
	for (int i=0;i<t;i++){
		if (minn[i] != INF) cout << minn[i]<< endl;
		else cout << -1 << endl;
	}
	return 0;
}
