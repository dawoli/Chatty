#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin>>n;
	bool flag[60];
	char nxt[2];
	int hs, ds;
	char huase[4] = {'D', 'C', 'H', 'S'};
	char dianshu[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	for (int i = 0; i < 52; i ++){
		flag[i] = 1;
	}
	for (int i = 0; i < n; i ++){
		cin>>nxt[0]>>nxt[1];
		for (int j = 0; j < 4; j++)
			if(nxt[0] == huase[j])
				hs = j;
		//cout<<hs;
		for (int j = 0; j < 13; j++)
			if(nxt[1] == dianshu[j])
				ds = j;
		//cout<<ds<<endl; 
		flag[hs * 13 + ds] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < 52; i ++){
		cnt += flag[i];
	}
	cout<<cnt;
	return 0;
}

