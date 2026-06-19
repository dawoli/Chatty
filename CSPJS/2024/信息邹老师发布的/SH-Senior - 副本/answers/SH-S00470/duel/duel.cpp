#include<bits/stdc++.h>
using namespace std;
std::ifstream fin("duel.in");
std::ofstream fout("duel.out");
const int e=1e5+5;
int n,r[e];
int main(){
	fin>>n;
	for(int i=1;i<=n;i++)fin>>r[i];
	sort(r+1,r+n+1);
	deque<int>s;
	for(int i=1;i<=n;i++){
		s.push_back(r[i]);
		if(s.back()>s.front())s.pop_front();
	}
	fout<<s.size();
	return 0;
}
