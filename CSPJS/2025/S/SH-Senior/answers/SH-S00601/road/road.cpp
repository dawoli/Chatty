#include <stdio.h>
#include <unordered_set>
#include <vector>
#include <utility>

auto main(void) -> int {
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);

        unsigned int countOfNodes, countOfRoads, countOfExtraNodes;
        scanf("%u %u %u", &countOfNodes, &countOfRoads, &countOfExtraNodes);

        std::vector<std::pair<unsigned int, unsigned int>> graph[countOfNodes + 1];

        for (unsigned int i = 1; i <= countOfRoads; i++) {
                unsigned int u, v, w;
                scanf("%u %u %u", &u, &v, &w);
                graph[u].push_back(std::make_pair(v, w));
                graph[v].push_back(std::make_pair(u, w));
        }

        std::unordered_set<unsigned int> unallocatedNodes;

        for (unsigned int i = 2; i <= countOfNodes; i++) unallocatedNodes.insert(i);

        unsigned int addCost[countOfExtraNodes + 1];
        unsigned int roadCost[countOfExtraNodes + 1][countOfNodes + 1];

        for (unsigned int i = 1; i <= countOfExtraNodes; i++) {
                scanf("%u", &addCost[i]);
                for (unsigned int j = 1; j <= countOfNodes; j++)
                        scanf("%u", &roadCost[i][j]);
        }

        unsigned int ans = 0;


        for (unsigned int cjj = 1; cjj < countOfNodes; cjj++) {
                bool constructNewNode = false;
                unsigned int constructNewNodeId, from, to;
                unsigned int currentCost = 0x3f3f3f3f;

                for (auto currentNode: unallocatedNodes) {
                        for (auto next: graph[currentNode]) {
                                if (unallocatedNodes.find(next.first) != unallocatedNodes.end()) continue;
                                if (next.second < currentCost) {
                                        constructNewNode = false;
                                        from = currentNode;
                                        to = next.first;
                                        currentCost = next.second;
                                }
                                for (unsigned int town = 1; town <= countOfExtraNodes; town++) {
                                        unsigned int cost = addCost[town] + roadCost[town][currentNode] + roadCost[town][next.first];
                                        
                                        if (cost < currentCost) {
                                                constructNewNode = true;
                                                constructNewNodeId = town;
                                                from = currentNode;
                                                to = next.first;
                                                currentCost = cost;
                                        }
                                }
                        }
                }

                if (!constructNewNode) {
                        unallocatedNodes.erase(from);
                        ans += currentCost;
                } else {
                        unallocatedNodes.erase(from);
                        ans += currentCost;
                        addCost[constructNewNodeId] = 0;
                }
        }

        printf("%u", ans);

        return 0;
}
