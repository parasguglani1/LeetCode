class Solution
{
    public:
        int getans(int i, vector<string> &words, vector<int> &freq, vector< int > &score)
        {
            if (i == words.size())
            {
                return 0;
            }

            int take = 0;
            int cursum = 0;
            int isPossible = true;

            vector<int> used(26, 0);
            for (int j = 0; j < words[i].size(); j++)
            {
                char ch = words[i][j];
                int c = ch - 'a';

                if (freq[c] == 0)
                {
                    isPossible = false;
                    break;
                }
                int sc = score[c];
                cursum += sc;
                used[c]++;
                freq[c]--;
            }
            if (isPossible)
            {
                take = getans(i + 1, words, freq, score);
            }
            else
            {
                cursum=0;
            }
            for (int i = 0; i < 26; i++)
            {
                freq[i] += used[i];
            }

            int nottake = getans(i + 1, words, freq, score);

            return max(nottake, take + cursum);
        }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector< int > &score)
    {
        int n = letters.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq[letters[i] - 'a']++;
        }

        int m = words.size();

        return getans(0, words, freq, score);
    }
};