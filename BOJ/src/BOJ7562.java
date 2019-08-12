import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
 

class Point{
	int x;
	int y;
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class BOJ7562{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i=0; i<t; i++) {
			int size = sc.nextInt();
			Point start = new Point(sc.nextInt(), sc.nextInt());
			Point end = new Point(sc.nextInt(), sc.nextInt());
			System.out.println(bfs(start, end, size));
		}
	}
	
	public static int bfs(Point start, Point end, int size) {
		final int[] dx = {-2, 2, -1, 1, -2, 2, -1, 1};
		final int[] dy = {-1, 1, -2, 2, 1, -1, 2, -2};
		boolean[][] visit = new boolean[size][size];
		boolean hasGoal = false;
		int cnt=0;
		
		Queue<Point> q = new LinkedList<>();
		q.offer(start);
		visit[start.x][start.y] = true;
		
		while(!q.isEmpty() && !hasGoal) {
			for(int i=0, qSize = q.size(); i<qSize; i++) {
				Point current = q.poll();
				if(current.x== end.x && current.y == end.y) {
					hasGoal = true;
					break;
				}
				for(int dif= 0; dif<dx.length; dif++) {
					int nextX = current.x + dx[dif];
					int nextY = current.y + dy[dif];
					
					if(nextX<0 || nextX>size-1 || nextY<0 || nextY>size-1)
						continue;
					if(visit[nextX][nextY]) continue;
					
					q.offer(new Point(nextX, nextY));
					visit[nextX][nextY] = true;
				}
			}
			if(hasGoal) break;
			cnt++;
		}
		return cnt;
	}
}