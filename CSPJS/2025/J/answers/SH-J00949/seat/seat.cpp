#include <bits/stdc++.h>
using namespace std;
int ai[225];
int a[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","W",stdout);
	int n,m;
	cin >> n >> m;
	int bi;
	cin >> bi;
	ai[1] = bi;
	for (int i = 2;i <= n*m;i++){
		cin >> ai[i];
	}
	int sd = n*m;
	sort (ai+1,ai+sd+1);
	int pos =1;
	bool stop = 1;
	for (int i = 1;i <= m;j++){
		if (stop == 1){
			for (int i = 1;i <= n;i++){
		        a[i][j] = ai[sd-pos+1];
		        pos++;
	        }
	        
		}
		else{
			for (int i = n;i >=1;i--){
		       a[i][j] = ai[sd -pos+1];
		        pos++;
	        }
		}
		stop = !stop; 
	}
	int BI,BJ;
	for (int j = 1;j <= m;j++){
		for (int i = 1;i <= n;i++){
		    if (a[i][j] == bi){
		    	BI = i;BJ = j;
		    	break;
			}
	    }
	}
	cout << BI << " "<< BJ;
	return 0;
}
