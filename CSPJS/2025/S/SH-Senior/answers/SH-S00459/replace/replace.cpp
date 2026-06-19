#include<bits/stdc++.h>
using namespace std;
int N, Q;
string sList[200009][2], tList[200009][2];
int sSizeList[200009], tSizeList[200009];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> N >> Q;
	for (int i = 0; i < N; i ++){
		string t, u;
		cin >> t >> u;
		sSizeList[i] = t.length();
		//cout << sSizeList[i] <<endl;
		sList[i][0] = t;
		sList[i][1] = u;
	}
	for(int k = 0; k < Q; k ++){
		string t, u;
		cin >> t >> u;
		tSizeList[k] = t.length();
		tList[k][0] = t;
		tList[k][1] = u;
	}
	for(int j = 0; j < Q; j ++){
		int cnt = 0;
		int lenT = tSizeList[j];
			
		for (int i = 0; i < N; i ++){
			int lenS = sSizeList[i];
			
			//cout << (sList[i][0][4]);
			if (lenS > lenT) continue;
			for(int k = 0; k < lenT - lenS + 1; k ++){
				bool flag = 0;
				for (int l = 0; l < lenS; l ++){
					//if (i == 0&& j == 0)cout << lenT << lenS << endl;
					if (sList[i][0][l] != tList[j][0][k+l]) {
						flag = 1;
						break;
					}
				}
				
				//if (j == 0)cout <<"here";
				if (flag == 1) continue;
				//if (j == 0)cout <<"here";
				char la, lb;
				flag = 0;
				for (int l = 0; l < lenT; l ++){
					if (k <= l && l < k + lenS){
						la = sList[i][1][l - k];
					}
					else{
						la = tList[j][0][l];
					}
					lb = tList[j][1][l];
					if(la != lb){
						flag = 1;
						break;
					}
				}
				if (flag == 0){
					cnt ++;
					//cout << i << j << k <<endl;
				}
			}
			
		}
		cout << cnt <<endl;
	}
	return 0;
}

