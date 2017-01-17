//easy problem, still made one stupid mistakes
class Logger {
private:
    unordered_map<string,int> message_timestamp;
    
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (message_timestamp.find(message) == message_timestamp.end() || timestamp - message_timestamp[message] >= 10) {
            message_timestamp[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */