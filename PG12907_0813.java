
import java.util.*;

class PG12907 {
	
	static int[] dp;
	static int MOD = 1000000007;
	
    public int solution(int n, int[] money) {
    	
    	int answer = 0;
    	
    	Arrays.sort(money);
    	dp = new int[n + 5];
    	
    	for (int m = 0; m <=n; m += money[0])
    	{
    		dp[m] = 1;
    	}
    	
    	for (int idx = 1; idx < money.length; ++idx)
    	{
    		for (int m = 0; m <= n; ++m)
    		{
    			if (m >= money[idx])
    			{
    				dp[m] += dp[m-money[idx]] % MOD; 
    			}
    		}
    	}
    	
        return dp[n];
    }
}
