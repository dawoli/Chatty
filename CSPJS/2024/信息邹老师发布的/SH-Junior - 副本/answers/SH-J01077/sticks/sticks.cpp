#include <iostream>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while (T--){
		int n;
	    cin >> n;
	    if (n>=100 && n%7==0){
		    for (int i=1; i<=n/7; i++){
		    	cout << 8;
		    }
    	}else if (n>=100 && n%7==1){
    	    cout << 10;
    	    for (int i=1; i<=(n-8)/7; i++){
        		cout << 8;
    	    }
       	}
	}
	fclose(stdin);
	fclose(stdout);
} 
