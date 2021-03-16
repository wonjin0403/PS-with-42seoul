import java.util.ArrayList;
import java.util.Arrays;

public class 모의고사 
{
    public static void main(String[] args)
    {
        for (int i : solution(new int[]{1,3,2,4,2}))
            System.out.println(i);
    }

    public static int[] solution(int[] answers)
    {
        int[] one = {1, 2, 3, 4, 5};
        int[] two = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

        Integer[] check = new Integer[3];
        Arrays.fill(check, 0);

        for (int i = 0 ; i < answers.length; i++)
        {
            if (one[i % one.length] == answers[i])
                ++check[0];
            if (two[i % two.length] == answers[i])
                ++check[1];
            if (three[i % three.length] == answers[i])
                ++check[2];
        }

        int max;
        max = 0;

        for (Integer i : check)
            max = Math.max(i, max);

        ArrayList<Integer> arr = new ArrayList<>();

        for (int i = 0; i < check.length; i++)
            if (max == check[i])
                arr.add(i + 1);

        int[] answer = {};
        answer = new int[arr.size()];
        
        for(int i = 0; i < answer.length; i++) {
        	answer[i] = arr.get(i);
        }
        return (answer);
    }
}
