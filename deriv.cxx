#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void fu(double* x, const double& mi, const double& ma, const int len){
  double step = (ma-mi)/(len-1);
  for(int i = 0; i < len; i++){
    x[i] = exp(-(i*step+mi)*(i*step+mi));
  }
}

void deri(double* x, const double& dex, const int len){
  double bu1,bu2 = x[0]; // Puffer
  
  // Randwert links
  x[0] = x[1]/(2*dex);
  for(int i = 1; i < (len-1); i++){
    bu1 = x[i];
    x[i] = (x[i+1]-bu2)/(2*dex);
    bu2 = bu1;
  }
  // Randwert rechts
  x[len-1] = -bu2/(2*dex);
}


int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  // call to function which fills array p here
  fu(p,xmin,xmax,N);
  // call to functio which calculates the derivative
  deri(p,dx,N);
  
  print(p,N,dx,xmin);

  return 0;
}
