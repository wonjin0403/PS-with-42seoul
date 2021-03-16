import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 테트로미노 
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] arr = new int[n][m];
        
        for (int i = 0; i < arr.length; i++)
        {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < arr[0].length; j++)
                arr[i][j] = Integer.parseInt(st.nextToken());
        }

        int sum = 0;
        int temp;

        for (int i = 0; i < arr.length; i++)
        {
            for (int j = 0; j < arr[0].length; j++)
            {
                //  1.
                //  🟥🟦🟦🟦
                if (j < arr[0].length - 3) 
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
                    sum = Math.max(sum, temp);
                }

                //  2.
                //  🟥
                //  🟦
                //  🟦
                //  🟦
                if (i < arr.length - 3)
                {
                    temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
                    sum = Math.max(sum, temp);
                }

                //  3.
                //  🟥🟨
                //  🟨🟨
                if (i < arr.length - 1 && j < arr[0].length - 1) 
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
                    sum = Math.max(sum, temp);
                }

                //  4.
                //  🟥
                //  🟧
                //  🟧🟧
                if (i < arr.length - 2 && j < arr[0].length - 1) 
                {
                    temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
                    sum = Math.max(sum, temp);
                }

                //  5.
                //  🟥🟧
                //    🟧
                //    🟧
                if ((j < arr[0].length - 1) && (i < arr.length - 2)) 
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
                    sum = Math.max(sum, temp);
                }

                //  6.
                //  🟥🟧🟧
                //  🟧
                if ((j < arr[0].length - 2) && (i < arr.length - 1))
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
                    sum = Math.max(sum, temp);
                }

                //  7.
                //      🟧
                //  🟥🟧🟧
                if (i > 0 && j < arr[0].length - 2) 
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2];
                    sum = Math.max(sum, temp);
                }

                //  8.
                //    🟥
                //    🟧
                //  🟧🟧
                if ((j > 0) && (i < arr.length - 2)) 
                {
                    temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1];
                    sum = Math.max(sum, temp);
                }

                //  9.
                //  🟥🟧
                //  🟧
                //  🟧
                if ((j < arr[0].length - 1) && (i < arr.length - 2)) 
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j];
                    sum = Math.max(sum, temp);
                }


                //  10.
                //  🟥🟧🟧
                //      🟧
                if ((j < arr[0].length - 2) && (i < arr.length - 1)) 
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
                    sum = Math.max(sum, temp);
                }

                //  11.
                //  🟥
                //  🟧🟧🟧
                if ((j < arr[0].length - 2) && (i < arr.length - 1)) 
                {
                    temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
                    sum = Math.max(sum, temp);
                }

                //  12.
                //  🟥
                //  🟩🟩
                //    🟩
                if ((j < arr[0].length - 1) && (i < arr.length - 2)) 
                {
                    temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
                    sum = Math.max(sum, temp);
                }

                //  13.
                //    🟥
                //  🟩🟩
                //  🟩
                if ((j > 0) && (i < arr.length - 2)) 
                {
                    temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j - 1];
                    sum = Math.max(sum, temp);
                }

                //  14.
                //    🟩🟩
                //  🟥🟩
                if ((j < arr[0].length - 2) && (i > 0)) 
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i - 1][j + 2];
                    sum = Math.max(sum, temp);
                }

                //  15.
                //  🟥🟩
                //    🟩🟩
                if ((j < arr[0].length - 2) && (i < arr.length - 1)) 
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
                    sum = Math.max(sum, temp);
                }

                //  16.
                //  🟥🟪🟪
                //    🟪
                if ((j < arr[0].length - 2) && (i < arr.length - 1)) 
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
                    sum = Math.max(sum, temp);
                }

                //  17.
                //  🟥
                //  🟪🟪
                //  🟪
                if ((j < arr[0].length - 1) && (i < arr.length - 2)) 
                {
                    temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j];
                    sum = Math.max(sum, temp);
                }

                //  18.
                //    🟪
                //  🟥🟪🟪
                //
                if ((j < arr[0].length - 2) && (i > 0)) 
                {
                    temp = arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i][j + 2];
                    sum = Math.max(sum, temp);
                }

                //  19.
                //    🟥
                //  🟪🟪
                //    🟪
                if ((j > 0) && (i < arr.length - 2)) 
                {
                    temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j];
                    sum = Math.max(sum, temp);
                }
            }
        }
        System.out.println(sum);
    }
}
