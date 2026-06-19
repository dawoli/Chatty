#include <bits/stdc++.h>
using namespace std;

int n,m,raw_a[100001],a[100001],c[100001],T,X[4];
string *D;
long long sum(int full_players){
	queue<vector<int>> p;
	int round=-1, nth=0;
	vector<int> empty; 
	p.push(empty);
	for(int i=0;i<full_players;i++){
		vector<int> v;
		v.push_back(i);
		p.push(v);
	}
	cout<<"sz:"<<p.size()<<' ';
	while(p.size()>2){
		vector<int> v1 = p.front();
		p.pop();
		if(v1.empty()){
			p.push(v1);
			++round;
			nth=0;
			continue;
		}
		vector<int> v2 = p.front();
		p.pop();
		vector<int> v;
		
		bool is_right = D[round][nth++]-'0';
		if(!is_right){
			vector<int> tmp = v2;
			v2=v1;
			v1=tmp;
		}
		bool flag=false;
		cout<<'[';
		for(int i=0; i<v1.size(); ++i){
			cout<<a[v1[i]]<<' ';
			if(a[v1[i]]==-1){
				flag=true;
				v.push_back(v1[i]);
			}else if(a[v1[i]]>=round){
				v.push_back(v1[i]);
			}else{
				flag=true;
			}
		}
		cout<<flag<<"] ";
		if(flag){
			for(int i=0; i<v2.size(); ++i){
				v.push_back(v2[i]);
			}
		}
		cout<<v.size()<<' ';
		p.push(v);
	}
	p.pop();
	cout<<"| ";
	long long res=0;
	for(int i=0;i<p.front().size();++i){
		cout<<p.front()[i]+1<<' ';
		res+=p.front()[i]+1;
	}
	cout<<res<<' '<<endl;
	return res;
}
int main(){
	freopen("arena1.in","r",stdin);
//	freoepn("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>raw_a[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int tmp=ceil(log2(n));
	string d[tmp];
	for(int i=0;i<tmp;i++){
		cin>>d[i];
	}
	D=d;
	cin>>T;
	for(int _=0;_<T;++_){
		cin>>X[0]>>X[1]>>X[2]>>X[3];
		long long res=0;
		cout<<"---"<<endl;
		for(int i=0; i<m; i++){
			int players=c[i];
			int full_players=pow(2,ceil(log2(players)));
			for(int j=0;j<players;j++){
				a[i]=raw_a[i] xor X[i];
			}
			for(int j=players;j<full_players;j++){
				a[i]=-1;
			}
			res = res xor ((i+1)*sum(full_players));
		}
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

