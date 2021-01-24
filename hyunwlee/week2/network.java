import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String[] args) {
        System.out.println("answer:" + solution(3, new int[][]{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}));
    }

    public static int solution(int n, int[][] computers) {

        int answer = 0;
        ArrayList<Integer>[] arr = (ArrayList<Integer>[]) new ArrayList[n + 1];
        boolean[] check = new boolean[n + 1];

        for (int i = 0; i <= n; i++) {
            arr[i] = new ArrayList<>();
        }

		// 인접행렬을 인접리스트로 변환
        for (int i = 0; i < computers.length; i++) {
            for (int j = i; j < computers[0].length; j++) {
                if (i != j && computers[i][j] == 1) {
                    arr[i + 1].add(j + 1);
                    arr[j + 1].add(i + 1);
                }
            }
        }

		// 인접리스트 잘 나오는지 출력
        //for (ArrayList<Integer> a : arr) {
        //    for (Integer i : a) {
        //        System.out.print(i + " ");
        //    }
        //    System.out.println();
        //}

        for (int i = 1; i <= n; i++) {
            if(check[i] == false){
                bfs(i, arr, check);
                answer++;
            }
        }

        return (answer);
    }

    public static void bfs(int start, ArrayList<Integer>[] arr, boolean[] check) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        check[start] = true;
        while (!queue.isEmpty()) {
            Integer temp = queue.poll();
            for (Integer y : arr[temp]) {
                if (check[y] == false) {
                    check[y] = true;
                    queue.offer(y);
                }
            }
        }
    }
}
