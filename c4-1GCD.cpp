#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

class GCD {
	private:
		int num;
	public:
		GCD (int a) {
			num=a;
		};
		int getnum () {
			return num;
		};
		int getgcd (GCD a);
};
int GCD::getgcd (GCD a) {
	for (int r=numa;r!=0;numb=r) {
		r=numa%numb;
		num=numb;
	};
	return num;
};

int main()
{
	int a,b;
	cin>>a>>b;
	GCD A(a);
	GCD B(b);
	A.getgcd(B);
	cout<<A.getnum()<<endl;
	return 0;
};
