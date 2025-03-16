#include <bits/stdc++.h>
using namespace std;

vector<int> countVisitedShops(vector<int> paths) {
    int n = paths.size();

    // Step 1: Convert paths array into an adjacency list
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        adj[i].push_back(paths[i]); // Each node points to exactly one other node
    }

    // Step 2: Initialize necessary data structures
    vector<int> visited(n, 0);  // 0: not visited, 1: visiting, 2: fully processed
    vector<int> count(n, 0);    // Result array

    // Step 3: DFS function to detect cycles and count nodes
    function<void(int, unordered_set<int>&, vector<int>&)> dfs = [&](int node, unordered_set<int>& path, vector<int>& stack) {
        if (visited[node] == 2) return; // Already processed
        if (visited[node] == 1) { // Cycle detected
            int cycle_start = find(stack.begin(), stack.end(), node) - stack.begin();
            int cycle_length = stack.size() - cycle_start;

            for (int i = cycle_start; i < stack.size(); i++) {
                count[stack[i]] = cycle_length;
                visited[stack[i]] = 2;
            }

            for (int i = 0; i < cycle_start; i++) {
                count[stack[i]] = stack.size();
                visited[stack[i]] = 2;
            }
            return;
        }

        visited[node] = 1; // Mark as visiting
        path.insert(node);
        stack.push_back(node);

        dfs(paths[node], path, stack);

        if (visited[node] != 2) {
            count[node] = count[paths[node]] + 1;
        }
        visited[node] = 2; // Mark as fully processed
        path.erase(node);
        stack.pop_back();
    };

    // Step 4: Process all nodes
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            unordered_set<int> path;
            vector<int> stack;
            dfs(i, path, stack);
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> paths(n);
    for (int i = 0; i < n; i++) {
        cin >> paths[i];
    }

    vector<int> result = countVisitedShops(paths);
    for (int x : result) {
        cout << x << endl;
    }
    cout << endl;
    return 0;
}
