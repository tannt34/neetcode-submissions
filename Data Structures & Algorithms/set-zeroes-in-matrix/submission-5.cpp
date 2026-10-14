class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool temp0row = false;
        bool temp0col = false;

        for (int i = 0; i < cols; i++) {
            if (matrix[0][i] == 0) {
                temp0row = true;
            }
        }

        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                temp0col = true;
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        //for (int i = 0; i < rows; i++) {
          //  for (int j = 0; j < cols; j++) {
            //    cout << matrix[i][j] << " ";
            //}
            //cout << endl;
        //}
       // cout << endl;
        for (int c = 1; c < cols; c++) {
            if (matrix[0][c] == 0) {
                for (int i = 0; i < rows; i++) {
                    matrix[i][c] = 0;
                }
            }
        }

       // for (int i = 0; i < rows; i++) {
         //   for (int j = 0; j < cols; j++) {
           //     cout << matrix[i][j] << " ";
            //}
            //cout << endl;
        //}
        //cout << endl;

        for (int r = 1; r < rows; r++) {
            if (matrix[r][0] == 0) {
                for (int i = 0; i < cols; i++) {
                    matrix[r][i] = 0;
                }
            }
        }

        //for (int i = 0; i < rows; i++) {
          //  for (int j = 0; j < cols; j++) {
            //    cout << matrix[i][j] << " ";
            //}
            //cout << endl;
       // }
        //cout << endl;

        if (temp0col) {
            for (int r = 0; r < rows; r++) {
                matrix[r][0] = 0;
            }
        }
        if (temp0row) {
            for (int c = 0; c < cols; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};
