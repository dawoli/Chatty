#include<bits/stdc++.h>
using namespace std;
template<typename Tp>
pair<reference_wrapper<Tp>,reference_wrapper<Tp>> firstTwoListElement(list<Tp>& l){
	auto b=l.begin();
	auto r1=ref(*b);
	b++;
	auto r2=ref(*b);
	return pair<reference_wrapper<Tp>,reference_wrapper<Tp>>(r1,r2);
}
template<typename Tp>
void removeListFirst(list<Tp>& l){
	l.erase(l.begin());
}
template<typename Tp>
void removeListSecond(list<Tp>& l){
	auto b=l.begin();
	b++;
	l.erase(b);
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	unordered_map<int,int> data;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		data[x]++;
	}
	vector<pair<int,int>> r(data.begin(),data.end());
	sort(r.begin(),r.end());
	list<pair<int,int>> l(r.begin(),r.end());
	int b=0;
	while(l.size()>1){
		auto elem = firstTwoListElement(l);
		if(elem.first.get().second<elem.second.get().second){
			b+=elem.first.get().second;
			elem.second.get().second-=elem.first.get().second;
			removeListFirst(l);
		}else{
			b+=elem.second.get().second;
			elem.first.get().second-=elem.second.get().second;
			removeListSecond(l);
		}
	}
	printf("%d",n-b);
}
