import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class BOJ1613 {
    
    static int n,k,s;
    static int[][] map;
    static int[] p;
    static StringBuffer sb = new StringBuffer();
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n  =Integer.parseInt(st.nextToken());
        k  =Integer.parseInt(st.nextToken());
        
        map = new int[n+1][n+1];
        
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            map[a][b] = -1;
            map[b][a] = 1;
        }
        
        for (int a = 1; a <= n; a++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if(map[i][a] == 0 || map[i][a] != map[a][j])
                        continue;
                    map[i][j] = map[i][a];
                }
            }
        }
        
        s = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < s; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            sb.append(map[a][b]+"\n");
        }
        System.out.println(sb);
    }
}