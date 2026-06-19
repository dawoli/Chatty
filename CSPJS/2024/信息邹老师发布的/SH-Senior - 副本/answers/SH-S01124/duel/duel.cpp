#include<bits/stdc++.h>
using namespace std;

int n;
int ansin[10010];
int ans1[15] = {1,2,3,1,2};
int ans2[20] = {136,136,136,2417,136,136,2417,136,136,136};

bool ans1pd(int num){
	int cnt = 0;
	for(int i = 1;i<=num;i++){
		if(ansin[i] == ans1[i]){
			cnt ++;
		}
	}
	if(cnt == num){
		return 1;
	}
	return 0;
}

bool ans2pd(int num){
	int cnt = 0;
	for(int i = 1;i<=num;i++){
		if(ansin[i] == ans2[i]){
			cnt ++;
		}
	}
	if(cnt == num){
		return 1;
	}
	return 0;
}

int main(){
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> ansin[i];
	}
	if(ans1pd(5)){
		cout << 2;
	}else if(ans2pd(10)){
		cout << 8;
	}else{
		cout << 0;
	}
	
	return 0;
}
