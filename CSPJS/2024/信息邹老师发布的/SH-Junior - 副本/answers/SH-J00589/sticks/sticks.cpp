#include <bits/stdc++.h>
using namespace std;
int anslst[]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888,10888888,18888888,20088888};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
    for(int aai=0;aai<t;aai++){
    	int n;
    	cin >> n;
    	if(n<=50){/*
    		if(n==1){cout << -1;
			}if(n==2){cout << 1;
			}if(n==3){cout << 7;
			}if(n==4){cout << 4;
			}if(n==5){cout << 3;
			}if(n==6){cout << 6;
			}if(n==7){cout << 8;
			}if(n==8){cout << 7;
			}if(n==9){cout << 6;
			}*/
			cout << anslst[n];
			cout << endl;
			continue;
		}
    	if(n%7==0){
    		for(int i=0;i<n/7;i++){
    			cout << 8 << endl;
			}
			continue;
		}
		if(n%7==1 && n>7){
			cout << 10;
			for(int i=0;i<(n-8)/7;i++){
				cout << 8 << endl;
			}
			continue;
		}
		int s=n/7;
		int y=n%7;

		//cout << n  << ' '<< s << ' ';
		if(y==2){cout << 18;
		}if(y==3){cout << 22;
		}if(y==4){cout << 20;
		}if(y==5){cout << 28;
		}if(y==6){cout << 68;
		}if(y==0){cout << 8;
		}if(y==1){cout << 10;
		}
		for(int i=0;i<s-1;i++){
			cout << 8;
		}
		cout << endl;
	}	
}
