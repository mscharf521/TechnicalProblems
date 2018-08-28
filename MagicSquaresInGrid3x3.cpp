class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3) {return 0;}
        if (grid[0].size() < 3) {return 0;}
        
        int returnval = 0;
        bool is_magic = false;
        for (int i = 0; i < grid.size() - 2;i++) {
            for (int j = 0;j < grid[0].size() - 2;j++) { // new 3x3
                
                is_magic = true;
                int sum = 0;
                int target = -999;
                for (int k = 0;k<3;k++) { //rows
                    for (int l = 0;l<3;l++) {sum += grid[k+i][l+j];}
                    //cout << "1. " <<sum << " for " << i << ", "<< j << endl;
                    if (target == -999) {target = sum;}
                    if (sum != target) { is_magic = false; }
                    sum = 0;
                }
                for (int k = 0;k<3;k++) { //cols
                    for (int l = 0;l<3;l++) {sum += grid[l+i][k+j];}
                    //cout << "2. " <<sum << " for " << i << ", "<< j << endl;
                    if (sum != target) { is_magic = false; }
                    sum = 0;
                }
                for (int k = 0;k<3;k++) {//diag downleft
                    sum += grid[i+k][j+k];
                    
                }
                //cout << "3. " <<sum << " for " << i << ", "<< j << endl;
                if (sum != target) { is_magic = false; }
                sum = 0;
                
                for (int k = 0;k<3;k++) {//diag upright
                    sum += grid[i+2-k][j+k];
                    
                }
                //cout << "4. " <<sum << " for " << i << ", "<< j << endl;
                if (sum != target) { is_magic = false; }
                sum = 0;
                
                if (is_magic) {
                    returnval++;
                }
            }
            
        }
        return returnval;
    }
};