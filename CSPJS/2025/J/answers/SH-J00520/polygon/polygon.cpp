#include<bits/stdc++.h>
using namespace std;
ifstream fin ("polygon.in");
ofstream fout ("polygon.out");
int a[5009];
int main(){
	int n;
	fin >> n;
	for(int i = 0 ; i < n ; i++){
		fin >> a[i]; 
	}
	int c = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 2 ; j < n ; j++){
			int ans = 0;
			int cnt = 0;
			for(int k = i ; k <= j ; k++){
				ans += a[k];
			} 
			for(int k = i ; k <= j ; k++){
				if(ans < 2*a[k]){
					break;
				}
				else{
					cnt++;
				} 
			}
			if(cnt == j - i + 1){
				c++;
			}
		} 
	} 
	fout << c;
}
