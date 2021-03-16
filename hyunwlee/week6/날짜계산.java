import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class 날짜계산{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int E = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int cntE = 0;
        int cntS = 0;
        int cntM = 0;
        int cntReal = 0;
        while (true)
        {
            if (cntE == E && cntS == S && cntM == M)
                break;
            
            if (cntE == 15)
                cntE = 1;
            else
                ++cntE;
            if (cntS == 28)
                cntS = 1;
            else
                ++cntS;
            if (cntM == 19)
                cntM = 1;
            else
                ++cntM;
            ++cntReal;
        }
        System.out.println(cntReal);
    }
}
