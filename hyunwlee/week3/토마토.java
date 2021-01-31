import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair {
    int x;
    int y;

    Pair() {
    }

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    public static Queue<Pair> q = new LinkedList<>();
    public static int[][] arr;
    //    public static boolean[][] check; 이걸로는 최소비용을 출력할 수 없다.
    public static int[][] dist;

    // 동,서,남,북
    public static int[] dx = {0, 0, -1, 1};
    public static int[] dy = {1, -1, 0, 0};

    //  0: 🥭(익지 않은 토마토)
    //  1: 🍅(익은 토마토)
    // -1: X
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        arr = new int[n][m];
        dist = new int[n][m];
//        check = new boolean[n][m];


        for (int i = 0; i < arr.length; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < arr[0].length; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                dist[i][j] = -1;
                if (arr[i][j] == 1) {
                    q.offer(new Pair(i, j));
                    dist[i][j] = 0;
//                    System.out.println("[" + i +" / " + j + "]");
                }
            }
        }
        bfs(); // 익은 토마토를 큐에 먼저 다 넣고 시작해야 동시에 출발이 가능하다.

        int answer = 0;

        for (int[] a : dist) {
            for (int i : a) {
                answer = Math.max(answer, i);
            }
        }

        // 🥭를 찾자
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                if (arr[i][j] == 0 && dist[i][j] == -1) {
                    answer = -1;
                }
            }
        }

        System.out.println(answer);
//        for (int i = 0 ; i < dist.length; i++)
//        {
//            for (int j = 0; j < dist[0].length; j++)
//            {
//                System.out.print(dist[i][j] + " ");
//            }
//            System.out.println();
//        }
    }

    public static void bfs() {
        while (!q.isEmpty())
        {
            Pair temp = q.poll();
            for (int i = 0; i < 4; i++)
            {
                int goX = temp.x + dx[i];
                int goY = temp.y + dy[i];

                if ((goX >= 0 && goX < arr.length) && (goY >= 0 && goY < arr[0].length)
                        && arr[goX][goY] == 0 && dist[goX][goY] == -1)
                {
                    q.offer(new Pair(goX, goY));
                    dist[goX][goY] = dist[temp.x][temp.y] + 1;
                }
            }
        }
    }
}
