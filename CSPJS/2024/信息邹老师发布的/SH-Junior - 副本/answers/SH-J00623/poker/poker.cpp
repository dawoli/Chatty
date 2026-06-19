#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int p[4+7][13+7];
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int	n,cnt=0;
	char a,b;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a>>b;
		if(a=='D') {
			if(b=='A' && p[1][1]==0) {
				p[1][1]=1;	
				cnt++;			
			} else if(b=='T' && p[1][10] == 0) {
				p[1][10] = 1;
				cnt++;
			} else if(b=='J' && p[1][11] == 0) {
				p[1][11] = 1;
				cnt++;
			} else if(b=='Q' && p[1][12] == 0) {
				p[1][12] = 1;
				cnt++;
			} else if(b=='K' && p[1][13] == 0) {
				p[1][13] = 1;
				cnt++;
			} else if('1'<='b' && b<='9' && p[1][b-'0'] == 0){
				p[1][b-'0'] = 1;
				cnt++;
			}
		} else if(a=='C') {			
			if(b=='A' && p[2][1]==0) {
				p[2][1]=1;	
				cnt++;			
			} else if(b=='T' && p[2][10] == 0) {
				p[2][10] = 1;
				cnt++;
			} else if(b=='J' && p[2][11] == 0) {
				p[2][11] = 1;
				cnt++;
			} else if(b=='Q' && p[2][12] == 0) {
				p[2][12] = 1;
				cnt++;
			} else if(b=='K' && p[2][13] == 0) {
				p[2][13] = 1;
				cnt++;
			} else if('1'<='b' && b<='9' && p[2][b-'0'] == 0){
				p[2][b-'0'] = 1;
				cnt++;
			}
		} else if(a=='H') {			
			if(b=='A' && p[3][1]==0) {
				p[3][1]=1;	
				cnt++;			
			} else if(b=='T' && p[3][10] == 0) {
				p[3][10] = 1;
				cnt++;
			} else if(b=='J' && p[3][11] == 0) {
				p[3][11] = 1;
				cnt++;
			} else if(b=='Q' && p[3][12] == 0) {
				p[3][12] = 1;
				cnt++;
			} else if(b=='K' && p[3][13] == 0) {
				p[3][13] = 1;
				cnt++;
			} else if('1'<='b' && b<='9' && p[3][b-'0'] == 0){
				p[3][b-'0'] = 1;
				cnt++;
			}
		} else if(a=='S'){			
			if(b=='A' && p[4][1]==0) {
				p[4][1]=1;	
				cnt++;			
			} else if(b=='T' && p[4][10] == 0) {
				p[4][10] = 1;
				cnt++;
			} else if(b=='J' && p[4][11] == 0) {
				p[4][11] = 1;
				cnt++;
			} else if(b=='Q' && p[4][12] == 0) {
				p[4][12] = 1;
				cnt++;
			} else if(b=='K' && p[4][13] == 0) {
				p[4][13] = 1;
				cnt++;
			} else if('0'<='b' && b<='9' && p[4][b-'0'] == 0){
				p[4][b-'0'] = 1;
				cnt++;
			}
		}
	}
	cout<<52-cnt;
	return 0;
} 
