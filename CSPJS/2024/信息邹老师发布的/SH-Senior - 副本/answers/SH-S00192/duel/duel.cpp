#include<bits/stdc++.h>
using namespace std;
struct m{
	int s;
	bool is;
};
bool c(m x,m y){
	return x.s<y.s;
}
int duel(vector<m>& v,int n){
	sort(v.begin(),v.end(),c);
	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++){
			if(v.at(i).s<v.at(j).s && !v.at(j).is){
				n--;
				v.at(j).is=1;
				break;
			}
		}
	}
	return n;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("deul.out","w",stdout);
	int n=0;
	cin>>n;
	vector<m> v(n);
	for(int i=0;i<n;i++)
		cin>>v.at(i).s;
	cout<<duel(v,n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
