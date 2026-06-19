#include <bits/stdc++.h>
using namespace std;

int dir[10]={6,2,5,5,4,5,6,3,7,6};
int lessThanTwenty[21]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,228,208,288,688};
/*const int N=1e5+5;
int result[N];
int count[N];
int end[N];*/

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int T;
	cin>>T;
	int maxN=0;
	for (int t=0;t<T;t++){
		int n;
		cin>>n;
		maxN=max(n,maxN);
		
		int ret=-1;
		
		if (n%7==0){
			ret=0;
			int x=n/7;
			int base=1;
			while (x>0){
				ret+=8*base;
				base*=10;
				x--;
			}
		}
		
		else if (n%7==1 && n!=1){
			int x=n/7+1;
			int base=1;
			ret=10;
			while (x>2){
				ret*=10;
				ret+=8;
				x--;
			}
		}
		
		else if (n%7==2){
			int x=n/7;
			ret=1;
			while (x>0) {
				ret*=10;
				ret+=8;
				x--;
			}
		}
		
		else if (1<=n&&n<=20){
			ret=lessThanTwenty[n];
		}
		
		cout<<ret<<endl;
	}
	
	/*for (int i=0;i<=14;i++){
		result[i]=lessThanTwenty[i];
	}
	
	for(int i=20;i<=maxN;i++){
		int count=i;
		int len=i/7+1;
		int countTemp=count;
		int lenTemp=len;
		
		if (i%7==0){
			int ret=0;
			int x=i/7;
			int base=1;
			while (x>0){
				ret+=8*base;
				base*=10;
				x--;
			}
			result[i]=ret;
			continue;
		}
		
		else{
			int temp=result[i-7];
			temp*=10;
			temp+=8;
			while(lenTemp>0){
				if ((countTemp-5) < len*7){
					
				}
			}
		}
	}*/
	
	return 0;
}
