#include<fstream>
#include<iostream>
using namespace std;

int main(){
	ifstream fin("duel.in");
	ofstream fout("duel.out");
	int n,a[100001],b,fmin = 1,fa = 1,min_ = 1000010,ans = 0,x = 1;
	fin >> n;
	for(int i = 1;i <= n;i++){
		fin >> a[i];
		if(a[i] <= min_){
			min_ = a[i];
		}
	}
	while(a[x] == min_){
		fmin++;
		x++;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(a[i] >= a[j]){
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
	}
	for(int i = fmin;i <= n;i++){
		if(a[fmin] > a[fa]){
			a[fa] = -1;
			fa++;
		}
		fmin++;
	}
	for(int i = 1;i <= n;i++){
		if(a[i] != -1){
			ans++;
		}
	}
	fout << ans;
	return 0;
} 
