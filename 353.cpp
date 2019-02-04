class SnakeGame {
    vector<vector<int>> grid_;//0 is empty, 1 is food, 2 is snake
    vector<pair<int,int>> food_;
    int food_position = 0;
    queue<pair<int,int>> snake_;
    int m , n;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        grid_.resize(height);
        m = height;
        n = width;
        for (int i = 0; i < m; ++i) {
            grid_[i].resize(n);
        }
        food_ = food;
        grid_[0][0] = 2;
        snake_.push(make_pair(0,0));
        if (food_position < food_.size()) {
            grid_[food_[food_position].first][food_[food_position].second] = 1;    
        }
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int,int> d;
        if (direction == "U") {
            d = make_pair(-1,0);
        } else if (direction == "L") {
            d = make_pair(0,-1);
        } else if (direction == "R") {
            d = make_pair(0, 1);
        } else if (direction == "D") {
            d = make_pair(1, 0);
        }
        pair<int,int> h = snake_.back();
        h.first += d.first;
        h.second += d.second;
        if (h.first < 0 || h.second < 0 || h.first >= m || h.second >= n || 
            (grid_[h.first][h.second] == 2 && !(h.first == snake_.front().first &&
                                               h.second == snake_.front().second))) {
            return -1;
        }
        if (grid_[h.first][h.second] == 1) {
            grid_[h.first][h.second] = 2;
            snake_.push(h);
            food_position++;
            if (food_position < food_.size() && food_[food_position].first < m && 
               food_[food_position].second < n) {
                grid_[food_[food_position].first][food_[food_position].second] = 1;            
            }
        } else {
            grid_[snake_.front().first][snake_.front().second] = 0;
            snake_.pop();
            snake_.push(h);
            grid_[h.first][h.second] = 2;
        }

        return snake_.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
