#include <bits/stdc++.h>
using namespace std;


struct Node
{
    bool isEnd;
    Node* arr[26];
    
    bool containsKey(char ch)
    {
        return arr[ch - 'a'] != NULL;
    }
    
    void putKey(char ch)
    {
        arr[ch - 'a'] = new Node();
    }
    
    Node* getKey(char ch)
    {
        return arr[ch - 'a'];
    }
    
    void setEnd()
    {
        isEnd = true;
    }
    
    bool tellEnd()
    {
        return isEnd;
    }
};


class Trie
{
    private:
    Node *root;
    
    public:
    Trie()
    {
        root = new Node();
    }
    
    void insert(string word)
    {
        Node *curr = root;
        int n = word.length();
        
        for(int i = 0; i < n; i++)
        {
            if(curr -> containsKey(word[i]) == false)
                curr -> putKey(word[i]);
            curr = curr -> getKey(word[i]);
        }
        
        curr -> setEnd();
    }
    
    bool search(string word)
    {
        Node *curr = root;
        int n = word.length();
        for(int i = 0; i < n; i++)
        {
            if(curr -> containsKey(word[i]) == false)
                return false;
            curr = curr -> getKey(word[i]);
        }
        
        return curr -> tellEnd();
    }
    
    bool isPrefix(string word)
    {
        Node *curr = root;
        int n = word.length();
        
        for(int i = 0; i < n; i++)
        {
            if(curr -> containsKey(word[i]) == false)
                return false;
            curr = curr -> getKey(word[i]);
        }
        
        return true;
    }
};


signed main()
{
    Trie obj1;
    obj1.insert("welcome");
    obj1.insert("hariprasad");
    
    cout << obj1.search("welcome") << endl;
    cout << obj1.search("hariprasad") << endl;
    cout << obj1.search("hari") << endl;
    cout << obj1.search("ramsai") << endl;
    
    cout << obj1.isPrefix("welco") << endl;
    cout << obj1.isPrefix("hari") << endl;
    cout << obj1.isPrefix("haris") << endl;
    
    return 0;
}
