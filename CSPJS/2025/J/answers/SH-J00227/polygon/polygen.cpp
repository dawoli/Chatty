#include <bits/stdc++.h>
using namespace std;
long long a[100000];
/*bool cmp(long long a,long long b){
	return a > b;
}
long long ans = 0;*/
/*long long s(long long n,long long t){
	if(t >= n) return 0;
	else{
		for(int i = 0;i < n;i++)
			if(a[t]+a[s(n,t+i)] > 2 * a[t]) ans++;
	}
}*/
int main(){
	long long n;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a,a+n);
	if(n == 3){
		sort(a,a+n);
		int sum = 0;
		for(int i = 0;i < n;i++) sum += a[i];
		if(sum > 2*a[2]) cout << 1;
		else cout << 0;
		return 0;
	}
	if(n == 5){
		long long ans = 0;
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					if(a[i]+a[j]+a[k] > 2 * a[k])
						ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						if(a[i]+a[j]+a[k]+a[x] > 2 * a[x])
							ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							if(a[i]+a[j]+a[k]+a[x]+a[y] > 2 * a[y])
								ans++;
		cout << ans;
		return 0;
	}
	if(n == 4){
		long long ans = 0;
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					if(a[i]+a[j]+a[k] > 2 * a[k])
						ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						if(a[i]+a[j]+a[k]+a[x] > 2 * a[x])
							ans++;
		cout << ans;
		return 0;
	}
	if(n == 6){
		long long ans = 0;
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					if(a[i]+a[j]+a[k] > 2 * a[k])
						ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						if(a[i]+a[j]+a[k]+a[x] > 2 * a[x])
							ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							if(a[i]+a[j]+a[k]+a[x]+a[y] > 2 * a[y])
								ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx] > 2 * a[xx])
									ans++;
		cout << ans;
		return 0;
	}
	if(n == 7){
		long long ans = 0;
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					if(a[i]+a[j]+a[k] > 2 * a[k])
						ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						if(a[i]+a[j]+a[k]+a[x] > 2 * a[x])
							ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							if(a[i]+a[j]+a[k]+a[x]+a[y] > 2 * a[y])
								ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx] > 2 * a[xx])
									ans++;
									for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								for(int xxx = xx+1;xxx < n;xxx++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx]+a[xxx] > 2 * a[xxx])
									ans++;
		cout << ans;
		return 0;
	}
	if(n == 8){
		long long ans = 0;
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					if(a[i]+a[j]+a[k] > 2 * a[k])
						ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						if(a[i]+a[j]+a[k]+a[x] > 2 * a[x])
							ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							if(a[i]+a[j]+a[k]+a[x]+a[y] > 2 * a[y])
								ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx] > 2 * a[xx])
									ans++;
									for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								for(int xxx = xx+1;xxx < n;xxx++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx]+a[xxx] > 2 * a[xxx])
									ans++;
									for(int i = 0;i <n;i++)
										for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								for(int xxx = xx+1;xxx < n;xxx++)
								for(int yy = xxx+1;yy < n;yy++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx]+a[xxx]+a[yy] > 2 * a[yy])
									ans++;
		cout << ans;
		return 0;
	}
		if(n == 9){
		long long ans = 0;
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					if(a[i]+a[j]+a[k] > 2 * a[k])
						ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						if(a[i]+a[j]+a[k]+a[x] > 2 * a[x])
							ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							if(a[i]+a[j]+a[k]+a[x]+a[y] > 2 * a[y])
								ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx] > 2 * a[xx])
									ans++;
									for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								for(int xxx = xx+1;xxx < n;xxx++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx]+a[xxx] > 2 * a[xxx])
									ans++;
									for(int i = 0;i <n;i++)
										for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								for(int xxx = xx+1;xxx < n;xxx++)
								for(int yy = xxx+1;yy < n;yy++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx]+a[xxx]+a[yy] > 2 * a[yy])
									ans++;
									for(int i = 0;i <n;i++)
									for(int j = i+1;j < n;j++)
									for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								for(int xxx = xx+1;xxx < n;xxx++)
								for(int yy = xxx+1;yy < n;yy++)
								for(int yyy = yy+1;yyy<n;yyy++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx]+a[xxx]+a[yy]+a[yyy] > 2 * a[yyy])
									ans++;
		cout << ans;
		return 0;
	}
	if(n == 10){
		long long ans = 0;
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					if(a[i]+a[j]+a[k] > 2 * a[k])
						ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						if(a[i]+a[j]+a[k]+a[x] > 2 * a[x])
							ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							if(a[i]+a[j]+a[k]+a[x]+a[y] > 2 * a[y])
								ans++;
		for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx] > 2 * a[xx])
									ans++;
									for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								for(int xxx = xx+1;xxx < n;xxx++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx]+a[xxx] > 2 * a[xxx])
									ans++;
									for(int i = 0;i <n;i++)
										for(int j = i+1;j < n;j++)
				for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								for(int xxx = xx+1;xxx < n;xxx++)
								for(int yy = xxx+1;yy < n;yy++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx]+a[xxx]+a[yy] > 2 * a[yy])
									ans++;
									for(int i = 0;i <n;i++)
			for(int j = i+1;j < n;j++)
									for(int k = j+1;k < n;k++)
					for(int x = k+1;x < n;x++)
						for(int y = x+1;y < n;y++)
							for(int xx = y+1;xx < n;xx++)
								for(int xxx = xx+1;xxx < n;xxx++)
								for(int yy = xxx+1;yy < n;yy++)
								for(int yyy = yy+1;yyy<n;yyy++)
								for(int yyyy = yyy+1;yyyy < n;yyyy++)
								if(a[i]+a[j]+a[k]+a[x]+a[y]+a[xx]+a[xxx]+a[yy]+a[yyy]+a[yyyy] > 2 * a[yyyy])
									ans++;
		cout << ans;
		return 0;
	}
	//s(n,0);
	//cout << ans%998244353;
	return 0;
}
