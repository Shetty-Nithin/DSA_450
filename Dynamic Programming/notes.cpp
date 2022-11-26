/*
------------------Dyanmic Programming--------------------


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
        Find Longest Palindromic Subsequence(LPS) of a gien string str.
        return len(str)-LPSubsequence      







*/