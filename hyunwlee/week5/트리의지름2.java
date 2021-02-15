import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Edge
{
    int node;
    int cost;

    public Edge()
    {}

    public Edge(int node, int cost)
    {
        this.node = node;
        this.cost = cost;
    }
}

public class Main
{
    public static ArrayList<Edge>[] vertex;
    public static boolean[] check;
    public static int[] dist;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        vertex = new ArrayList[n + 1];
        check = new boolean[n + 1];
        dist = new int[n + 1];

        for (int i = 0 ; i < vertex.length; i++)
            vertex[i] = new ArrayList<>();

        int idx = 0;
        while (++idx < n)
        {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int val = Integer.parseInt(st.nextToken());
            vertex[from].add(new Edge(to, val));
            vertex[to].add(new Edge(from, val));
        }


        bfs(1);

        int start = 0;
        for (int i = 1; i < dist.length; i++) {
            if (dist[start] < dist[i]) {
                start = i;
            }
        }

        dist = new int[n + 1];
        check = new boolean[n + 1];
        bfs(start);

        int max = start;

        for (int i = 1; i < dist.length; i++) {
            if (dist[max] < dist[i]) {
                max = i;
            }
        }
        System.out.println(dist[max]);
    }

    public static void bfs(int start)
    {
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        check[start] = true;
        while (!q.isEmpty())
        {
            int from = q.poll();
            for (Edge to : vertex[from])
            {
                if (!check[to.node])
                {
                    q.offer(to.node);
                    dist[to.node] = dist[from] + to.cost;
                    check[to.node] = true;
                }
            }
        }
    }
}
