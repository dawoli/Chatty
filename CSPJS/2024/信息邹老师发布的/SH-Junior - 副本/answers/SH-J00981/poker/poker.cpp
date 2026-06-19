#include <cstdio>
#include <string>
#include <map>
using namespace std;

std::map<std::string,int> cards;
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	scanf("%d", &n);
	char temp[5];
	for (int i = 0; i < n; i++) {
		scanf("%s", temp);
		cards[temp] = 1;
	}
	printf("%d", 52-cards.size());
	return 0;
} 
