#include <stdio.h>

int MAP[505][505]={0}, visit[505][505];
int dp[505][505]={0};
int X[4]={1,0,-1,0}, Y[4]={0,1,0,-1};
int M,N;


int check(int x, int y)
{
    if(x==M && y==N) return 1;
    if(visit[x][y]) return dp[x][y];
    visit[x][y]=1;
    for(int i=0; i<4; i++) {
        int xx=x+X[i];
        int yy=y+Y[i];
        if(xx>0 && xx<=M && yy>0 && yy<=N) {
            if(MAP[x][y]>MAP[xx][yy]) dp[x][y]+=check(xx,yy);
        }
    }
    return dp[x][y];
}

int main()
{
    int i,j;
    scanf("%d %d", &M, &N);
    for(i=1; i<=M; i++) {
        for(j=1; j<=N; j++) {
            scanf("%d", &MAP[i][j]);
        }
    }
    printf("%d", check(1,1));
}
