#include <bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
struct o {
	int d,v,a;
	int chaosulight = -1;
	int qichulight = 0;//被哪个灯记录了超速 
}cars[10050];//记录车的信息 
int light[1005];//记录灯的位置 
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--) {
		cin >> n >> m >> L >> V;
		int chaosu = 0;
		int left = -1,right = 1000005;
		for(int i = 1;i <= n;i++) {
			cin >> cars[i].d >> cars[i].v >> cars[i].a;
		}
		for(int i = 1;i <= m;i++) {
			cin >> light[i];
		}
		for(int i = 0;i <= n;i++) {
			if(cars[i].d <= light[m]) {
				if(cars[i].a == 0 && cars[i].v > V) {
					chaosu++;
					for(int j = 1;j <= m;j++) {
						if(cars[i].d <= light[j]) {
							cars[i].chaosulight = j;
							if(left < j)
								left = j;
							break;
						}	
					}
				}
				else if(cars[i].a > 0) {
					int len = light[m] - cars[i].d;
					if((cars[i].v * cars[i].v + 2 * cars[i].a * len) > V * V) {
						chaosu++;
						for(int j = 1;j <= m;j++) {
							if(cars[i].d <= light[j]) {
								int len1 = light[j] - cars[i].d;
								if((cars[i].v * cars[i].v + 2 * cars[i].a * len1) > V * V) {
									cars[i].chaosulight = j;
									if(left < j)
										left = j;
									break;
								}
							}	
						}
					}
				}
				else {
					int flag = 0;
					for(int j = 1;j <= m;j++) {
						if(cars[i].d <= light[j]) {
							int len = light[j] - cars[i].d;
							int speed = cars[i].v * cars[i].v + 2 * cars[i].a * len;
							if(speed <= 0) {
								break;
							}
							else {
								if(speed > V * V) {
									if(flag == 0) {
										chaosu++;
										cars[i].qichulight = j;
									}	
									cars[i].chaosulight = j;
									flag = 1;
								}
							}
						}
					}
				}		
			}
		}
		cout << chaosu << ' ';
		int xy[100005] = {0};
		for(int i = 1;i <= n;i++) {
			if(cars[i].chaosulight != -1) {
				if(cars[i].a >= 0) {
					for(int j = cars[i].chaosulight;j <= m;j++) {
						xy[j]++;
					}
				}
				else if(cars[i].a < 0) {
					for(int j = cars[i].qichulight;j <= cars[i].chaosulight;j++) {
						xy[j]++;
					}
				}
			}
		}
		sort(xy,xy + m + 1);
		cout << m - (chaosu - xy[m] + 1) << endl;
	}
	return 0;
} 
