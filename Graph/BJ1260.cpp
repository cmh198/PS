#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define TRUE 1
#define FALSE 0

void bfs(vector<int> vec[],int start,vector<int>& check)
{
    queue<int> q;
    q.push(start);
    check[start]=TRUE;  

    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        cout<<tmp<<" ";
        for(int i=0;i<vec[tmp].size();i++){

            if(check[vec[tmp][i]]==FALSE)
            {
                q.push(vec[tmp][i]);
                check[vec[tmp][i]]=TRUE;
            }
        }
    }
}

void dfs(vector<int> vec[],int start,vector<int>& check)
{
    stack<int> stk;
    stk.push(start);
    check[start]=TRUE;
    cout<<start<<" ";

    while(!stk.empty()){
        int current_node=stk.top();
        stk.pop();
        for(int i=0;i<vec[current_node].size();i++){
            int next_node=vec[current_node][i];

            if(check[next_node]==FALSE){
                cout<<next_node<<" ";
                check[next_node]=TRUE;

                stk.push(current_node);
                stk.push(next_node);
                break;
            }
        }

        
    }

    
}
int main()
{
    int N, M, S;
    cin >> N >> M>>S;
    
    vector<int> vec[N+1];
    for(int i=0;i<M;i++)
    {
        int v,w;
        cin>>v>>w;
        vec[v].push_back(w);
        vec[w].push_back(v);
    }

    for(int i=1; i<=N; i++){
		sort(vec[i].begin(), vec[i].end());
	}
    
    vector<int> is_visited_bfs(N+1,FALSE);
    vector<int> is_visited_dfs(N+1,FALSE);

    dfs(vec,S,is_visited_dfs);
    cout<<endl;
    bfs(vec,S,is_visited_bfs);

    return 0;
}