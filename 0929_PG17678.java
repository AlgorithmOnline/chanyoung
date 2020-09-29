package TEST;

import java.util.*;

class Solution {
	
	public String minute2time(int time)
	{
		StringBuilder sb = new StringBuilder();
		
		int hour = time / 60;
		int minute = time % 60;
		
		if (hour < 10)
		{
			sb.append("0");
			sb.append(hour);
		}
		else
		{
			sb.append(hour);
		}
		
		sb.append(":");
		
		if (minute < 10)
		{
			sb.append("0");
			sb.append(minute);
		}
		else
		{
			sb.append(minute);
		}
		
		return sb.toString();
	}
	
	public int time2minute(String time)
	{
		String[] info = time.split(":");
		int hour = Integer.parseInt(info[0]);
		int minute = Integer.parseInt(info[1]);
		
		return 60*hour + minute;
	}
	
    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
        
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < timetable.length; ++i)
        {
        	int minute = time2minute(timetable[i]);
        	pq.offer(minute);
        }
        
        int busTime = time2minute("09:00");
        int lastTime = 0;
        
        int passengerCount = 0;
        for (int i = 0; i < n; ++i)
        {
        	passengerCount = 0;
        	
        	while (!pq.isEmpty() && passengerCount < m)
        	{
        		if (pq.peek() <= busTime)
        		{
        			lastTime = pq.poll();
        			passengerCount += 1;
        		}
        		else
        			break;
        	}
        	busTime += t;
        }
        
        busTime -= t;
        
        if (passengerCount == m)
        {
        	answer = minute2time(lastTime-1);
        }
        else
        {
        	answer = minute2time(busTime);
        }
        
        return answer;
    }
}
