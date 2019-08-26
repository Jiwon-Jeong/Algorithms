import java.io.*;
import java.util.*;
 
class MyScanner {
    BufferedReader br;
    StringTokenizer st;
 
    public MyScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
 
    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
 
    int nextInt() {
        return Integer.parseInt(next());
    }
 
    long nextLong() {
        return Long.parseLong(next());
    }
 
    double nextDouble() {
        return Double.parseDouble(next());
    }
}
 
public class BOJ1600 {
 
    public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    public static MyScanner sc = new MyScanner();
    static int[] Hx = {-2,-1,1,2,2,1,-1,-2};
    static int[] Hy = {-1,-2,-2,-1,1,2,2,1};
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,-1,0,1};
    static int K,W,H,map[][];
    static boolean[][][] visited;
    public static void main(String[] args) throws IOException {
        K = sc.nextInt();
        W = sc.nextInt();
        H = sc.nextInt();    
        map = new int[H][W];
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                map[i][j] = sc.nextInt();
            }
        }
        visited = new boolean[201][201][31];
        int ans = BFS();
        out.println(ans);
        out.flush();
    }
    private static int BFS() {
        
        Queue<Node> q = new LinkedList<Node>();
        visited[0][0][K]=true;
        q.offer(new Node(0,0,K));
        int depth=0;
        while(!q.isEmpty())
        {
            int size = q.size();
            for(int sz =0;sz<size;sz++)
            {
                Node p = q.poll();
                int x = p.x;
                int y = p.y;
                int move = p.move;
                if(x == H-1 && y == W-1){
                    return depth;
                }
                if(move>0){
                for(int h=0;h<8;h++)
                {
                    int Hx1 = x+Hx[h];
                    int Hy1 = y+Hy[h];
                    if(Hx1<0 || Hy1<0 || Hx1>=H || Hy1>=W) continue;                    
                        if(map[Hx1][Hy1]==0  && !visited[Hx1][Hy1][move-1])
                        {
                            visited[Hx1][Hy1][move-1]=true;
                            q.offer(new Node(Hx1,Hy1,move-1));
                        }
                }
                }
                for(int M =0;M<4;M++){
                    int Mx1 = x+dx[M];
                    int My1 = y+dy[M];
                    if(Mx1<0 || My1<0 || Mx1>=H || My1>=W) continue;
                    if(map[Mx1][My1]==0 && !visited[Mx1][My1][move]){
                        visited[Mx1][My1][move]=true;
                    q.offer(new Node(Mx1,My1,move));
                    }
                    }
            }
            depth++;
        }
        return -1;
    }
}

class Node{
    int x,y,move;
    Node (int x, int y , int move){
        this.x = x;
        this.y = y;
        this.move = move;
    }
}

