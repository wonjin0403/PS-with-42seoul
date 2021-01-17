import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

class Main {

    public static void main(String[] args) {
        System.out.println(solution(new int[]{2, 3, 2, 1}, 3));
    }

    public static int solution(int[] priorities, int location) {
        int answer = 0;

        Queue<Integer> queue = new LinkedList();
        Integer[] tempArr = new Integer[priorities.length];

        int idx = 0;
        for (int i : priorities) {
            queue.offer(i);
            tempArr[idx++] = i;
        }

        Arrays.sort(tempArr, Collections.reverseOrder());

        while (!queue.isEmpty())
        {
            Integer i = queue.poll();

            if (i != tempArr[answer]) {
                queue.offer(i);
                location--;
                if (location < 0)
                    location = queue.size() - 1;
            } else {
                answer++;
                location--;
                if (location < 0)
                    break;
            }
        }
        return answer;
    }
}
