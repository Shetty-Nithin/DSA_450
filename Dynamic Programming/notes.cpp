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
        b. Coin Change
        c. Coin Change II
        d. Maximum Ribbon Cut

        Note : In 0-1 Knapsack, once the item is visited, it will be processed i.e.,
               either it will be included or excluded. Means it will be processed and will
               never be processed again. But in case of unbounded knapsack it will be processed
               if the item is excluded and it will never be processed again & if the item
               is included, then it wont be processed and it may processed in the future.

               In 0-1 knapsack, next call will be on (n-1), but in unbounded knapsack
               again it will be called on n items. (only this is the difference).
        
        a. 












*/