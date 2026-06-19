#include <iostream>
const int maxn = 2e5 + 10;
const int maxm = 1e6 + 5;

struct Node{
	int number;
	bool color;
	// color = 0 = red
	// color = 1 = blue
};

Node color[maxn];
int n;

long long dfs(int pos, long long score, int last_r, int last_b){
	if(pos == n + 1) return score;
	
	int c = 0;
	color[pos].color = 0;
	if(color[last_r].number == color[pos].number)
		c = color[pos].number;
	long long chose_red = dfs(pos + 1, score + c, pos, last_b);
	
	c = 0;
	color[pos].color = 1;
	if(color[last_b].number == color[pos].number)
		c = color[pos].number;
	long long chose_blue = dfs(pos + 1, score + c, last_r, pos);
	
	return std::max(chose_red, chose_blue);
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	int t;
	std::cin >> t;
	
	color[0].number = 0;
	
	for(int i = 1; i <= t; i++){
		std::cin >> n;
		for(int j = 1; j <= n; j++)
			std::cin >> color[j].number;
		std::cout << dfs(1, 0, 0, 0) << std::endl;
	}
}
