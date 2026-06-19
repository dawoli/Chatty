#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int a[5050];

int accumulate(vector<int> v,int n){
	if(n==1){
		int answer=0;
		for(int i=0;i<v.size();i++){
			answer+=a[v[i]];
		}
		return answer;	
	}
	int answer=0;
	for(int i=0;i<v.size();i++){
		answer+=v[i];
	}
	return answer;
}

int max_element(vector<int> v,int n){
	if(n==1){
		int answer=0;
		for(int i=0;i<v.size();i++){
			answer=max(answer,a[v[i]]);
		}
		return answer;
	}else{	
		int answer=0;
		for(int i=0;i<v.size();i++){
			answer=max(answer,v[i]);
		}
		return answer;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	int answer=0;
	stack <vector<int>> s;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			s.push({i,j});
		}
	}
	while(!(s.empty())){
		vector <int> v=s.top();
		s.pop();
		
		for(int i=max_element(v,0)+1;i<n;i++){
			vector <int> sum=v;
			sum.push_back(i);
			s.push(sum);		
			if(accumulate(sum,1) > 2*max_element(sum,1)){
				answer=(answer+1)%998244353;
			}
		}
	}
	cout << answer<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
