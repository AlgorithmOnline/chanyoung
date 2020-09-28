package ETC;

import java.io.*;
import java.util.*;

public class BOJ1238 {

	static class Pair implements Comparable<Pair> {
		int node, time;
		Pair(int node, int time)
		{
			this.node = node;
			this.time = time;
		}
		@Override
		public int compareTo(Pair arg0) {
			if (this.time < arg0.time) return -1;
			else if (this.time == arg0.time) return 0;
			else return 1;
		}
	}
	
	static final int INF = 987654321;
	static int N, M, X;
	static ArrayList<Pair>[] graph;
	
	public static int[] djikstra(int node)
	{
		int[] dist = new int[N];
		Arrays.fill(dist,INF);
		
		dist[node] = 0;
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		pq.offer(new Pair(node,0));
		
		while (!pq.isEmpty())
		{
			Pair now = pq.poll();
			
			if (dist[now.node] < now.time)
				continue;
			
			for (int idx = 0; idx < graph[now.node].size(); ++idx)
			{
				int nxtNode = graph[now.node].get(idx).node;
				int nxtTime = graph[now.node].get(idx).time;
				
				if (dist[nxtNode] > now.time + nxtTime)
				{
					dist[nxtNode] = now.time + nxtTime;
					pq.offer(new Pair(nxtNode,dist[nxtNode]));
				}
			}
		}
			
		return dist;
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] info = br.readLine().split(" ");
		
		N = Integer.parseInt(info[0]);
		M = Integer.parseInt(info[1]);
		X = Integer.parseInt(info[2]);
		X--;
		
		graph = new ArrayList[N];
		for (int i = 0; i < N; ++i)
		{
			graph[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < M; ++i)
		{
			String[] edge = br.readLine().split(" ");
			int src,dst,time;
			src = Integer.parseInt(edge[0]);
			dst = Integer.parseInt(edge[1]);
			time = Integer.parseInt(edge[2]);
			
			src--; dst--;
			graph[src].add(new Pair(dst,time));
		}
		
		
		int[] dst2src = new int[N];
		dst2src = djikstra(X);
			
		int answer = -1;
		for (int i = 0; i < N; ++i)
		{
			if (i != X)
			{
				int[] dist = new int[N];
				dist = djikstra(i);
				answer = Math.max(answer, dist[X] + dst2src[i]);
			}
		}
		
		System.out.println(answer);
	}
}
