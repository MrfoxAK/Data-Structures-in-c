class Solution
{
public:
     // Function to return Breadth First Traversal of given graph.
     vector<int> bfsOfGraph(int V, vector<int> adj[])
     {
          // Code here
          vector<int> ans;
          vector<bool> visited(V, false);

          queue<int> q;
          q.push(0); // pushing 0th node;
          ans.push_back(0);
          visited[0] = true;

          while (!q.empty())
          {
               int front = q.front();
               q.pop();
               for (int i = 0; i < adj[front].size(); i++)
               {
                    if (!visited[adj[front][i]])
                    {
                         ans.push_back(adj[front][i]);
                         visited[adj[front][i]] = true;
                         q.push(adj[front][i]);
                    }
               }
          }
          return ans;
     }
};