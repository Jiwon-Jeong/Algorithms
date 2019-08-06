 
import java.util.Scanner;
 
public class BOJ6603 {
    private static StringBuilder sb = new StringBuilder();
    private static int cnt;
    private static int k;
    private static int arr[];
    
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        
        while ((k = in.nextInt()) != 0) {
            arr = new int[13];
            
            for (int i = 0; i < k; i++) {
                arr[i] = in.nextInt();
            }
 
            for (int i = 0; i < k - 5 ; i++) {
                cnt = 1;
                findLottoNum(i, String.valueOf(arr[i]));
            }
            
            System.out.print(sb.append("\n").toString());
            sb = new StringBuilder();
        }
 
        in.close();
    }
 
    public static void findLottoNum(int index, String str) {
        if (6 == cnt) {
            sb.append(str + "\n");
        } else {
            for (int i = index + 1; i < k; i++) {
                cnt++;
                findLottoNum(i, str + " " + arr[i]);
            }
        }
        cnt--; 
    }
}
