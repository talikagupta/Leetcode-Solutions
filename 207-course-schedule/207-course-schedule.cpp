class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        vector<vector<int>>adj(n, vector<int>());
        vector<int> indegree(n, 0);
        for(auto p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i<indegree.size(); i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v : adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        

        for(auto n : indegree)
        {
            if(n != 0) return false; 
        }
        return true;
    }
};