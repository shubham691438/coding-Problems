#include <iostream>

 int factorial(int n) {
     int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

 int combination(int n, int r) {
    if (r > n) return 0;
    if(n*(n-1)*(n-2) / 6<0) return 0;
    return n*(n-1)*(n-2) / 6;
}


 int diverseDeputation(int M, int W) {
    
     int totalWays = combination(M + W, 3);

    
     int allMenWays = combination(M, 3);

    
     int allWomenWays = combination(W, 3);

  
     int diverseWays = totalWays - allMenWays - allWomenWays;

    return diverseWays;
}

int main() {
    int M, W;
    
    std::cin >> M;
    std::cin >> W;

     int result = diverseDeputation(M, W);
    std::cout<< result << std::endl;

    return 0;
}
