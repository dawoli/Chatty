#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
int n;
int r[100086],v[100086],idx;
priority_queue<int,vector<int>,greater<int> >q1;
priority_queue<int,vector<int>,greater<int> >q2;


int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		scanf("%d",&r[i]);
		q1.push(r[i]);
	} 
	int c1,c2;

	while(q1.size()){
		while(q1.size()&&q2.size()&&(q2.top()<q1.top())){
			q2.pop(),q2.push(q1.top()),q1.pop();
			n--;
		}
		if(q1.size()){
			q2.push(q1.top());
			q1.pop();
		}
	}
	printf("%d",n);
	return 0; 
} 
