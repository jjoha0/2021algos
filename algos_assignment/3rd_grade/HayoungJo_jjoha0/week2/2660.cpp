#include <iostream>
#include <algorithm>
using namespace std;
 
#define INF 1e9 

int graph[51][51];
int N, a, b;
int score[51];

void floydWarshall() {
    for (int k = 1; k <= N; k++)            
        for (int i = 1; i <= N; i++)         
            for (int j = 1; j <= N; j++)     
                if (graph[i][j] > graph[i][k] + graph[k][j])        
                    graph[i][j] = graph[i][k] + graph[k][j];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;    
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
    while (cin >> a >> b)
    {
        if (a == -1 && b == -1)
            break;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    floydWarshall();
    
    int dist = INF;
    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        for (int j = 1; j <= N; j++) {
            tmp = max(tmp, graph[i][j]);
        }
        score[i] = tmp;
        dist = min(dist, score[i]);
    }
    
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (score[i] == dist)
            cnt++;
    }       
    cout << dist << ' ' << cnt << '\n';
    
    for (int i = 1; i <= N; i++)
    {
        if (dist == score[i])
            cout << i;
    }        
    return 0;

}
