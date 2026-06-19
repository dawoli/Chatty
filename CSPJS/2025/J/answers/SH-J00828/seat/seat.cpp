#include<bits/stdc++.h> 
int m;
int n;
int Score[10001];
bool compare(int i,int j){
	return i > j;
}
int main(){
	std :: freopen("seat.in","r",stdin);
	std :: freopen("seat.out","w",stdout);
	std :: cin >> m;
	std :: cin >> n;
	for(int i = 1;i <= m*n;i++){
		std :: cin >> Score[i];
	}
	int ScoreR = Score[1];
	std :: sort(Score+1,Score+m*n+1,compare);
	for(int i = 1;i <= m*n;i++){
		if(Score[i] == ScoreR){
			if(i%n==0){
				std::cout << i/n << ' ';
				if((i/n) % 2 == 0){
					std :: cout << n-i%n;
				}
				else{
					std :: cout << i%n+n;
				}
			}
			else {
				std::cout << (i-i%n)/n+1 << ' ';
				if(((i-i%n)/n+1) % 2 == 0){
					std :: cout << n-i%n;
				}
				else{
					std :: cout << i%n;
				}
			}
			return 0;
		}
	}
	return 0;
}
	
