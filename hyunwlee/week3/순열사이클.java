import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static ArrayList<Integer>[] arr;
    public static boolean[] check;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0)
        {
            arr = new ArrayList[Integer.parseInt(br.readLine()) + 1]; // 9개
            check = new boolean[arr.length];
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0 ; i < arr.length; i ++)
                arr[i] = new ArrayList<>();

            for (int i = 1; i < arr.length; i++)
            {
                int temp = Integer.parseInt(st.nextToken());
                arr[i].add(temp);
            }

            for (int i = 1 ; i < arr.length; i ++)
                Collections.sort(arr[i]);


//            for (ArrayList<Integer> a : arr)
//            {
//                for (Integer i : a)
//                {
//                    System.out.print(i + " ");
//                }
//                System.out.println();
//            }

            int answer = 0;
            for (int i = 1; i < arr.length; i++)
            {
                if (!check[i]) {
                    bfs(i);
                    answer++;
                }
            }
            System.out.println(answer);
        }
    }

    public static void bfs(int start)
    {
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        check[start] = true;
        while (!q.isEmpty())
        {
            int temp = q.poll();
            for (int i : arr[temp])
            {
                if (!check[i])
                {
                    q.offer(i);
                    check[i] = true;
                }
            }
        }
    }
}
