package ETC;

import java.util.*;
import java.util.concurrent.LinkedBlockingDeque;
import java.io.*;

public class BOJ2164 {

	static int N;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		Queue<Integer> q = new LinkedList<>();
		
		for (int num = 1; num <= N; ++num)
		{
			q.offer(num);
		}
		
		if (N == 1) {
			System.out.println(1);
			return;
		}
		
		while (!q.isEmpty())
		{
			q.poll();
			
			if (q.size() == 1)
			{
				break;
			}
			else
			{
				int num = q.poll();
				q.offer(num);
			}
		}
		
		System.out.println(q.poll());
	}

}
