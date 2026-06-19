#include<bits/stdc++.h>
using namespace std;

struct car {
	int sta;
	int vec;
	int add;
};

int main () {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
//	
	int t,flaga=1,flagb=1;//ÌØÅĞA¡¢B 
	cin >> t;
	while (t--) { 
		
	int num,mon,len,lim;
	cin >> num >> mon >> len >> lim;
	car arr[num];
	for (int i=0;i<num;i++) {
		cin >> arr[i].sta >> arr[i].vec >> arr[i].add;
		if (arr[i].add) flaga=0; 
		if (arr[i].add<=0) flagb=0; 
	}
	int monit[mon],northest=0;
	for (int i=0;i<mon;i++) {
		;cin >>monit[i];
		if (northest<monit[i]) northest=monit[i];
	}
	
	if (flaga) {
		int chaosu=0;
		for (int i=0;i<num;i++) {
			if (arr[i].vec>lim &&arr[i].sta<northest) chaosu++;
			
		}
		cout << chaosu << " " << lim-1;
	}
	if (flagb) {
		int chaosu=0;
		for (int i=0;i<num;i++) {
			if (arr[i].sta>northest) continue;
			double speed=sqrt(pow(arr[i].vec,2)+2*arr[i].add*(northest-arr[i].sta));
			if (speed>lim) chaosu++;
		}
		cout << chaosu <<" " << lim-1;
	}
}
	return 0;
}

