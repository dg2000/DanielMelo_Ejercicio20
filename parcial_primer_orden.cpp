#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;



void evoluciona( double* ut, int nx, double hx, double ht, double c)
{
  for (int i=0; i < nx-1 ; i++)
    {
       ut[i+1]=ut[i]- c*(ht/hx)*( ut[i+1] - ut[i] );
    }
}




int main()
{

  double c = 1.0;

  double T = 0.5;

  double hx = 0.1;

  double ht = 0.01;

  double L = 2.0;

  int nx = (L/hx) + 1;

  int nt =(T/ht)+ 1;

  double* ut      = new double[nx];

  //double* ut = new double[nx];

  


  for (int i=0; i < nx; i++)
    {

      if (i < 0.75)
	{
	  ut     [i] = 0.0;
	}

      else if ( (i > 0.75) && (i < 1.25) )
	{
	  ut     [i] = 1.0;
	}

      else
	{
	  ut     [i] = 0.0;
	}

    }

  

  for (int j=0; j < nt; j++)
    {
      evoluciona( ut,nx,  hx,  ht,  c);
    }

  for (int k=0; k < nx; k++)
    {
      cout << k*nx << " " << ut[k] << endl;
    }
  

  return 0;
}


      

  
	  
	  
  
