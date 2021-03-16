public class 카펫{
    
    public static void main(String[] args)
    {
        for (int i : solution(10, 2))
        {
            System.out.println(i);
        }
    }

    public static int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int sum = brown + yellow;

        for (int i = 3; i <= sum; i++)
        {
            if (sum % i == 0)
            {
                int col = sum / i;
                int row = sum / col;

                if (((col - 2) * (row - 2) == yellow) && col >= row)
                    return new int[]{col, row};
            }
        }

        return answer;
    }
}
