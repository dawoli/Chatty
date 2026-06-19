
#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int t;
int car[100010][3];
int spd[100010];
int spdca[100010]; 
int spdc[100010]; 
int countcd = 0;
int clospd = 0;

int main(){
	freopen("detect.in","r",stdin);
	freopen("detcet.out","w",stdout);
	cin >> t;
	for (int i = 0;i < t;i++){
		int n;
		int m;
		int L;
		int V;
		cin >>n >> m >> L >> V; 
		for (int j = 0;j < n;j++){
			cin >> car[j][0] >> car[j][1] >> car[j][2];
		}
		for (int j = 0;j < m;j++){
			cin >> spd[j];
		}
		
		for (int j = 0;j < n;j++){
		
			float changedis = (V*V-car[j][1]*car[j][1]) / (2 * car[j][2]);
			if (changedis == 0){
				changedis = 0x3f;
			}
			float abovespeedplace = car[j][0] + changedis;
			for (int k = 0;k < m;k++){
				if (spd[k] > abovespeedplace){
					spdc[k] += 1;
					countcd += 1;
					
				}
			}
		}
		for (int i = 0;i < m;i++){
			if (spdc[i] == 0){
				clospd += 1;
			}
		}
		cout << countcd << " " << clospd <<endl;
	}

	return 0;
}
