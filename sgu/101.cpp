/*
欧拉图，欧拉路径
*/
#include <stdio.h>
#include <stdlib.h>
int head[7];
int buff[201];
int *side = &buff[100];
int buff2[201];
int *next = &buff2[100];
int len;
int count[7];
int used[101];

/*
前向星，用于节点数较多或两点之间有重边的情况
当前节点x,通过head[x]找到是第一条边在side，next数组中的索引，通过side[i]找到边的终点，通过next[i]找到x的下一条边
*/
void add(int x, int y)
{
    int i;
    i = ++len;
    side[i] = y; //1-100，对应buff101-200
    next[i] = head[x];
    head[x] = i;

    side[-i] = x; //-100--1，对应buff0-99
    next[-i] = head[y];
    head[y] = -i;

    count[x]++, count[y]++; //记录度数
}
int ans[101];
int end;

void dfs(int k)
{
    int i;
    i = head[k];
    while(i != 0){
        if(!used[abs(i)]){ //不管正负，但只能走一次
            used[abs(i)] = 1;
            dfs(side[i]); //下层都搜完后
            ans[end++] = i; //记录当前边的索引
        }
        i = next[i];
    }
}

int main(int argc, char **argv)
{
    int i;
    int a, b;
    int n, t, s;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    t = 0;
    for(i = 0; i <= 6; i++){
        if(count[i] & 1){ //判断奇偶性
            t++;
            s = i;
        }
    }
    if(t > 2){
        printf("No solution\n");
        exit(0);
    }
    if(t == 0){
        for(i = 0; i <= 6; i++){
            if(count[i] > 0){
                s = i;
                break;
            }
        }
    }
    //当t==2时，从奇数度节点出发，t==0时，从有度节点出发
    dfs(s); //仅需经过一次dfs搜索，标准做法
    for(i = 1; i <= n; i++){
        if(!used[i]){ //有边没有走到
            printf("No solution\n");
            exit(0);
        }
    }
    for(i = end - 1; i >= 0; i--){
        if(ans[i] > 0){
            printf("%d +\n", ans[i]);
        }else{
            printf("%d -\n", -ans[i]);
        }
    }
    return 0;
}