// depth-first search and breadth-first search

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct Node {
    std::vector<int> adj_nodes;
};

class Graph {
    std::vector<Node> nodes;

public:
    Graph(int n_nodes)
        : nodes(n_nodes) {}
    
    void add_edge(int a, int b) {
        nodes[a].adj_nodes.push_back(b);
        nodes[b].adj_nodes.push_back(a);
    }
    
    void print(void) {
        std::cout << "-----EDGES-----\n";
        for (int i = 0; i < nodes.size(); i++) {
            std::cout << i << ": ";
            for (int j : nodes[i].adj_nodes)
                std::cout << j << ", ";
            std::cout << '\n';
        }     
    }

    int find_farthest(int i_node) { // DFS
        std::vector<bool> visited(nodes.size(), false);
        std::stack<std::pair<int, int>> visit_stack;

        int farthest_node = i_node;
        int max_depth = 0;

        visited[i_node] = true;
        visit_stack.push({ i_node, 0 });

        while (!visit_stack.empty()) {
            auto [i_cur, depth] = visit_stack.top();
            visit_stack.pop();

            depth++;
            for (int i : nodes[i_cur].adj_nodes) {
                if (visited[i]) 
                    continue;
                if (depth > max_depth) {
                    farthest_node = i;
                    max_depth = depth;
                }
                visited[i] = true;
                visit_stack.push({ i, depth });
            }
        }

        return farthest_node;
    }

    std::vector<int> find_distances(int i_node) { // BFS
        std::vector<int> distances(nodes.size(), -1); 
        std::vector<bool> visited(nodes.size(), false);
        std::queue<int> visit_queue;

        distances[i_node] = 0;
        visited[i_node] = true;
        visit_queue.push(i_node);

        while (!visit_queue.empty()) {
            int i_cur = visit_queue.front();
            visit_queue.pop();

            for (int i : nodes[i_cur].adj_nodes) {
                if (visited[i])
                    continue;
                distances[i] = distances[i_cur] + 1;
                visited[i] = true;
                visit_queue.push(i);
            }
        }

        return distances;
    }
};

int main(void) {
    int n_nodes, n_edges, i_start_bfs, i_start_dfs;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n_nodes;
    std::cout << "Enter the number of edges: ";
    std::cin >> n_edges;
    std::cout << "Enter the paths between nodes: \n";
    
    Graph graph(n_nodes);
    for (int i = 0; i < n_edges; i++) {
        int a, b;
        std::cin >> a >> b;
        graph.add_edge(a, b);
    }
    graph.print();

    std::cout << "Enter the starting node for BFS: ";
    std::cin >> i_start_bfs;
    std::cout << "-----FIND-DISTANCES-(BFS)-----\n";
    auto distances = graph.find_distances(i_start_bfs);
    for (int i = 0; i < distances.size(); i++)
        std::cout << i << ": " << distances[i] << '\n';

    std::cout << "Enter the starting node for DFS: ";
    std::cin >> i_start_dfs;
    std::cout << "-----FIND-FARTHEST-(DFS)-----\n";
    auto farthest = graph.find_farthest(i_start_dfs);
    std::cout << farthest << '\n';

    return 0;
}
