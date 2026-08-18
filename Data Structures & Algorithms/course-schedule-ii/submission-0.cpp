class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        
        // Adjacency list
        vector<vector<int>> adj(n);

        // Resutant vector
        vector<int> res;

        // Map of courses with dependency and number (indegree)
        map<int,int> map;

        // Queue with all the courses without a pre-requisite
        queue<int> queue; 

        for(int i=0;i<prerequisites.size();i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            map[prerequisites[i][0]]++;
        }

        for(int i=0;i<n;i++) {
            if(map.find(i) == map.end()) {
                queue.push(i);
            }
        }

        while(queue.empty()==false) {
            int curr = queue.front();
            queue.pop();
            res.push_back(curr);

            for(int i : adj[curr]) {
                map[i]--;
                if(map[i]==0) {
                    queue.push(i);
                }
            }
        }

        if(res.size()==n)
        return res;

        return vector<int>();
        
    }
};
