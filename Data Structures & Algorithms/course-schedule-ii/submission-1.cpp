class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        map<int,int> indegree;
        queue<int> availableCourses;
        vector<int> res;

        for(auto &prerequisite: prerequisites) {
            int dependency = prerequisite[1];
            int dependent = prerequisite[0];

            adj[dependency].push_back(dependent);
            indegree[dependent]++;
        }

        for(int i=0;i<numCourses;i++) {
            if(indegree.find(i) == indegree.end()) {
                availableCourses.push(i);
            }
        }


        while(availableCourses.empty() == false) {
            int curr = availableCourses.front();
            res.push_back(curr);
            availableCourses.pop();

            for(auto &course : adj[curr]) {
                indegree[course]--;
                if(indegree[course]==0) {
                    availableCourses.push(course);
                }
            }
        }

        if(res.size()!=numCourses)
        return vector<int>();

        return res;
    }
};
