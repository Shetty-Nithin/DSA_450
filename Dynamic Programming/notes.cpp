/*              Dyanmic Programming
                ___________________

1.  How to recognize DP?
->  Choice will be given
->  optimization related words such as max, min,largest, or smallest 
    will be present.
->  If in recurssion overlapping problem is presnet means in recurssion if
    2 calls are present, then we can apply DP. (DP cannot be applied for single
    call recurssion)

2.  How to recoginze the base condition?
->  Think of the smallest valid input

3.  Parent Questions
        i. 0-1 Knapsack (6)
        ii. Unbounded Knapsack (5)
        iii. Fibonacci (7)
        iV. Longest Common Subsequence (15)
        v. Longest Increasing Subsequence (10)
        vi. Kadane's Algorithm (6)
        vii. Matrix Chain Multiplication (7)
        viii. DP on Trees (4)
        ix. DP on grid (14)
        x. otheres (5)

4.  Knapsack
    types : 
        i. 0-1 knapsack : either include or exclude completely. No partial and single occurence.
        ii. Fractional : Fraction of an item can be included.
        iii. Unbounded : same item can be included multiple times
 
    Problems on 0-1 Knapsack : 
        a. Subset sum problem
        b. Equal sum partition
        c. Count of subset sum
        d. Minimum subset summ difference
        e. Number of subset in given difference
        f. Target sum

        a.         
            int incl = 0;
            if(wt[index] <= capacity){
                incl = val[index] + solve(capacity-wt[index], wt, val, index-1, dp);
            }
            int excl = solve(capacity, wt, val, index-1, dp);
            dp[index][capacity] = max(incl, excl);
            return dp[index][capacity];

        b.  
            int include = canPartitionUtil(nums, index+1, target-nums[index], dp);
            int exclude = canPartitionUtil(nums, index+1, target, dp);
            return dp[index][target] = include || exclude;

        c.  
            int include = canPartitionUtil(nums, index+1, target-nums[index], dp);
            int exclude = canPartitionUtil(nums, index+1, target, dp);
            return dp[index][target] = include + exclude;  

        d.
            Take the last row of the subset sum matrix (it has all the possible subset sum).
            Push only the possible sum from the last row of the subset sum matri to the new vector.
            Run the loop till Range/2 and find least diff by using "Range - 2*s1"
            where s1 will be present before Range/2.
        
        e.
            s1 - s2 = diff ---------(1)
            s1 + s2 = sum(arr) -----(2)
            ___________________________     ----------------------------
               2*s1 = diff + sum(arr)   =>  | s1 = (diff + sum(arr))/2 |
                                            ----------------------------

            we can find count of s1 by using c. Count of subset sum problem

        f. 
            Target sum problem is same as e. Number of subset in given difference problem


    Problems on unbounded Knapsack : 
        a. Rod Cutting
        b. Coin Change - maximum number of ways
        c. Coin Change II - minimum number of coins
        d. Maximum Ribbon Cut

        Note : In 0-1 Knapsack, once the item is visited, it will be processed i.e.,
               either it will be included or excluded. Means it will be processed and will
               never be processed again. But in case of unbounded knapsack it will be processed
               if the item is excluded and it will never be processed again & if the item
               is included, then it wont be processed and it may processed in the future.

               In 0-1 knapsack, next call will be on (n-1), but in unbounded knapsack
               again it will be called on n items. (only this is the difference).
        
        a. 
            same as 0-1 knapsack but unbounded. Can use the item multiple times.

        b. 
            Relatd to subset sum problem.
            
            if(wt[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i]]j-nums[i-1];
            }
            else dp[i][j] = dp[i-1][j];

        c. 
            for(int i=0; i<sum+1; i++){ // Initialization
                for(int j=0; j<arr.size()+1, j++){
                    if(i=0){
                        dp[0][j] = INT_MAX;
                    }
                    if(j=0){
                        dp[i][0] = 0;
                    }
                }
            }
            for(int i=2; i< ; i++){ // initialization
                for(int j=1; j<sum+1; j++){
                    if(j%arr[0] == 0){
                        dp[i][j] = j/arr[0];
                    }
                    else {
                        dp[i][j] = INT_MAX-1;
                    }
                }
            }

            if(wt[i-1] <= j){
                dp[i][j] = min(1 + dp[i][j-arr[i+1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }


5. Longest Common Subsequence
    i. Longest Common Substring
    ii. Print LCS
    iii. Shortest common supersequence
    iv. Print SCS
    v. Minimum number of insertion and deletions from A to B
    vi. Longest Repeating subsequence
    vii. Length of longest subsequence of A which is substring in B
    viii. Subsequence pattern matching
    ix. Count how many times A appear as subsequence in B
    x. Longest palindromic subsequence
    xi. Longest palindromic substring
    xii. Count of palindromic substring
    xiii. Minimum number of deletion in a string to make it a palindrome.
    xiv. Minimum number of insertion to a string to make it a palindrome.


    Problems : 
    LCSubsequence
        Note : subsequence --> can be discontinuous
               substring ---> must be continuous

        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + longestCommonSubsequenceUtil(text1, text2, i+1, j+1);
        }else{
            int i_next = longestCommonSubsequenceUtil(text1, text2, i+1, j);
            int j_next = longestCommonSubsequenceUtil(text1, text2, i, j+1);
            ans = max(i_next, j_next);
        }
        return ans;

    i.  LCSubstring
            if matching make dp[i][j] = 1 + dp[i-1][j-1]
            else save the longest ans till now and make the dp[i][j] = 0;  

    ii. Print LCSequence
              0     1
            ___________
            |    |    |
        0   |____|____| 
            |    |    |
        1   |____|____|
            

            To fill the matrix:
                if(str1[1][0] == str2[0][1]){
                    dp[1][1] = 1 + dp[0][0];
                }else{
                    dp[1][1] = max(dp[1][0], dp[0][1]);
                }

            To print the LCSequence:
                string str = "";
                
                int m = i;
                int n = j;
                while(i >= 0 && j >= 0){
                    if(str1[i-1] == str2[j-1]){
                        str.push_back(str1[i-1]);
                    }
                    else{
                        if(dp[i][j-1] > dp[i-1][j]){
                            j--;
                        }else{
                            i--;
                        }
                    }
                }
                return reverse(str);

    iii.Shortest common supersequence
        (len(str1) + len(str2)) - LCSubsequence

    iv. Print Shortest Common Supersequence
                      0     1
            ___________
            |    |    |
        0   |____|____| 
            |    |    |
        1   |____|____|
            

            To fill the matrix:
                if(str1[1][0] == str2[0][1]){
                    dp[1][1] = 1 + dp[0][0];
                }else{
                    dp[1][1] = max(dp[1][0], dp[0][1]);
                }

            To print the SCSupersequence:
                string str = "";
                
                int m = i;
                int n = j;
                while(i >= 0 && j >= 0){
                    if(str1[i-1] == str2[j-1]){
                        str.push_back(str1[i-1]);
                    }
                    else{
                        if(dp[i][j-1] > dp[i-1][j]){
                            str.push_back(str1[i-1]);
                            j--;
                        }else{
                            str.push_back(str2[j-1]);
                            i--;
                        }
                    }
                }
                while(i > 0){
                    str.push(str1[i-1]);
                    i--;
                }
                while(j > 0){
                    str.push(str2[j-1]);
                    j--;
                }
                return reverse(str);

        

    v.  Minimum number of insertion and deletions from A to B
        Convert A to LCSubsequence ---> will get number of deletion
        Convert LCSubsequence to B =--> will get number fo insertion.

----------------------------------
    Pattern Matching Algorithm to apply LCSubsequence:
        i/p    question     o/p
----------------------------------

    viii. Subsequence pattern matching
        str1 == str2
        first row = first col = 0;
        
        if(str1[i-1] == str2[j-1] && i != j){ // with restriction (i != j)
            dp[i][j] = 1 + dp[i-1][j-1];
        }
        else{
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }


    Palindromes
    x.  Longest palindromic subsequence
        A   -----> A
        B  ------> reverse(A)
        Longest Palindromic Subsequence is the LCSubsequence of A & B. 
        
    xiii. Minimum number of deletion in a string to make it a palindrome.
        Find Longest Palindromic Subsequence(LPS) of a given string str.
        return len(str)-LPSubsequence  

    xiv.     
        Number of Insertion = Number of Deletion

6.  Matrix Chain Multiplication
    i. MCM
    ii. Printing MCM
    iii. Evaluate expression to true (or boolean parenthesis)
    iv. Min/Max value of an expression
    v. Palindrome partitioning
    vi. Scramble string
    vii. Egg dropping problem

    format: 
        ex: 10, 20, 30, 40, 50, 60, 70
             i           k           j
            i = near to left most index
            j = near to right most index

        if(i>j) return 0;

        int ans = 0;
        int temp = 0;
        for(int k=i; k<j; k++){
            temp = solve(arr, i, k) + solve(arr, i+1, j);
            ans = function(temp);
        }
        return ans;

    i.  MCM
        1. Find i and j
        2. Find the base case
        3. Find the k loop scheme
        4. Find ans from temp ans

        // recurssion
        if(i >= j) return 0;

        int temp = 0;
        int mini = INT_MAX;
        for(int k=i; k<=j-1; k++){ // or for(int k=i+1; k<=j; k++)
            int left = solve(arr, i, k);
            int right = solve(arr, k+1, j);
            int mulCost = arr[i-1] * arr[k] * arr[j]

            temp = left * right * mullCost; 
            mini = min(mini, temp);
        }
        return mini;

        //memoization
        vector<vector<int>> dp[i+1][j+1]; or 
        int static t[1001][1001]; // global decalration

        int solve(arr[], int i, int j, dp){
            if(i >= j) return 0;
            if(dp[i][j] != -1) return dp[i][j];

            int temp = 0;
            int mini = INT_MAX;
            for(int k=i; k<=j-1; k++){ // or for(int k=i+1; k<=j; k++)
                int left = solve(arr, i, k);
                int right = solve(arr, k+1, j);
                int mulCost = arr[i-1] * arr[k] * arr[j]

                temp = left * right * mullCost; 
                mini = min(mini, temp);
            }
            return dp[i][j] = mini;
        }

        int main(){
            memset(dp, -1, sizeOf(dp));
            solve(arr, 1, sizeOf(arr)-1)
        }

    iii. Evaluate expression to true (boolean parenthesis)

        int solve(s, i, j, isTrue){
            if(i > j) return false;
            if(i == j){
                if(isTrue == True) return s[i] == 'T'; 
                else s[i] == 'F';
            }

            int ways = 0;
            for(int k=i+1; k<=j-1; k+2){
                int leftTrue = solve(s, i, k-1, T);
                int rightTrue = solve(s, i, k-1, F);
                int leftFalse = solve(s, k+1, j, T);
                int rightFalse = solve(s, k+1, j, F);

                if(s[k] == '&){
                    if(isTrue == true){
                        ways = ways + leftTrue*rightTrue
                    }
                    else{
                        ways = ways + leftFalse*rightTrue + leftFalse*rightFalse + leftTrue*rightFalse;
                    }
                }
                else if(s[k] == '|'){
                    if(isTrue == True){
                        ways = ways + leftTrue*rightTrue + leftTrue*rightFalse + leftFalse*rightTrue;
                    }
                    else{
                        ways = ways + leftFalse*rightFalse;
                    }
                }
                else if(s[k] == '^'){
                    if(isTrue == True){
                        ways = ways + leftFalse*rightTrue + leftTrue*rightFalse;
                    }
                    else{
                        ways = ways + leftTrue*rightTrue + leftFalse*rightFalse;
                    }
                }
            }
            return ways;
        }

        //memoization/bottom-up
        unordered_map<string, int> dp //global declaration of map

        int solve(s, i, j, isTrue){
            if(i > j) return false;
            if(i == j){
                if(isTrue == True) return s[i] == 'T'; 
                else s[i] == 'F';
            }

            string temp = to.string(i);
            temp.push_back(' ');
            temp.append(to.string(j));
            temp.push_back(' ');
            temp.append(to.string(isTrue));

            if(dp.find(temp) != dp.end()){
                return mp[temp];
            }

            int ways = 0;
            for(int k=i+1; k<=j-1; k+2){
                int leftTrue = solve(s, i, k-1, T);
                int rightTrue = solve(s, i, k-1, F);
                int leftFalse = solve(s, k+1, j, T);
                int rightFalse = solve(s, k+1, j, F);

                if(s[k] == '&){
                    if(isTrue == true){
                        ways = ways + leftTrue*rightTrue
                    }
                    else{
                        ways = ways + leftFalse*rightTrue + leftFalse*rightFalse + leftTrue*rightFalse;
                    }
                }
                else if(s[k] == '|'){
                    if(isTrue == True){
                        ways = ways + leftTrue*rightTrue + leftTrue*rightFalse + leftFalse*rightTrue;
                    }
                    else{
                        ways = ways + leftFalse*rightFalse;
                    }
                }
                else if(s[k] == '^'){
                    if(isTrue == True){
                        ways = ways + leftFalse*rightTrue + leftTrue*rightFalse;
                    }
                    else{
                        ways = ways + leftTrue*rightTrue + leftFalse*rightFalse;
                    }
                }
            }
            return dp[temp] = ways;
        }

        int main(){
            dp.clear();
            solve(s, i, j, true);
        }

    v.  Palindrome partitioning
        // recurssion
        bool isPalindrome(){
            return true/false
        }
        int solve(){
            if(i >= j) return 0;
            if(isPalindrome(s, i, j)) return 0;

            int ans = INT_MAX; 
            for(int k=i; k<=j-1; k++){
                int temp = 1 + solve(s, i, k) + solve(s, k+1, j);
                ans = min(ans, temp);
            }

            return ans;
        }


    vi. Scramble string
        bool condition_1(){
            if(solve(a.substring(0, i), b.substring(n-i, i)) && 
               solve(a.substring(i, n-i), b.substring(0, n-i))){
                return true;
            }
            else return false;
        }
        bool condition_2(){
            if(solve(a.substring(0, i), b.substring(0, i)) && 
               solve(a.substring(i, n-i), b.substring(i, n-i))){
                return true;
            }
            else return false;
        }

        bool solve(string a, string b){
            if(a.compare(b) = 0) return true;
            if(a.length() <= 1) return false;

            int n = a.length();
            bool flag = false; // means a and b are not scrambled for now.

            for(int i=1; i<=n-1; i++){
                if(condition_1() || condition_2()){
                    flag = true;
                    break;
                }
            }

            return flag;
        }

        int main(){
            string a;
            string b;

            if(a.length() != b.length()) return false;
            if(a.empty() && b.empty()) return true;

            return solve(a, b);
        }
        
        
    vii. Egg dropping problem

        int solve(int e, int f){
            if(e == 1) return f;
            if(f == 0 || f == 1) return f;

            int attempt = INT_MAX;
            for(int k=0; k<f; k++){
                int temp = 1 + max(solve(e-1, k-1), solve(e, f-k));
                attempt = min(attempt, temp);
            }

            returm attempt;
        }

7. DP on Trees
    i. General Syntax
    ii. How dp can be applied to trees(Identification)
    iii. Diameter of a Binary Tree
    iv. Maximum path sum from any node any other node
    v. Maximum path sum from leaf to leaf
    vi. Diameter of N-array Tree.


    i. General Syntax
        int function(){
            1. base condition
            2. hypothesis
            3. induction
        }
        

        int solve(Node* root, int& res){
            if(root == nullptr){ // base condition
                return 0;
            }

            int left = solve(root->left, res); // hypothesis
            int right = solve(root->right, res);

            int temp = 1 + max(left, right);
            int ans = max(temp, relation);
            res = max(res, ans);

            return temp;   
        }

        int main(){
            int res = INT_MIN;
            return solve(root, res);
        }


    iii. Diameter of a Binary Tree
        int solve(Node* root, int& res){
            if(root == nullptr){
                return 0;
            }

            int left = solve(root->left, res);
            int right = solve(root->right, res);

            int temp = 1 + max(left, right);
            int ans = max(temp, 1+left+right);
            res = max(res, ans);
            return res;
        }

        int main(){
            int res = INT_MIN;
            return solve(root, res);
        }


    iv. Maximum path sum from any node any other node
        int solve(Node* root, int& res){
            if(root == nullptr){
                return 0;
            }

            int left = solve(root->left, res);
            int right = solve(root->right, res);

            int temp = max(max(left, right)+root->value, root->value);
            int ans = max(temp, left+right+root->value);
            res = max(res, ans);
            return res;
        }

        int main(){
            int res = INT_MIN;
            return solve(root, res);
        }


    v. Maximum path sum from leaf to leaf
        int solve(Node* root, int& res){
            if(root == nullptr){
                return 0;
            }

            int left = solve(root->left, res);
            int right = solve(root->right, res);

            int temp = max(left, right) + root->value;
            if(root->left == nullptr && root->right == nullptr){
                temp = max(temp, root->value); // redundant
            }

            int ans = max(temp, left+right+root->value);
            res = max(res, ans);
            return res;
        }

        int main(){
            int res = INT_MIN;
            return solve(root, res);
        }

*/