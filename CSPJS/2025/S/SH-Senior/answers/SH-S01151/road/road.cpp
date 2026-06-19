#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
std::ifstream fin ("road.in" );
std::ofstream fout("road.out");

struct road {
	int a; 
	int b; 
	int c; 	
};

bool comp(road x, road y) {return x.c < y.c;}


int n, m, k; 
int arr[10016]; 

int find(int x) {
	int n = x; 
	while (arr[x] != 0) x = arr[x]; 
	int q = x; 
	x = n; 
	while (arr[x] != 0) {
		n = arr[x]; 
		arr[x] = q; 
		x = n; 
	}
	return x; 
}

void merge(int x, int y) {
	arr[find(x)] = find(y); 
}

long long solve(std::vector<road> roads, int count) {
	std::sort(roads.begin(), roads.end(), comp); 
//	std::cout << roads.size() << '\n'; 
//	for (int i = 0; i < roads.size(); i++) {
//		std::cout << roads[i].a << ' '
//		 		  << roads[i].b << ' '
//		  		  << roads[i].c << '\n'; 
//	}
	for (int i = 0; i < n + 13; i++) {arr[i] = 0;}
	ll cost = 0; 
	int left = n - 1 + count; 
	int index = 0; 
	while (left > 0) {
//		if (index > roads.size()) 
//			std::cout << "FUCKKKKK" << roads.size(); 
		int a, b, c; 
		a = roads[index].a; 
		b = roads[index].b; 
		c = roads[index].c; 
		if (find(a) != find(b)) {
//			std::cout << "\nC " << a << ' ' << b; 
			left--; 
			cost += c; 
			merge(a, b); 
		}
		index++; 
	}
	return cost; 
}

int main() {
	fin >> n >> m >> k; 
	std::vector<road> roads; 
	for (int i = 0; i < m; i++) {
		road r; 
		fin >> r.a >> r.b >> r.c; 
		roads.push_back(r); 
	}
	int p[k]; 
	std::vector<std::vector<road>> moreroads(k); 
	for (int i = 0; i < k; i++) {
		fin >> p[i]; 
		for (int j = 0; j < n; j++) {
			int c; 
			fin >> c; 
			road r; 
			r.a = i + n + 1; 
			r.b = j + 1; 
			r.c = c; 
			moreroads[i].push_back(r); 
		}
	}
	ll best = solve(roads, 0); 
	for (int poss = 0; poss < (1 << k); poss++) {
//		std::cout << "\nK " << poss << ' '; 
		ll cost = 0; 
		std::vector<road> copy; 
		for (road r : roads) copy.push_back(r); 
		int count = 0; 
		for (int i = 0; i < k; i++) {
			if (poss & (1 << i)) continue; 
			cost += p[i]; 
			for (road r : moreroads[i]) copy.push_back(r); 
			count++; 
		}
		cost += solve(copy, count); 
//		std::cout << '\n' << cost << std::endl; 
		if (cost < best) best = cost; 
	}
	fout << best; 
}
