#include<bits/stdc++.h>
using namespace std;
int n,ans = 0,maxc1 = INT_MIN,maxc2 = INT_MIN,maxc3 = INT_MIN,maxn = INT_MIN;
int a1,a2,a3;
int maxcc1,maxcc2,maxcc3,max123,rec;
int rmax,rmin,mid;
int maxc,minc;
struct culb{
	int c1,c2,c3;
}club[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 0;i < t;i ++){
		cin >> n;
		max123 = 0;
		a1 = 0;a2 = 0;a3 = 0;
		for(int i = 0;i < n;i ++){
			cin >> club[i].c1 >> club[i].c2 >> club[i].c3;
		}	
		for(int i = 0;i < n;i ++){
			for(int j = 0;j < n;j ++){
				maxc1 = max(maxc1,club[j].c1);
				if(club[j].c1 == maxc1) maxcc1 = i;
				
				maxc2 = max(maxc2,club[j].c2);
				if(club[j].c2 == maxc2) maxcc2 = i;
				
				maxc3 = max(maxc3,club[j].c3);
				if(club[j].c3 == maxc3) maxcc3 = i;
				
				maxn = max(max(maxc1,maxc2),maxc3);
				if(maxn == maxc1) rec = 1;
				else if(maxn == maxc2) rec = 2;
				else rec = 3;
				if (rec == 1){
					if(club[j].c1 == maxn) max123 = j;
				}
				else if (rec == 2){
					if(club[j].c2 == maxn) max123 = j;
				}
				else if (rec == 3){
					if(club[j].c3 == maxn) max123 = j;
				}
			}
			maxc = max(max(club[max123].c1,club[max123].c2),club[max123].c3);
			if(maxc == club[max123].c1) rmax = 1;
			else if(maxc == club[max123].c2) rmax = 2;
			else rmax = 3;
					
			minc = min(min(club[max123].c1,club[max123].c2),club[max123].c3);
			if(minc == club[max123].c1) rmin = 1;
			else if(minc == club[max123].c2) rmin = 2;
			else rmin = 3;
			if(rec == 1){
				if(a1>=n/2){
					if(rmax==1 && rmin==2){
						if(a3 >= n/2){
							ans += minc;
							club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
							maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
							a2++;
							continue;
						}
						mid = club[max123].c3;
						ans += mid;
						club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
						maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
						a3++;
						continue;
					} 
					else if(rmax==1 && rmin==3){
						if(a2 >= n/2){
							ans += minc;
							club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
							maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
							a3++;
							continue;
						}
						mid = club[max123].c2;
						ans += mid;
						club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
						maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
						a2++;
						continue;
					} 
				}
				else{
					ans += maxn;
					club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
					a1++;
					maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
					continue;
				}
			}
			else if(rec == 2){
				if(a2 >= n/2){
					if(rmax==2 && rmin==1){
						if(a3 >= n/2){
							ans += minc;
							club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
							maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
							a1++;
							continue;
						}
						mid = club[max123].c3;
						ans += mid;
						club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
						maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
						a3++;
						continue;
					} 
					else if(rmax==2 && rmin==3){
						if(a1 >= n/2){
							ans += minc;
							club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
							maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
							a3++;
							continue;
						}
						mid = club[max123].c1;
						ans += mid;
						club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
						maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
						a1++;
						continue;
					}	
				}
				else{
					ans += maxn;
					club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
					maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
					a2++;
					continue;
				}
			}
			else if(rec == 3){
				if(a3>=n/2){
					if(rmax==3 && rmin==1){
						if(a2 >= n/2){
							ans += minc;
							club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
							maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
							a1++;
							continue;
						}
						mid = club[max123].c2;
						ans += mid;
						club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
						maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
						a2++;
						continue;
					} 
					else if(rmax==3 && rmin==2){
						if(a1 >= n/2){
							ans += minc;
							club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
							maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
							a2++;
							continue;
						}
						mid = club[max123].c1;
						ans += mid;
						club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
						maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
						a1++;
						continue;
					}	
				}
				else{
					ans += maxn;
					club[max123].c1 = -1;club[max123].c2 = -1;club[max123].c3 = -1;
					maxc1 = INT_MIN;maxc2 = INT_MIN;maxc3 = INT_MIN;maxn = INT_MIN;
					a3++;
					continue;
				}
			}
		}
		cout << ans << endl;
		ans = 0;
		
	} 
	return 0;
}
