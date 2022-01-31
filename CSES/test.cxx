
#include <iostream>
using namespace std;
 
void fun(int *arr, unsigned int n)
{
   for (int i = 0; i < n; i++)
   {
	   arr[i] *= 23;
   }
}

void fun2(int arr[8], unsigned int n)
{
   for (int i = 0; i < n; i++)
   {
	   arr[i] *= 0;
   }
}
 
// Driver program
int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
   unsigned int n = sizeof(arr)/sizeof(arr[0]);
   //fun(arr, n);
	fun2(arr, n);

   for (int i = 0; i < n; i++)
   {
	   cout <<" "<< arr[i];
   }
   return 0;
}