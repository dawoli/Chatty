#include <bits/stdc++.h>

using namespace std;

const int maxn = 100020;
double n,m,L,V,T;
double ans1, ans2, pmax;
double v[maxn], a[maxn], d[maxn],p[maxn];

double fastread(){
	
	int x =0, f = 1;
	char ch = getchar();
	
	while(ch > '9' || ch < '0'){
		
		if(ch = '-') f = -1;
		ch = getchar();
	}
	
	while(ch <= '9' && ch >= '0'){
		
		x = x*10 + ch -'0';
		ch = getchar();
	}
	
	return x*f;
	
}

double check(double vlimit, double vstart, double a){
	
	return (vlimit*vlimit - vstart*vstart)/(2*a);	
	
}

int check1(int l, int r, double tl, double tr){

	int mid;
	while(l < r){
		
		mid = (l+r)>>1;
		if(p[mid] >= tl && p[mid] <= tr) return p[mid];
		else if(p[mid] < tl) l = mid+1;
		else if(p[mid] > tr) r = mid-1;
		 
	}
	return -1;
	
} 

int main(){
	
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	T =fastread();
	
	for(int i = 1; i <= T ; i ++){
		
		n =fastread();
		m =fastread();
		L =fastread();
		V =fastread();
		
		ans1 = 0;
		ans2 = 0;
		pmax = 0;
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		memset(p,0,sizeof(p));
		
		
		for(int j = 1; j <= n; j ++){
			d[j] =fastread();
			v[j] =fastread();
			
			a[j] =fastread();
			
			
		}
		for(int j = 1; j <= m; j ++){
			
			p[j] =fastread();
			pmax = max(pmax, p[j]);
			
		}
		
		for(int j = 1; j <= n; j ++){
			
			if(a[j] > 0){
				
				if(check(V,v[j],a[j]) < pmax -d[j] && pmax >= d[j]){
					
					ans1++;	
					//cout << check(V,v[j],a[j]) << endl;
					
				} 
			
			}
			
			else if(a[j] == 0){
				
				if(v[j] > V && pmax >= d[j]){
					
					ans1++;
					//cout << j << endl;
					
				}
				
			} 
			
//			else if(a[j] < 0){
//				
//				if(v[j] > V && pmax >= d[j] && check1(1,m+1,d[j],d[j]+check(V,v[j],a[j]))!=-1){
//					
//					ans1++;	
//					//cout << check1(1,m+1,d[j],d[j]+check(V,v[j],a[j])) << endl;
//					
//				} 
//				
//			}
			
		}
		if(ans1==0) cout << ans1 << ' ' << m << endl;
		else cout << ans1 << ' ' << m-1<< endl;
		
		
	}
	
	return 0;
	
}
//1
//5 5 15 3
//0 3 0
//12 4 0
//1 1 4
//5 5 -2
//6 4 -4
//2 5 8 9 15
