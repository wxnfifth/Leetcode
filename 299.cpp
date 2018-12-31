class Solution {
public:
    string getHint(string secret, string guess) {
        int count_secret[10] = {0}; // how many digit in secret
        int count_guess[10] = {0};
        for (int i = 0; i < secret.length(); ++i) {
            count_secret[secret[i] - '0']++;
        }
        int cow = 0;
        for (int i = 0; i < guess.size(); ++i) {
            if (secret[i] == guess[i]) {
                cow++;
                count_secret[secret[i] - '0']--;//minus digits that already matched
            } else {
                count_guess[guess[i] - '0']++;
            }
        }
        int bull = 0;
        for (int i = 0; i < 10; ++i) {
            bull += min(count_secret[i], count_guess[i]);
        }
        return to_string(cow) + "A" + to_string(bull) + "B";
        
    }
};
