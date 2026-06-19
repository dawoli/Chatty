#include<bits/stdc++.h>
using namespace std;
ifstream fin ("xor.in");
ofstream fout ("xor.out");
long long a[2000009];
int main(){
	int n , k;
	fin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		fin >> a[i];
	}
	if(k == 0){
		fout << "1";
		return 0;
	}
	int b = n - 1 , e = n;
	while(b > e){
		int ans1 = a[1]; 
		for(int i = 1 ; i <= b ; i++){
			ans1 = a[i] ^ ans1;
		}
		int ans2 = a[e];
		for(int i = e + 1 ; i <= n ; i++){
			ans2 = a[i] ^ ans2;
		}
		if(ans1 == ans2 == k){
			fout << max(ans1 , n - ans2);
			break;
		}
		else if(ans1 > k){
			b--;
			e++;
		}
		else if(ans2 > k){
			b++;
			e--;
		}
	}
	return 0;
}
