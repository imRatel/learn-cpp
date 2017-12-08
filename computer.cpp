#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

enum class Level {
	L1=1,L2,L3,L4,L5
};

class cpu{
	
	float voltage,rate;
	Level level;
	
	public:
	cpu (float v,float r,int l):voltage(v),rate(r),level((char)l){
		cout<<"Make a cpu!\n";
	};
	~cpu (){
		cout<<"Lose a cpu!\n";
	};
	float getvoltage (){
		return voltage;
	};
	float getrate (){
		return rate;
	};
	float getlevel (){
		return (int)level;
	};
	void setcpu (float v,float r,int l){
		voltage=v;
		rate=r;
		level=l;
	};
	void showcpu (){
		cout<<"My cpu voltage is "<<voltage<<"."<<endl;
		cout<<"My cpu rate is "<<rate<<"."<<endl;	
		cout<<"My cpu Levele is L"<<(int)level<<"."<<endl;
	};
}


using namespace std;
int main()
{

  return 0;
}

