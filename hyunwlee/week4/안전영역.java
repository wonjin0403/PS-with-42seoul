import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair {
    private int x;
    private int y;

    public Pair()
    {}

    public Pair(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public int getX()
    {
        return this.x;
    }

    public int getY()
    {
        return this.y;
    }
}

public class Main {
    public static int[][] arr;
    public static int[][] arr2;
    public static boolean[][] check;
    public static int[] dx = {0, 0, 1, -1};
    public static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());

        arr = new int[n][n];
        arr2 = new int[n][n];
        check = new boolean[n][n];
        int answer = 1; // ☔️ 비가 오지 않는 경우에는 모든 지도가 안전영역임으로 초기 값은 1로 주었다. ex) n이 0으로 주어지는 경우

        for (int i = 0; i < arr.length; i++)
        {
            st = new StringTokenizer(br.readLine());
            for (int j = 0 ; j < arr[0].length; j++)
                arr[i][j] = Integer.parseInt(st.nextToken());
        }

//        System.out.println("1. arr관한것");
//        printArr(arr);

        for (int k = 1; k <= 100; k++)
        {

            for (int i =0; i < arr2.length; i++)    // 초기화 작업
            {
                Arrays.fill(arr2[i], 0);
                Arrays.fill(check[i], false);
            }

            for (int i = 0; i < arr.length; i++)
            {
                for (int j = 0; j < arr[0].length; j++) {
                    if (arr[i][j] <= k) {
                        arr2[i][j] = -1;
                        check[i][j] = true;
                    }
                }
            }


//            System.out.println("2. arr2관한것");
//            printArr2(arr2);


            int cnt = 1;
            for (int i = 0 ; i < arr.length; i ++)
            {
                for (int j = 0 ; j < arr[0].length; j++)
                {
                    if (!check[i][j])
                    {
                        bfs(i,j,cnt);
                        cnt++;
                    }
                }
            }

            for (int i = 0 ; i < arr.length; i ++)
            {
                for(int j = 0 ; j < arr[0].length; j++)
                {
                    answer = Math.max(answer, arr2[i][j]);
                }
            }
//            System.out.println("answer: " + answer);
//
//            System.out.println("3.3.3.3.3.3.3.3");
//            printArr(arr2);
//            System.out.println("🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥");
        }

        System.out.println(answer);
    }

    public static void bfs(int x, int y, int cnt) {
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(x, y));
        arr2[x][y] = cnt;
        check[x][y] = true;

        while (!q.isEmpty())
        {
            Pair temp = q.poll();
            for (int i = 0 ; i < 4; i ++)
            {
                int nx = temp.getX() + dx[i];
                int ny = temp.getY() + dy[i];
                if ((0 <= nx && nx < arr2.length) && ((0 <= ny && ny < arr2[0].length))
                        && !check[nx][ny])
                {
                    q.offer(new Pair(nx, ny));
                    arr2[nx][ny] = cnt;
                    check[nx][ny] = true;
                }
            }
        }
    }

    public static void printArr(int[][] arr)
    {
        System.out.println("↓↓↓↓↓↓↓↓↓");
        for (int i = 0 ; i < arr.length; i ++)
        {
            for(int j = 0 ; j < arr[0].length; j++)
            {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("↑↑↑↑↑↑↑↑↑\n");
    }

    public static void printArr2(int[][] arr)
    {
        System.out.println("↓↓↓↓↓↓↓↓↓");
        for (int i = 0 ; i < arr.length; i ++)
        {
            for(int j = 0 ; j < arr[0].length; j++)
            {
                if (arr[i][j] == -1)
                {
                    System.out.print("x ");
                }
                else
                {
                    System.out.print(arr[i][j] + " ");
                }
            }
            System.out.println();
        }
        System.out.println("↑↑↑↑↑↑↑↑↑\n");
    }
}
