#include<bits/stdc++.h>
using namespace std;
//[208]实现 Trie (前缀树)
//Opened on 2025-11-22 16:26:57
//leetcode submit region begin(Prohibit modification and deletion)
class Trie {
private:
    int t[1000000][26];//trie
    bool w[1000000];//end of word
    int tot=0;
public:
    Trie(){
        memset(t,0,sizeof(t));
        memset(w,0,sizeof(w));
        tot=0;
    }
    
    void insert(string word) {
        int u=0;//root
        for(int i=0;i<word.length();i++)
        {
            const int a=word[i]-'a';
            if (!t[u][a])
            {
                t[u][a]=++tot;
            }
            u=t[u][a];
        }
        w[u]=true;
    }
    
    bool search(string word) {
        int u=0;
        for (int i=0;i<word.length();i++)
        {
            const int a=word[i]-'a';
            if (!t[u][a])
            {
                return false;
            }
            u=t[u][a];
        }
        return w[u];
    }
    
    bool startsWith(string prefix)
    {
        int u=0;
        for (int i=0;i<prefix.length();i++)
        {
            const int a=prefix[i]-'a';
            if (!t[u][a])
            {
                return false;
            }
            u=t[u][a];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)
