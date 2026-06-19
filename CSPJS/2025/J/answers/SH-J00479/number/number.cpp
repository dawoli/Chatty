#include<bits/stdc++.h>
using namespace std;
ifstream fin("number.in");
ofstream fout("number.out");
int a[1000005];
int main(){
	char c;
	int n=0;
	while(fin>>c){
		if('0'<=c and c<='9'){
			a[n]=c-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;--i){
		fout<<a[i];
	}
}

