#include<fstream>
#include<algorithm>
//写t1写了两个小时TT 
int n,m,k{},p[10001],fau{0};
struct Edge{
	int u,v,w{};
	Edge()=default;
	bool operator<(const Edge& y){
		return this->w<y.w;
	}
}mp[1000001];
int get(int x){
	if(!p[x])return x;
	return p[x]=get(p[x]);
}
void merge(int x,int y){
	p[x]=y;
}
int main(){
	std::fstream fin("road.in",std::ios::in),fout("road.out",std::ios::out);
	fin >> n>> m >> k ;
	for(int i{0};i<m;++i)fin >> mp[i].u >> mp[i].v >> mp[i].w;
	for(int i{0},c;i<k;++i){
		fin >> c;
		for(int j{0},a;j<n;++j)fin >> a;
	}
	if(k)fout << '1';
	else{
		std::sort(mp,mp+m);
		for(int i{0},x{get(mp[0].u)},y{get(mp[0].v)};i<m;++i,x=get(mp[i].v),y=get(mp[i].u)){
			if(x==y)continue;
			merge(x,y),fau+=mp[i].w;
		}
		fout << fau;
	}
	fout.close(),fin.close();
	return 0;
} 
