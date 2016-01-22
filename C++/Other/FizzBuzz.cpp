// C++ 2016/01/22 Hiroki Naganuma Created
#include<iostream>
using namespace std;

int main()
{
	int fizz,buzz;
	int end,i;
	cin >> end;
	i=0;
	
	while (++i <= end) {
		fizz = i % 3;
	    buzz = i % 5;
	    if (fizz == 0 && buzz == 0) {
	        cout << "FizzBuzz" << endl;
	    }else if (fizz == 0) {
	        cout << "Fizz" << endl;
	    }else if (buzz == 0) {
	        cout << "Buzz" << endl;
	    }else {
	        cout << i << endl;
	    }
	}
	return 0;
}