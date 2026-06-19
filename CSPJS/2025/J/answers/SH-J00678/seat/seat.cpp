#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int list[100001] = {}, mpw, mpl, r, rank = -1;
	cin >> mpw >> mpl;
	for(int i = 0; i < mpw * mpl; i++){
		cin >> list[i];
		if(i == 0) r = list[i];
	}
	sort(list, list + mpw * mpl, comp);
	for(int i = 0; i < mpw * mpl; i++){
		if(list[i] == r){
			rank = i + 1;
			break;
		}
	}
	int row, tempdiv;
	if(rank % mpw != 0){
		cout << rank / mpw + 1;
	} else cout << rank / mpw;
	cout << " ";
	tempdiv = rank % (2 * mpw);
	if(!tempdiv) tempdiv = 2 * mpw; 
	if(tempdiv <= mpw){ 
		cout << tempdiv;
	} else cout << mpw - (tempdiv - mpw) + 1; 
	return 0;
} 
