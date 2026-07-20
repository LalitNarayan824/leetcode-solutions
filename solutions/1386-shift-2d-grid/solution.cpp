class Solution {
public:


    void rev(vector<vector<int>> &grid , int s ,  int e,int  c){
        while(s<e){
            swap(grid[s/c][s%c] , grid[e/c][e%c]);
            s++;
            e--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size() , c = grid[0].size() ,size=r*c;
        k = k%(r*c);

        rev(grid, size-k , size-1, c);
        rev(grid , 0 , size-k-1, c);
        rev(grid , 0 , size-1, c);

        return grid;
    }
};