/*
Given a list of contacts contact[] of length n where each contact is a 
string which exist in a phone directory and a query string s. The task 
is to implement a search query for the phone directory. Run a search 
query for each prefix p of the query string s (i.e. from  index 1 to |s|)
that prints all the distinct contacts which have the same prefix as p 
in lexicographical increasing order. Please refer the explanation part
for better understanding.
Note: If there is no match between query and contacts, print "0".

Link : https://practice.geeksforgeeks.org/problems/phone-directory4628/1
Link : https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666

Example 1:
    Input: 
    n = 3
    contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"}
    s = "geeips"

    Output:
    geeikistest geeksforgeeks geeksfortest
    geeikistest geeksforgeeks geeksfortest
    geeikistest geeksforgeeks geeksfortest
    geeikistest
    0
    0

    Explaination: By running the search query on contact list for "g" 
    we get: "geeikistest", "geeksforgeeks" and "geeksfortest".
    By running the search query on contact list for "ge" we get: 
    "geeikistest" "geeksforgeeks"and "geeksfortest".
    By running the search query on contact list for "gee" we get: 
    "geeikistest" "geeksforgeeks"and "geeksfortest".
    By running the search query on contact list for "geei" we get: 
    "geeikistest".
    No results found for "geeip", so print "0". 
    No results found for "geeips", so print "0".


Constraints:
    1 ≤ n ≤ 50
    1 ≤ |contact[i]| ≤ 50
    1 ≤ |s| ≤ 6 

    Expected Time Complexity: O(|s| * n * max|contact[i]|)
    Expected Auxiliary Space: O(n * max|contact[i]|)
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

        int index = word[0] - 'a'; // word is in UPPERCASE
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
    
    void printSuggestion(TrieNode* curr, vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        
        for(char ch='a'; ch <= 'z'; ch++){
           TrieNode* next = curr->children[ch-'a']; 
           if(next != NULL){
               prefix.push_back(ch);
               printSuggestion(next, temp, prefix);
               prefix.pop_back();
           }
        }
    }
    
    vector<vector<string>> getSuggestion(string str){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        
        for(int i=0; i<str.length(); i++){
            char lastChar = str[i];
            prefix.push_back(lastChar);
            
            TrieNode* curr = prev->children[lastChar-'a'];
            if(curr == NULL){
                break;
            }
            vector<string> temp;
            printSuggestion(curr, temp, prefix);
            
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* T = new Trie();
    
    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        T->insertWord(str);
    }
    return T->getSuggestion(queryStr);
}