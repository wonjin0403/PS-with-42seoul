import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 일곱난쟁이
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[9];
        int sum = 0;
        
        for (int i = 0; i < arr.length; i++)
        {
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
        }
        Arrays.sort(arr);
        // nC7 == nC2
        // nC2 => O( n * (n - 1) / 2) == O(N^2)
        // 따라서, imposter 두명만 찾는다.
        for (int i = 0; i < arr.length - 1; i++)
        {
            for (int j = i + 1; j < arr.length; j++)
            {
                if (sum - arr[i] - arr[j] == 100)
                {
                    for (int dwaf : arr)
                    {
                        if (arr[i] == dwaf || arr[j] == dwaf)
                            continue;
                        System.out.println(dwaf);
                    }
                    return ;
                }
            }
        }
    }
}