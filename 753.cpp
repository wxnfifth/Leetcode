//my solution, bfs

class Solution {
public:
    string crackSafe(int n, int k) {
        //total node k^n, each node is like 00,01,10,11, replace last digit of each node to other node
        unordered_set<string> visited;
        string node(n, '0');
        string ans;
        ans += node;
        visited.insert(node);
        for (int i = 0; i < pow(k, n); ++i) {
            string pre = ans.substr(ans.length() - (n - 1), n - 1);
            //cout << ans << "\n";
            for (int j = k - 1; j >= 0; --j) {
                string cur = pre + to_string(j);
                if (visited.count(cur) == 0) {
                    ans += to_string(j);
                    visited.insert(cur);
                    break;
                }
            }
        }
        return ans;
        
    }
};




Approach #1: Hierholzer's Algorithm [Accepted]

Intuition

We can think of this problem as the problem of finding an Euler path (a path visiting every edge exactly once) on the following graph: there are k^{n-1}k 
n−1
  nodes with each node having kk edges.

For example, when k = 4, n = 3, the nodes are '00', '01', '02', ..., '32', '33' and each node has 4 edges '0', '1', '2', '3'. A node plus edge represents a complete edge and viewing that substring in our answer.

Any connected directed graph where all nodes have equal in-degree and out-degree has an Euler circuit (an Euler path ending where it started.) Because our graph is highly connected and symmetric, we should expect intuitively that taking any path greedily in some order will probably result in an Euler path.

This intuition is called Hierholzer's algorithm: whenever there is an Euler cycle, we can construct it greedily. The algorithm goes as follows:

Starting from a vertex u, we walk through (unwalked) edges until we get stuck. Because the in-degrees and out-degrees of each node are equal, we can only get stuck at u, which forms a cycle.

Now, for any node v we had visited that has unwalked edges, we start a new cycle from v with the same procedure as above, and then merge the cycles together to form a new cycle u \rightarrow \dots \rightarrow v \rightarrow \dots \rightarrow v \rightarrow \dots \rightarrow uu→⋯→v→⋯→v→⋯→u.

Algorithm

We will modify our standard depth-first search: instead of keeping track of nodes, we keep track of (complete) edges: seen records if an edge has been visited.

Also, we'll need to visit in a sort of "post-order", recording the answer after visiting the edge. This is to prevent getting stuck. For example, with k = 2, n = 2, we have the nodes '0', '1'. If we greedily visit complete edges '00', '01', '10', we will be stuck at the node '0' prematurely. However, if we visit in post-order, we'll end up visiting '00', '01', '11', '10' correctly.

In general, during our Hierholzer walk, we will record the results of other subcycles first, before recording the main cycle we started from, just as in our first description of the algorithm. Technically, we are recording backwards, as we exit the nodes.

For example, we will walk (in the "original cycle") until we get stuck, then record the node as we exit. (Every edge walked is always marked immediately so that it can no longer be used.) Then in the penultimate node of our original cycle, we will do a Hierholzer walk and then record this node; then in the third-last node of our original cycle we will do a Hierholzer walk and then record this node, and so on.


题目：找到一个密码字符串可以以每一位作为开头测试。


1、使用DFS，找一条路可以走到底的。

2、密码字符串的长度是一定的。DFS结束条件就是看字符串长度。

3、最重要就是要知道这个目标字符串的长度是 n + k^n - 1

class Solution {
public:
    string crackSafe(int n, int k)
    {
        int sSize = n + pow(k, n) - 1;
        ret = "";
        for (int i = 0; i < n; i++)
            ret += "0";
        st.insert(ret);
        DFS(ret, n, k, sSize);
        return ret;
    }
private:
    string ret;
    set<string> st;
    
    int DFS(string s, int n, int k, int sSize) //4 2 举例
    {
        if (s.size() == sSize)  //找到了正确答案
        {
            ret = s;
            return -1;  //返回-1代表不用往下找了
        }
        
        string tmp = s.substr(s.size() - n + 1);    //截取后面的3位
        for (int i = 0; i < k; i++)
        {
            string new_s = tmp + to_string(i);
            if (st.find(new_s) == st.end())
            {
                st.insert(new_s);
                if ( DFS(s + to_string(i), n, k, sSize) == -1)  //已经找到了
                    return -1;
                st.erase(new_s);
            }
        }
        return 0;
    }

--------------------- 
作者：liqinzhe223 
来源：CSDN 
原文：https://blog.csdn.net/liqinzhe11/article/details/79064138 
版权声明：本文为博主原创文章，转载请附上博文链接！
