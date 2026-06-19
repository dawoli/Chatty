#include<iostream>
int n;
int a[102];
int b[200002];
int mem[102][102][102];
int mem2[12][12][200002];
int s(int x, int y, int t) {
	if (t==n) return 0;
	if (mem[x][y][t] < 0) {
		int q = s(x, a[t], t+1) + (a[t]==y?a[t]:0);
		int w = s(a[t], y, t+1) + (a[t]==x?a[t]:0);
		mem[x][y][t] = q>w?q:w;
	}
	return mem[x][y][t];
}
int s2(int x, int y, int t) {
	if (t==n) return 0;
	if (mem2[x][y][t] < 0) {
		int q = s(x, a[t], t+1) + (a[t]==y?a[t]:0);
		int w = s(a[t], y, t+1) + (a[t]==x?a[t]:0);
		mem2[x][y][t] = q>w?q:w;
	}
	return mem2[x][y][t];
}
void solve(){
	std::cin >> n;
	if(n<101){
	
	for (int z=0;z<=101;z++)for(int x=0;x<=101;x++)for(int c=0;c<=101;c++)mem[z][x][c]=-1;
	for(int i=0;i<n;i++)std::cin>>a[i];
	std::cout << s(101, 101, 0);}else{
			for (int z=0;z<=200001;z++)for(int x=0;x<=11;x++)for(int c=0;c<=11;c++)mem2[x][c][z]=-1;
	for(int i=0;i<n;i++)std::cin>>b[i];
	std::cout << s2(11, 11, 0);
	}
	
}
int main(){int h;std::cin >> h;for(int i=0;i<h;i++)solve();
}
