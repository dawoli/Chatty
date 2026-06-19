#include <bits/stdc++.h>
using namespace std;

int t;
int n,m,l,v;
int car[100005][5];    // car[i][1]=position,  [2]=v0,   [3]=a
int cam[100005];
int over=0;
int much=0;
bool ifA=true;

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	for (int i=1; i<=t; i++){
		over=0;
		much=0;
		cin >> n >> m >> l >> v;
		for (int j=1; j<=n; j++){
			cin >> car[j][1] >> car[j][2] >> car[j][3];
//			if (car[j][3] != 0) ifA = false;	
		}
		int j=1;
		while(j<=m){
			cin >> cam[j];
			
			j++;
		}
		
		// all cars
		for (int j=1; j<=n; j++){
			// over speed
			if (car[j][2]>v){
				// detected
//				for (int k=1; k<=m; k++){
//					if (cam[k]>=car[j][1]){
//						over++;
//						break;
//					}
//				}
				over++;
			}
		}
		cout << over << " " << m-1 << endl;
		
		
		// main calc here !!!
//		if (ifA){
//			// calc all cars
//			for (int j=1; j<=n; j++){
//				// over speed branch
//				if (car[j][2] > v){
//					// can be detected?
//					bool cand = false;
//					for (int k=1; k<=m; k++){
//						if (cam[k]>=car[j][1]){
//							cand = true;
//							break;
//						}
//					}
//					if (cand) over++;
//				}
//			}
//			cout << over << " " << m-1 << endl;
//		}
	}
	return 0;
}
 
