import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BOJ1726 {
	static int M, N;
	static int[][] factory;
	static Pair start, end;
	
	// 동 서 남 북 
	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};
	
	static int result;
	static boolean[][][] visit;
	
	static class Pair{
		int x;
		int y;
		int dir;
		int cnt;
		
		Pair(int x, int y, int dir, int cnt){
			this.x = x;
			this.y = y;
			this.dir = dir;
			this.cnt = cnt;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		M = sc.nextInt();
		N = sc.nextInt();
		
		factory = new int[100][100];
		visit = new boolean[100][100][5];
		
		for(int i = 1; i <= M; i++) {
			for(int j = 1; j <= N; j++) {
				factory[i][j] = sc.nextInt();
			}
		}
		
		int startX, startY, startDir;
		startX = sc.nextInt();
		startY = sc.nextInt();
		startDir = sc.nextInt();
		start = new Pair(startX, startY, startDir, 0);
		
		int endX, endY, endDir;
		endX = sc.nextInt();
		endY = sc.nextInt();
		endDir = sc.nextInt();
		end = new Pair(endX, endY, endDir, 0);
		
		visit[startX][startY][startDir] = true; // 시작위치 방문기록 
		
		solution();
		
		sc.close();
	}
	
	
	private static  void solution() {
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(start);

		while(!q.isEmpty()) {
			Pair curPair= q.poll();
			int curDir = curPair.dir;
			int curX = curPair.x;
			int curY = curPair.y;
			int curCnt = curPair.cnt;
			
			if(curX == end.x && curY == end.y && curDir == end.dir) {
				System.out.println(curCnt);
				return;
			}
			
			// 칸 이동 
			for(int i = 1; i <= 3; i++) { 
				// 이동할 수 있는 칸수를 모두 확인하면서 큐에 넣어준다. 
				int nextX = curX + dx[curDir-1] * i;
				int nextY = curY + dy[curDir-1] * i;
				
				if(nextX > M || nextY > N || nextX <= 0 || nextY <= 0) {
					// 장외 
				}else {
					if(factory[nextX][nextY] == 0) { // 이동 가능 
						
						if(!visit[nextX][nextY][curDir]) {
							visit[nextX][nextY][curDir] = true;
							q.add(new Pair(nextX, nextY, curDir, curCnt+1));
						}
					} else { // 그 이상의 칸으로 이동 불가 
						break;
					}
				}
 			}
			
			// 회전 
			for(int i = 1; i <= 4; i++) { 
				if(curDir != i && !visit[curX][curY][i]) {
					visit[curX][curY][i] = true;
					if((curDir == 1 && i == 2 )|| (curDir == 2 && i == 1 ) || (curDir == 3 && i == 4) ||(curDir == 4 && i == 3)) {
						q.add(new Pair(curX, curY, i, curCnt+2));
					}else {
						q.add(new Pair(curX, curY, i, curCnt+1));
					}
					
					
				}
				
			}
			
		}
		
	}

}