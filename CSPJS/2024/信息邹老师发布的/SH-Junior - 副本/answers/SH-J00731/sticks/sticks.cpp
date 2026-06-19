#include <bits/stdc++.h>
using namespace std;
int T,n[55],ans[55];
int count(int num){
	if(num == 1) return -1;
	else if(num == 2) return 1;
	else if(num == 3) return 7;
	else if(num == 4) return 4;
	else if(num == 5) return 2;
	else if(num == 6) return 6;
	else if(num == 7) return 8;
	else if(num-2 <= 7){
		if(num-2 == 6) return 10;
		else  return 10+count(num-2);
	}
	else if(num-5 <= 7){
		if(num-5 == 6) return 20;
		else  return 20+count(num-5);
	}
	else if(num == 13)return 68;
	else if(num == 14)return 88;
	else if(num == 15)return 108;
	else if(num == 16)return 188;
	else if(num == 17)return 200;
	else if(num == 18)return 208;
	else if(num == 19)return 608;
	else if(num == 20)return 808;
	else if(num == 21)return 888;
	else if(num % 7 == 0 && num >= 100){
		int b = num / 7;
		int c = 1;
		int d = 0;
		for(int i = 1;i <= b;i++){
			d += 8*c;
			c *= 10;
		}
		return d;
	}
	else if(num % 7 == 1 && num >= 100){
		int b = num / 7;int c = 1;int d = pow(10,b+1);
		for(int i = 1;i <= b;i++){
			d += 8*c;
			c *= 10;
		}
		return d;
	}
	else return 8888;
	

}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> T;
	for(int i = 1;i <= T;i++){
		cin >> n[i];
		ans[i] = count(n[i]);
	}
	for(int i = 1;i <= T;i++)
		cout << ans[i] << endl;
	
	return 0;
}
