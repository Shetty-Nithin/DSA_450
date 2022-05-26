/*
You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to 
find the longest common prefix among all these strings. If there is no 
common prefix, you have to return an empty string.
A prefix of a string can be defined as a substring obtained after 
removing some or all characters from the end of the string.

Link : https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383

Example 1:
    input:
    4
    coding codezen codingninja coder

    output:
    cod

Example 2:
    input:
    3
    night ninja nil 

    output:
    ni


Constraints:
    1 <= T <= 10
    1 <= N <= 3000
    1 <= |ARR[i]| <=1000

    Each string consists of only lowercase letters.
    Time limit: 1 sec
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// approach 1: using loops
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for(int i=0; i<arr[0].length(); i++){
        char ch = arr[0][i];
        
        bool match = true;
        for(int j=1; j<n; j++){
            if(arr[j].size() < i || ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(match == false){
            break;
        }else{
            ans.push_back(ch);
        }    
    }
    return ans;
}



// approach 2: Using Trie
class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
  public:
    TrieNode* root;
    Trie (char ch){
        root = new TrieNode(ch);
    }
    
    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a'; // word is in UPPERCASE
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }
    
    void lcp(string str, string &ans){
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            
            if(root->isTerminal == true || root->childCount > 1){
                break;
            }else{
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];            
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* T = new Trie('\0');
    
    for(int i=0; i<n; i++){
        T->insertWord(arr[i]);
    }
    
    string first = arr[0];
    string ans = "";
    
    T->lcp(first, ans);
    
    return ans;
}