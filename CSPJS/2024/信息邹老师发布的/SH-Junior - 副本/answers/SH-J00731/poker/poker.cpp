#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt = 0,flag = 0;
	string a[55] ;
	string all[60] = {"D1","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
					"C1","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK",
					"H1","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
					"S1","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		for(int j = 0;j < 52;j++){
			if(a[i] == all[j])
				flag = 1;
				break;
		}
		if(flag == 1) cnt++;	
	}
	int ans = 52-cnt;
	cout << ans;
	
	return 0;
} 
