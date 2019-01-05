// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    char buf4[4];
    int pos = 0;
    int len = 0;
    int read(char *buf, int n) {
        if (n <= 0) {
            return 0;
        }
        int index = 0;
        while (index < n) {
            //try to read from buf4
            while (pos < len && index < n) {
                buf[index++] = buf4[pos++];
            }
            //pos == len or index == n
            if (index == n) {
                return n;
            }
            len = read4(buf4);
            pos = 0;
            if (len == 0) {//if no more char can be read
                return index;
            } 
            //else continue loop
        }
        return n;
    }
};
