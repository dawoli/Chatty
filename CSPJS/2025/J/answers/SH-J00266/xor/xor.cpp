#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005];
bool flag = true;
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	fin>>n>>k;
	for(int i = 1; i <= n; ++i){
		fin>>a[i];
		if(a[i] == 0)
			flag = false;
	}
	if(k == 0 && flag){
		fout<<n/2;
	}
	else if(k == 1){
		int zcnt = 0, ocnt = 0, ans= 0;
		for(int i = 1; i<= n; ++i){
			if(a[i] == 0)
				zcnt+=1;
			else
				ocnt+=1;
			if(zcnt == ocnt && (zcnt+ocnt)%4!=0){
				ans++;
				zcnt = ocnt = 0;
			}
		}
		fout<<ans;
	}
	else if(k == 0){
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			if(a[i] == 0)
				ans++;
			else if(a[i] == a[i+1]){
				ans++;
				i+=1;
			}
			else
				continue;
		}
		fout<<ans;
	}
	return 0;
}
