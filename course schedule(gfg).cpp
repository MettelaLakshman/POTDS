class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int>ans(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<m;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ans[prerequisites[i][0]]++;
        }
        queue<int>q;
        vector<int>vt;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int w=q.front();
            q.pop();
            vt.push_back(w);
            for(auto it:adj[w])
            {
                ans[it]--;
                if(ans[it]==0)q.push(it);
            }
        }
        if(vt.size()!=n)return {};
        return vt;
    }
};
