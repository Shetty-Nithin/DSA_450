/*
Link : https://www.codingninjas.com/codestudio/problems/implement-trie_631356L
Link : https://leetcode.com/problems/implement-trie-prefix-tree/
Link : https://www.geeksforgeeks.org/trie-insert-and-search/
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    // Insert
    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A'; // word is in UPPERCASE
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    // Search
    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if( root->children[index] != NULL ){
            child = root->children[index];
        }else{
            return false;
        }

        return searchUtil(child, word.substr(1));
    }
    bool serachWord(string word){
        return searchUtil(root, word);
    }

    // Prefix
    bool prefixUtil(TrieNode* root, string prefix){
        if(prefix.length() == 0){
            return true;
        }

        int index = prefix[0] - 'a';
        TrieNode* child;

        if( root->children[index] != NULL ){
            child = root->children[index];
        }else{
            return false;
        }

        return prefixUtil(child, prefix.substr(1));
    }
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

int main(){

    Trie* t = new Trie();
    t->insertWord("NANANA");
    t->insertWord("NITHIN");
    t->insertWord("NITHINSHETTY");

    cout << "present or not = " << t->serachWord("ABCD") << endl;
    cout << "present or not = " << t->serachWord("ABCDE") << endl;


    return 0;
}