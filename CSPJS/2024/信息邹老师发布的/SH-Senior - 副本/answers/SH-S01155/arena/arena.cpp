#include<bits/stdc++.h>
using namespace std;
int mread(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0'; 
		ch=getchar();
	}
	return x;
}
int main(){
	
} 
