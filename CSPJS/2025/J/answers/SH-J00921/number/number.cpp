#include<bits/stdc++.h>
using namespace std;

string a,b;
int cnt = 0;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	
	cin >> a;
	cnt = a.size();
	int sum = 0;
	
	for(int i = 0 ; i < cnt ; i++){
		if(a[i] >= 'a' && a[i] <= 'z'){
			continue;
		}
		else{
			b[sum] = a[i];
			sum++;
		}
	}
	
	for(int i = 0 ; i < cnt ; i++){
		int maxx = -1,c = 0;
		for(int j = 0 ; j < cnt ; j++){
			if(b[j] > maxx){
				maxx = b[j];
				c = j;
			}
		}
		cout << b[c];
		b[c] = -2;
	}

	return 0;
}
