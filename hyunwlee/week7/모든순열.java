import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 모든순열 
{
    public static void main(String[] args) throws IOException 
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = i + 1;
        }
        do
        {
            for (int i : arr)
                System.out.print(i + " ");
            System.out.println();
        }
        while (next_permutation(arr));
    }
    public static boolean next_permutation(int[] arr)
    {
        int i = arr.length - 1;
        int j = arr.length - 1;
        int temp = 0;

        while (i > 0 && arr[i - 1] >= arr[i])
            i--;
        if (i == 0)
            return (false);
        while (arr[j] <= arr[i - 1])
            j--;

        temp = arr[i - 1];
        arr[i - 1] = arr[j];
        arr[j] = temp;

        j = arr.length - 1;
        while (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        return (true);
    }
}
