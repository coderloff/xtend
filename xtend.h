#include <bits/stdc++.h>

namespace XTend{
    class Graph{
    private:
        static int V;

        static std::vector<bool> visited;

        static std::vector<std::list<int>> adj;

    public:

        Graph(int V)
        {
            this->V = V;
            visited.resize(V);
            adj.resize(V);
        }

        static void addEdge(int v, int w){
            adj[v].push_back(w);
        }

        static void BFS(int s){
            std::vector<bool> visited;
            visited.resize(V, false);

            std::list<int> queue;

            visited[s] = true;
            queue.push_back(s);

            while (!queue.empty()) {

                s = queue.front();
                std::cout << s << " ";
                queue.pop_front();

                for (auto adjacent : adj[s]) {
                    if (!visited[adjacent]) {
                        visited[adjacent] = true;
                        queue.push_back(adjacent);
                    }
                }
            }
        }

        static void DFS(int v){
            visited[v] = true;
            std::cout << v << " ";

            for (int u : adj[v]) {
                if (!visited[u])
                    DFS(u);
            }
        }
    };

    class Algebra{
    public:
        static int gcd(int a, int b){
            return b ? gcd(b, a % b) : a;
        }

        static long long lcm(int a, int b){
            return a / gcd(a, b) * b;
        }

        static int fib(int n) {
            int a = 0;
            int b = 1;
            for (int i = 0; i < n; i++) {
                int tmp = a + b;
                a = b;
                b = tmp;
            }
            return a;
        }

        static std::vector<bool> sieve(int MAX){
            std::vector<bool> isPrime(MAX+1, true);

            isPrime[0] = isPrime[1] = false;
            for(int i = 2; (long long)i * i <= MAX; i++){
                if(isPrime[i]){
                    for(int j = i * i; j <= MAX; j+=i){
                        isPrime[j] = false;
                    }
                }
            }
            return isPrime;
        }

        static long long binpow(long long a, long long b) {
            long long res = 1;
            while (b > 0) {
                if (b & 1)
                    res = res * a;
                a = a * a;
                b >>= 1;
            }
            return res;
        }
    };
}