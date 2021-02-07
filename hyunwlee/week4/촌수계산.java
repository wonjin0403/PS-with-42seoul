import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main
{
    public static ArrayList<Integer>[] arr;
    public static boolean[] check;
    static int answer = -1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int from = Integer.parseInt(st.nextToken());
        int to = Integer.parseInt(st.nextToken());
        int cnt = Integer.parseInt(br.readLine());

        arr = new ArrayList[n + 1];
        check = new boolean[n + 1];
        for (int i = 0 ; i < arr.length; i++)
            arr[i] = new ArrayList<>();

        while (cnt-- > 0)
        {
            st = new StringTokenizer(br.readLine());
            int parent = Integer.parseInt(st.nextToken());
            int child = Integer.parseInt(st.nextToken());
            arr[parent].add(child);
            arr[child].add(parent);
        }

//        int idx = 0;
//        for (ArrayList<Integer> a : arr)
//        {
//            System.out.print(idx++ +": ");
//            for(Integer i : a)
//            {
//                System.out.print(i + " ");
//            }
//            System.out.println();
//        }

//        System.out.println(bfs(from, to)); // dfs가 더 편할 것 같다.
        dfs(from, to, 0);
        System.out.println(answer);
    }

    public static int bfs(int from, int to)
    {
        Queue<Integer> q = new LinkedList<>();
        q.offer(from);
        check[from] = true;

        int answer = 0;
        while (!q.isEmpty())
        {
            answer++;
            int temp = q.poll();
            for (Integer i : arr[temp])
            {
                if (!check[i])
                {
                    if (i == to)
                        return (answer);
                    q.offer(i);
                    check[i] = true;
                }
            }
        }
        return (-1);
    }

    public static void dfs(int from, int to, int cnt)
    {
        check[from] = true;
        for (Integer i : arr[from])
        {
            if (!check[i])
            {
                if (i == to)
                {
                    answer = cnt + 1;
                    return ;
                }
                dfs(i, to, cnt + 1);
            }
        }
    }
}
