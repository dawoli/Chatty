#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int so[100010];
int flag[100010] = {0};
int main(){
	
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >>n;
	int count = n;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	for (int i = 0;i < n;i++){
		for (int j = 0;j < n;j++){
			if (a[i] > a[j] && flag[i] == 0){
				count -= 1; 
				flag[i] = 1;
				a[j] = 0x3f3f;
			}
		}
	}
	cout <<count;
	return 0;
}
 
