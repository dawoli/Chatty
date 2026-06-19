#include<bits/stdc++.h>
using namespace std;

int n;
int a[100010] = {};
bool t[100010] = {};
bool e[100010] = {};
int k;


void attack(int x){
	if(x > n){
		return;
	}
	for(int i = 1; i<= n; i++){
		if(a[i] > a[x] && !t[i] && !e[i]){
			k--;
			t[x] = true;
			e[x] = true;
			t[i]  = true;
			break;
		}
	}
	attack(x + 1);
}





void line(){
	for(int i = 1; i<= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i] == a[j] && i == j){
				continue;
			}else if(a[i] > a[j] && i < j){
				swap(a[i],a[j]);
		    }else if(a[i] < a[j] && i > j){
		    	swap(a[i],a[j]);
			}
		}
	}
}

int main(){
    cin >> n;
    k = n;
    bool flag = true;
    for(int i = 1; i<= n; i++){
    	cin >> a[i];
    	if(a[i] != 1 && a[i] != 2){
    		flag = false;
		}
	} 
	if(flag){
		int q1 = 0, q2 = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 1){
				q1++;
			}else{
				q2++;
			}
		}
		if(q1 > q2){
			cout << n - q2;
		}else{
			cout << n - q1;
		}
	}else{
		line();
     	attack(1);
        cout<< k << endl;
	}
    return 0;
} 






























