/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
    //use map to record grid for the robot, start point as (0,0)
    set<pair<int,int>> grid;//grid[i][j] = 1 is accessible and cleaned, = 0 is block, undefined is not visited    
    int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0, -1}};
    struct Node {
        int row, col;
        int direction;//direction where it comes from
        //Node() {}
        Node(int _row, int _col, int _direction) {
            row = _row;
            col = _col;
            direction = _direction;
        }
    };
public:
    void cleanRoom(Robot& robot) {
        //dfs to solve the problem
        grid.insert(make_pair(0,0));
        stack<Node> stk;
        stk.push(Node(0,0,0));
        robot.clean();
        int direction = 0;//0 is up direction
        while (!stk.empty()) {
            Node u = stk.top();
            //move in 4 directions
            bool moved = false;
            for (int d = 0; d < 4; d++) {
                //try to move
                Node v = u;
                v.row += directions[direction][0];
                v.col += directions[direction][1];
                v.direction = direction;
                if (grid.count(make_pair(v.row, v.col)) == 0) {//not visited
                    if (robot.move()) {
                        robot.clean();
                        stk.push(v);
                        grid.insert(make_pair(v.row, v.col));
                        moved = true;
                        break;        
                    } else {
                        robot.turnRight();
                    }
                } else {
                    robot.turnRight();
                }
                direction = (direction + 1) % 4;
            }
            if (!moved) {
                stk.pop();
                //robot need to move back to u's previous node
                //from direction to (u.direction + 2) % 4
                while (direction != (u.direction + 2) % 4) {
                    direction = (direction + 1) % 4;
                    robot.turnRight();
                }
                robot.move();
                robot.turnRight();
                direction = (direction + 1) % 4;
                robot.turnRight();
                direction = (direction + 1) % 4;
            }
        }
    }
};
