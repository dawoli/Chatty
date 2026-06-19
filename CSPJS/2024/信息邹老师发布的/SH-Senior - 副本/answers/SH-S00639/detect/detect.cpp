#include<bits/stdc++.h>
using namespace std;

int t, m ,n ,l, vl;
int p[100010] = {};
int c[100010] = {};
struct{
	double d;
	int v;
	int f;
	double b;
	double e;
}ni[100010];


int main(){
	cin >> t;
	for(int j = 1; j <= t; j++){
		int ans = 0;
		cin >> n >> m >> l >> vl;
		bool flag[n + 5] = {};
     	for(int i  = 1; i<= n ;i++){
     		int x = 0, y = 0, z = 0;
    		cin >> x >> y >> z;
     	 	ni[i].d = x;
    		ni[i].v = y;
    		ni[i].f = z;
    	}
    	for(int i = 1; i<= m; i++){
    		cin >> p[i];
    	}
    	for(int i = 1; i<= n; i++){
    		double plus = 0;
    		if(ni[i].f == 0){
    			if(ni[i].v > vl){
    				flag[i] = true;
    				ni[i].b = ni[i].d - 0.5;
    				ni[i].e = l;
				}
			}else if(ni[i].f >0){
				if(ni[i].v >= vl){
					flag[i] = true;
					ni[i].b = ni[i].d;
    				ni[i].e = l;
				}else{
					double plus = 1.0 * (vl * vl - ni[i].v *ni[i].v) /2 / ni[i].f;
					if(plus > l - ni[i].d){
						continue;
					}else{
						ni[i].b = ni[i].d + plus;
				    	ni[i].e = l;
				    	flag[i] = true;
					}
			    }
			}else{
				if(ni[i].v <= vl){
					continue;
				}else{
					flag[i] = true;
					ni[i].f = 0 - ni[i].f;
					plus = 1.0 * (ni[i].v *ni[i].v - vl * vl) /2 / ni[i].f;
					ni[i].b = ni[i].d;
					ni[i].e = ni[i].d + plus;
				}
			} 
		}
		for(int i = 1; i<= n; i++){
			if(flag[i]){
				ans++;
				
			}
		}
		cout << ans << endl;		
	}
	return 0;
}
