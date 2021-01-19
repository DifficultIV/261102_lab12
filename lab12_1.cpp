#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double a[],int N,double b[]){
    double sumA ,sumH,sum,SD;
    double max = a[0], min = a[0],sumG = 1,sumS = 0;
    for(int i = 0; i < N; i++) sum += a[i];
    double mean = sum/N;
    for(int i = 0; i < N; i++){
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
        sumA += a[i];
        sumS += pow(a[i]-mean,2); 
        sumG *= a[i];
        sumH += 1/a[i]; 
    }
    SD = sumS/N;
    b[0] = sumA/N;
    b[1] = sqrt(SD);
    b[2] = pow(sumG,1.0/N);
    b[3] = N/sumH;
    b[4] = max;
    b[5] = min;
}