#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
long long n,m,x,y,k;
int nums[1005][1005];
vector<int> lasts;
long long s = 0;
int d = 0;
long long z = 0,h = 0;

void init(){
	memset(nums,0,sizeof(nums));
}

inline void d1(int d){
	if (d == 0){
		h = h + 1;
	}
	if (d == 1){
		z = z + 1;
	}
	if (d == 2){
		h = h - 1;
	}
	if (d == 3){
		z = z - 1;
	}
}

void dfs(){
	if (k == 0){
		s = s + 1;
		lasts.push_back(s);
		return;
	}
	z = x;
	h = y;
	if (z > 0 && h > 0 && z < n && h < m && nums[z][h] == 0){
		s++;
		k--;
		dfs();
	}
	d++;
	if (d == 4){
		d = 0;
	}
	d1(d);
	k--;
	dfs();
}

int main(){
	freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	
	int T;
	cin >> T;
	for (int i = 0;i < T;i++){
		long long n,m;
		init();
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (long long q = 0;q < n;q++){
			for (long long j = 0;j < m;j++){
				string str;
				cin >> str;
				if (str == "x") {
					nums[q][j] = 1;
				}
				if (str == "."){
					nums[q][j] = 0;
				}
			}
		}
		dfs();
	}
	for (int i = 0;i < T;i++){
		cout << lasts[i] << endl;
	}
	
	fclose(stdin);
    fclose(stdout);
	return 0;
}


