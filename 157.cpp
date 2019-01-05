// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int index = 0;
        char buf4[4];
        while (index < n) {
            int num = read4(buf4);
            if (num == 0) {
                return index;
            }
            for (int i = 0; i < num && index < n; ++i) {
                buf[index++] = buf4[i];
            }
        }
        return n;
    }
};
