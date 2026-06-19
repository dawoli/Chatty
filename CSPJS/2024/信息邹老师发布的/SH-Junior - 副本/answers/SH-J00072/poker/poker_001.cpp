#include <bits/stdc++.h>
using namespace std;
int n,t,flag;
string p[55],s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> s;
		flag = 0;
		for(int j = 1;j<=t;j++){
			if(s==p[j]){
				flag = 1;
				break;
			}
		}
		if(flag==0){
			t++;
			p[t] = s;
		}
	}
	cout << 52-t;
	return 0;
}
