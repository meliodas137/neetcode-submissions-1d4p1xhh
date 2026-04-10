class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);

        vector<vector<int>> adj(numCourses, vector<int>(numCourses, 0));

        for(auto &e: prerequisites) {
            adj[e[0]][e[1]] = 1;
        }   

        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0 && DFSCycle(i, adj, visited)) return false; 
        }

        return true;
    }

    bool DFSCycle(int i, vector<vector<int>>& adj, vector<int> &visited) {
        visited[i] = -1;

        for(int j = 0; j < adj[i].size(); j++) {
            if(adj[i][j] == 1 && visited[j] == -1) return true;
            if(adj[i][j] == 1 && visited[j] == 0 && DFSCycle(j, adj, visited)) {
                return true;
            }
        }

        visited[i] = 1;

        return false;
    }
};
