#include<bits/stdc++.h>
using namespace std;

int T,n;
int MAPPED[8]={-1,-1,1,7,4,2,0,8};

int RECOMMANDED[6][2]={
{0,6},
{1,2},
{2,5},
{4,4},
{7,3},
{8,7}};

int RECOMMANDED_FIRST[6][2]={
{1,2},
{2,5},
{4,4},
{6,6},
{7,3},
{8,7}};

int dfs(int rest, int nums, stack<int>* s){
	if(rest<2){
		return -1;
	}
	if(nums==1){
		return MAPPED[rest];
	}
	if(rest==nums*7){
		for(int i=1;i<nums;i++){
			s->push(8);
		}
		return 8;
	}
	for(int i=0;i<6;i++){
		int *item = RECOMMANDED[i];
		if(rest-item[1]>(nums-1)*7){
			continue;
		}
		int x = dfs(rest-item[1], nums-1, s);
		if(x!=-1){
			s->push(x);
			return item[0];
		}
	}
	return -1;
}

int dfs_first(int rest, int nums, stack<int>* s){
	if(rest<2){
		return -1;
	}
	if(nums==1){
		if(rest==6){
			return 6;
		}
		return MAPPED[rest];
	}
	if(rest==nums*7){
		for(int i=1;i<nums;++i){
			s->push(8);
		}
		return 8;
	}
	for(int i=0;i<6;++i){
		int *item = RECOMMANDED_FIRST[i];
		if(rest-item[1]>(nums-1)*7){
			continue;
		}
		int x = dfs(rest-item[1], nums-1, s);
		if(x!=-1){
			s->push(x);
			return item[0];
		}
	}
	return -1;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	stack<int> *s = new stack<int>();
	cin>>T;
	for(int _=0;_<T;++_){
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		int x=dfs_first(n,ceil(n/7.0),s);
		if(x==-1){
			cout<<-1<<endl;
			continue;
		}
		cout<<x;
		while(!s->empty()){
			cout<<s->top();
			s->pop();
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
