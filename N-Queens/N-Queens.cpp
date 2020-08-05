#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void print(int array[], int c, int size)
{
		cout << "This is solution number " << c << endl;
 		for (int i=0; i<size; i++)
			cout << array[i] << ' ';
		cout << endl;
		cout << endl;
}

void backtrack(int q[], int &c)
{
	  q[c] = 0;
	  c--;
	  
	  if (c < 0) return;
	  q[c]++;
	  
	  if (q[c] == 8) backtrack(q, c);
}

bool good(int q[], int c){
    for (int i = 0; i < c; i++){
      if ( c - i == abs(q[c] - q[i]) || q[c] == q[i]){
              return false;
      }
    }

return true;

}

int main() {
  // if (f()) cout << "false";

  int size;

  cout << "Please enter size of n queens problem" << endl;
  cin >> size;
  int *q = new int [size];
  int c = 0;
  int solution = 0;

  while (c > -1)
  {


    if (c == size) // check if column is out of bound
    {
      backtrack(q, c);
      solution++;
      print(q, solution, size);

    }

    else if (q[c] == size)  // check if row is out of bound
    {
      backtrack(q, c);
    }


    else if (good(q, c)) // check if we can place queen at current row
    {
      c++; // go to next column

    }
    else q[c]++;

  }

  delete []q;
}
