#include <iostream>
#include <algorithm>
#include <cmath>
const int maxn = 1e5 + 5;

struct Node{
	int start, speed, pluspeed;
};

bool cmp(Node x, Node y){
	if(x.start != y.start)
	return x.start < y.start;
	else if(x.speed != y.speed)
	return x.speed < y.speed;
	else return x.pluspeed < y.pluspeed;
}

Node car[maxn];
int monitor[maxn];
bool needed_monitor[maxn];


int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	int t;
	std::cin >> t;
	for(int i = 1; i <= t; ++i){
		for(int j = 0; j <= maxn; ++j){
			car[j].pluspeed = 0;
			car[j].speed = 0;
			car[j].start = 0;
		}
		
		bool least_one = 0;
		
		int n, m, L, V;
		std::cin >> n >> m >> L >> V;
		for(int j = 1; j <= n; ++j)
			std::cin >> car[j].start >> car[j].speed >> car[j].pluspeed;
		for(int j = 1; j <= m; ++j)
			std::cin >> monitor[j];
			
		std::sort(car + 1, car + 1 + n, cmp);

		long long overspeed_car = 0;
		for(int j = 1; j <= n; ++j){
			if(car[j].pluspeed == 0 && car[j].speed > V && car[j].start <= monitor[m]){
				least_one = 1;
				overspeed_car++;				
			}

			if(car[j].pluspeed > 0 && car[j].start <= monitor[m]){
				double last_monitor_speed = std::sqrt(car[j].speed * car[j].speed + 2 * car[j].pluspeed * (monitor[m] - car[j].start));
				if (last_monitor_speed > V) {
					least_one = 1;
					overspeed_car++;
				}
			}
		}
		
		std::cout << overspeed_car << " ";
		if(least_one)
			std::cout << m - 1 << std::endl;
		else
			std::cout << m << std::endl;
	}
	
}
