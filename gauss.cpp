#include<cstdio>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<iostream>
using namespace std;

const int N = 110;
const double eps = 1e-6;

double a[N][N];
int n;

//debug
void out()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n + 1; j++)
            printf("%5.2lf ", a[i][j]);

        printf("\n");
    }

    printf("\n\n");
}

int gauss()
{
    /****************************************************************************************************
    具体实现：
    1.枚举列，找到每列最大的绝对值，将其置换到当前未固定的最小行，然后将最小行之下的所有该列元素全部换为0
    2.如果有唯一解，那么再按照从最高行的位置将每一个解求解出来。
    ****************************************************************************************************/

    int r, c; //r为行，c为列
    for(c = 1, r = 1; c <= n; c++){
        int t = r; //初始化每次未固定的最小行为r
        for(int i = r + 1; i <= n; i++)
            if(fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        //如果这一列都为0，那么根据矩阵变换就无需进行这次的之后的操作了    
        if(fabs(a[t][c]) < eps) continue;

        //如果最小行不是初始化的值
        if(t != r){
            for(int j = 1; j <= n + 1; j++) swap(a[t][j], a[r][j]);
        }
        //交换后将其变为1
        for(int j = n + 1; j >= c; j--) a[r][j] /= a[r][c];

        //把最小行之下的所有该列元素都置为0，同时置为0的列元素所在行的元素也要改变
        for(int i = r + 1; i <= n; i++){
            if(fabs(a[i][c]) > eps)
                for(int j = n + 1; j >= c; j--)
                    a[i][j] = a[i][j] - a[i][c] * a[r][j];
        }
        r++;
    }

    if(r < n + 1){
        //由于r < n，所以可知至少有一个解是0x=0，故右边必须是0，否则就是无解
        for(int i = r; i <= n; i++) 
            if(fabs(a[i][n + 1]) > eps)
                return 2;
        return 1;
    }

    //当是唯一解时，我们需要将每个解都求解出来，因此我们需要从最后一个解开始，逐个借助已求出的解来解出其他的解

    //由于最后一个解本就确定了，故我们从倒数第二个开始解
    for(int i = n - 1; i >= 1; i--){
        //每次是从该元素的后一个元素开始解
        for(int j = i + 1; j <= n; j++)
            a[i][n + 1] = a[i][n + 1] - a[i][j] * a[j][n + 1];
    }

    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
		    freopen("IO\\in.txt","r",stdin);
		    freopen("IO\\out.txt","w",stdout);
            clock_t start, end;
            start = clock();
    #endif
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n + 1; j++)
            scanf("%lf", &a[i][j]);
    
    int t = gauss();

    //0代表唯一解，1代表无穷多组解，2代表无解
    if(t == 0){
        for(int i = 1; i <= n; i++) printf("%.2lf\n", a[i][n + 1]);
    }
    else if(t == 1) puts("Infinite group solutions");
    else puts("No solution");

    #ifndef ONLINE_JUDGE
        end = clock();
        cout << endl << "Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    #endif
}
