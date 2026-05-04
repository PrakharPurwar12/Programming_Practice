#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isSafe(int x, int y, vector<vector<bool>>&visited,vector<vector<int>>& arr, int n){
        if((x>=0 && x<n)&& (y>=0 && y<n) && visited[x][y]!=1 && arr[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
  
    void solve(int x, int y,vector<vector<int>>& arr,int n,vector<string> &ans, 
    vector<vector<bool>>&visited, string path){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        // Down
        if(isSafe(x+1, y,visited,arr,n)){
            solve(x+1,y,arr,n,ans,visited,path+'D');
        }
        
        // Left
        if(isSafe(x, y-1,visited,arr,n)){
            solve(x,y-1,arr,n,ans,visited,path+'L');
        }
        
        // Right
        if(isSafe(x, y+1,visited,arr,n)){
            solve(x,y+1,arr,n,ans,visited,path+'R');
        }
        
        //Up
        if(isSafe(x-1, y,visited,arr,n)){
            solve(x-1,y,arr,n,ans,visited,path+'U');
        }
        visited[x][y]=0;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<string> ans;
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        string path = "";
        
        if(arr[0][0]==0){
            return ans;
        }
        
        solve(0,0,arr,n,ans,visited,path);
        return ans;
    }
};

int main() {
    Solution obj;
    
    // Example Maze Input
    // 1: Path, 0: Block
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    // Function call
    vector<string> result = obj.ratInMaze(maze);

    // Output check
    if (result.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Possible paths are:" << endl;
        for (const string& path : result) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}