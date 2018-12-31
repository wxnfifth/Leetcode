https://www.jianshu.com/p/339c08570094

class NumMatrix {
    struct Node {
        Node* left_up;
        Node* left_down;
        Node* right_up;
        Node* right_down;
        int sum;
        int row_min, row_max;
        int col_min, col_max;
        Node(int _sum, int _row_min, int _row_max, int _col_min, int _col_max) {
            sum = _sum;
            row_min = _row_min;
            row_max = _row_max;
            col_min = _col_min;
            col_max = _col_max;
            left_up = left_down = right_up = right_down = nullptr;
        }
    };
    
    Node* root;
    int m, n;
    vector<vector<int>> matrix_;
    Node* buildSegTree(int row_min, int row_max, int col_min, int col_max) {
        if (row_min > row_max || col_min > col_max) {
            return nullptr;
        }
        if (row_min == row_max && col_min == col_max) {
            return new Node(matrix_[row_min][col_min], row_min, row_max, col_min, col_max);
        }
        int row_mid = (row_min + row_max) / 2;
        int col_mid = (col_min + col_max) / 2;
        Node* t = new Node(0, row_min, row_max, col_min, col_max);
        t->left_up = buildSegTree(row_min, row_mid, col_min, col_mid);
        t->left_down = buildSegTree(row_mid + 1, row_max, col_min, col_mid);
        t->right_up = buildSegTree(row_min, row_mid, col_mid + 1, col_max);
        t->right_down = buildSegTree(row_mid + 1, row_max, col_mid + 1, col_max);
        if (t->left_up != nullptr) {
            t->sum += t->left_up->sum;
        }
        if (t->left_down != nullptr) {
            t->sum += t->left_down->sum;
        }
        if (t->right_up != nullptr) {
            t->sum += t->right_up->sum;
        }
        if (t->right_down != nullptr) {
            t->sum += t->right_down->sum;
        }
        return t;
    }
    void updateSegTree(Node* t, int row, int col, int diff) {
        if (t == nullptr) {
            return;
        }
        if (t->row_min <= row && t->row_max >= row && t->col_min <= col && t->col_max >= col) {
            t->sum += diff;
            updateSegTree(t->left_up, row, col, diff);
            updateSegTree(t->left_down, row, col, diff);
            updateSegTree(t->right_up, row, col, diff);
            updateSegTree(t->right_down, row, col, diff);
        }
    }
    
    int sumSegTree(Node* t, int row1, int col1, int row2, int col2) {
        if (t == nullptr) {
            return 0;
        }
        if (t->row_min >= row1 && t->row_max <= row2 && t->col_min >= col1 && t->col_max <= col2) {
            return t->sum;
        }
        if (t->row_max < row1 || t->row_min > row2 || t->col_max < col1 || t->col_min > col2) {
            return 0;
        }
        return sumSegTree(t->left_up, row1, col1, row2, col2) + 
               sumSegTree(t->left_down, row1, col1, row2, col2) + 
               sumSegTree(t->right_up, row1, col1, row2, col2) + 
               sumSegTree(t->right_down, row1, col1, row2, col2); 
    }
    
    
public:
    NumMatrix(vector<vector<int>> matrix) {
        m = matrix.size();
        if (m == 0) {
            n = 0;
            return;
        }
        n = matrix[0].size();
        matrix_ = matrix;
        root = buildSegTree(0, m - 1, 0, n - 1);
    }
    
    void update(int row, int col, int val) {
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return;
        }
        int diff = val - matrix_[row][col];//sumSegTree(root, row, col, row, col);
        matrix_[row][col] = val;
        updateSegTree(root, row, col, diff);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumSegTree(root, row1, col1, row2, col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
