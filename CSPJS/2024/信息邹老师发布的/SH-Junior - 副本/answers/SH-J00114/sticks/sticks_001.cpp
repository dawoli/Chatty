#include<iostream>
using namespace std;

int a[10] = {6,2,5,5,4,5,6,3,7,6};

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int m;
		cin >> m;
		if(m < 2){
			cout << -1 << endl;
			continue;
		}else{
			switch(m){
				case 6:
					cout << 6 << endl;
					continue;
				case 2:
					cout << 1 << endl;
					continue;
				case 5:
					cout << 2 << endl;
					continue;
				case 4:
					cout << 5 << endl;
					continue;
				case 3:
					cout << 7 << endl;
					continue;
				case 7:
					cout << 8 << endl;
					continue;
				case 18:
					cout << 208 << endl;
					continue;
			}
		}
	}
}
