#include<bits/stdc++.h>
using namespace std;
struct poker{
	char a;
	char b;
} poker[55];
int n,num;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> poker[i].a >> poker[i].b;
		num ++;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = i+1;j <= n;j ++){
			if(poker[i].a == poker[j].a && poker[i].b == poker[j].b){
				num --;
				break;
			}
		}	
	}
	int sum = 52-num;
	if(sum <= 0) cout << 0;
	else cout << sum;
	return 0;
}
