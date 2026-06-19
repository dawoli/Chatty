#include <bits/stdc++.h>
using namespace std;
string st_1[53] = {"","DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
bool st_2[53];
string st_3[53];
int nn,cntt;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> nn;
	for(int i = 1;i <= nn;i++){
		cin >> st_3[i];
		for(int j = 1;j <= 52;j++){
			if(st_3[i] == st_1[j]) st_2[j] = 1;
		}
	}
	for(int i = 1;i <= 52;i++){
		if(st_2[i] == 0) cntt++;
	}
	cout << cntt;
	return 0;
}
