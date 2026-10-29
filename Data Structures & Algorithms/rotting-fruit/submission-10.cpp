class Solution {
public:

    bool isValid(int x, int y, int row, int column){
        if( x >= 0 && x < row && y >= 0 && y < column  ) return true;
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> coordRotten;
        int row = grid.size(), column = grid[0].size();
        // Get coord rotten fruits
        for(int i=0; i<row; i++){
            for( int j=0; j < column; j++ ){
                if( grid[i][j] == 2){
                    coordRotten.push_back({i,j});
                }
            }
        }

        // Inicialize the BFS
        vector<vector<int>> visited(row, vector<int>(column, 0));
        queue<pair<int,int>> q;

        for(auto coord : coordRotten){
            cout << coord.first << " " << coord.second << endl;
            q.push(coord);
            visited[coord.first][coord.second] = 1;
        }

        // Scan the grid using BFS
        int minutes = 0;


        while( !q.empty()){
            int size = q.size();
            int isFresh = 0;
            for( int i=0; i<size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                cout << x << " " << y << endl;
            
                // (0,1), (1,0) (-1,0), (0,-1)

                if( isValid(x, y+1, row, column) && grid[x][y+1] == 1  && !visited[x][y+1] ){
                    q.push({x,y+1});
                    visited[x][y+1] = 1;
                    isFresh = 1;
                }

                if( isValid(x+1, y, row, column) && grid[x+1][y] == 1  && !visited[x+1][y] ){
                    q.push({x+1,y});
                    visited[x+1][y] = 1;
                    isFresh = 1;
                }

                if( isValid(x, y-1, row, column) && grid[x][y-1] == 1  && !visited[x][y-1] ){
                    q.push({x,y-1});
                    visited[x][y-1] = 1;
                    isFresh = 1;
                }

                if( isValid(x-1, y, row, column) && grid[x-1][y] == 1  && !visited[x-1][y] ){
                    q.push({x-1,y});
                    visited[x-1][y] = 1;
                    isFresh = 1;
                }

            }
            
            if(isFresh) minutes++;
            cout << minutes << endl;
        }

        // Scanning unreachable fresh fruit

        for(int i=0; i<row; i++){
            for( int j=0; j < column; j++ ){
                if( grid[i][j] == 1 && !visited[i][j]){
                    return -1;
                }
            }
        }

        return minutes;
        
    }
};


