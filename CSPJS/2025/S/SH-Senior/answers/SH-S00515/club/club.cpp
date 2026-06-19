#include<bits/stdc++.h>
using namespace std;

struct note{
	int x, y, z;
}a[300005];

bool cmp(note q, note p){
	return q.x > p.x;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long t;
	cin >> t;
	for(long long k = 0;k < t;k++){
		long long n, ans = 0;
		cin >> n;
		int ab, ac, ad;
		for(long long i = 0;i < n;i++){
			cin >> ab >> ac >> ad;
			a[3*i].x = ab;
			a[3*i].y = i;
			a[3*i].z = 1;
			a[3*i+1].x = ac;
			a[3*i+1].y = i;
			a[3*i+1].z = 2;
			a[3*i+2].x = ad;
			a[3*i+2].y = i;
			a[3*i+2].z = 3;
		}
		sort(a, a + 3 * n, cmp);
		//ceshi
		//for(long long i = 0;i < 3*n;i++){
		//	cout << a[i].x << " " << a[i].y << " "<< a[i].z << endl;
		//}
		int ta = 0, tb = 0, tc = 0;
		bool l[100005] = {};
		for(int i = 0;i < 3*n;i++){
			if(l[i] == true || ta >= n / 2 || tb >= n / 2 || tc >= n / 2){
				continue;
			}
			ans += a[i].x;
			l[a[i].y] = true;
			if(a[i].z == 1){
				ta++;
			} else if(a[i].z == 2){
				tb++;
			} else {
				tc++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
