#include <fstream>
using namespace std;
ifstream fin("sticks.in");
ofstream fout("sticks.out");
int use[10]={0,1,2,4,6,7,8},num[10]={6,2,5,4,6,3,7};
int ans[10],cur;
bool dp(int sticks,int d){
	if (sticks==0)
		return (d==0);
	else if (sticks<0 or sticks==1)
		return 0;
	if (d==1){
		if (sticks>7)
			return 0;
		else{
			if (sticks==2) ans[cur]=1;
			else if (sticks==3)	ans[cur]=7;
			else if (sticks==4) ans[cur]=4;
			else if (sticks==5) ans[cur]=2;
			else if (sticks==6) ans[cur]=0;
			else if (sticks==7) ans[cur]=8;
			cur--;
			return 1;
		}
	}
	for (int i=0;i<=6;i++){
		if (dp(sticks-num[i],d-1)){
			ans[cur]=use[i];
			cur--; 
			return 1;
		}
	}
}
int main(){
	int T;
	fin >> T;
	while (T--){
		int n;
		bool flag=0;
		fin >> n;
		if (n<=1){
			fout << -1 << endl;
			continue;
		}
		int digits=(n+6)/7;
		bool print=0;
		int toprint=digits-5;
		if (digits>5){
			print=1;
			n-=toprint*7;
			digits=5;
		}
		cur=digits;
		for (int i=1;i<=6;i++){
			if (dp(n-num[i],digits-1)){
				ans[cur]=use[i];
				flag=1;
				break;
			}
		}
		if (!flag){
			fout << -1 << endl;
			continue;
		}
		for (int i=1;i<=digits;i++)
			fout << ans[i];
		if (print)
			for (int i=0;i<toprint;i++)
				fout << 8;
		fout << endl;
	}
	return 0;
}
