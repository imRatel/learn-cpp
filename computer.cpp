#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

enum class Level {
	L1=1,L2,L3,L4,L5
};

class cpu {
	
	float voltage,rate;
	Level level;
	
	public:

	cpu (float v,float r,int l):voltage(v),rate(r),level((Level)l){
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
	int getlevel (){
		return (int)level;
	};
	void setcpu (float v,float r,int l){
		voltage=v;
		rate=r;
		level=(Level)l;
	};
	void showcpu (){
		cout<<"My cpu voltage is "<<voltage<<"."<<endl;
		cout<<"My cpu rate is "<<rate<<"."<<endl;	
		cout<<"My cpu Levele is L"<<(int)level<<"."<<endl;
	};
	void runcpu ();
	void stopcpu ();
};
	void cpu::runcpu (){
		showcpu();
		cout<<"CPU is working!\n";
	};
	void cpu::stopcpu (){
		cout<<"CPU is stoping!\n";
	};

class ram {
	
	int volume;
	float rate;
	Level ddr;
	
	public:

	ram (int vol,float ra,int l):volume(vol),rate(ra),ddr((Level)l){
		cout<<"Make a RAM!\n";
	};
	~ram(){
		cout<<"Lose a RAM!\n";
	};
	void setram (int vol,float ra,int l){
		volume=vol;
		rate=ra;
		ddr=(Level)l;
	};
	void showram (){
		cout<<"My cpu volume is "<<volume<<"."<<endl;
		cout<<"My cpu rate is "<<rate<<"."<<endl;	
		cout<<"My cpu Levele is DDR"<<(int)ddr<<"."<<endl;
	};
	int getvolume (){
		return volume;
	};
	float getrate (){
		return rate;
	};
	int getddr (){
		return (int)ddr;
	};
	void stopram ();
	void runram ();
};
	void ram::runram (){
		showram();
		cout<<"RAM is working!\n";
	};
	void ram::stopram (){
		cout<<"RAM is stoping!\n";
	};


int main()
{
	float a,b;
	int c,d;
	cout<<"Please enter CPU parameter.\n"<<"(voltage rate Level)\n";
	cin>>a>>b>>c;
	cpu mycpu(a,b,c);
	mycpu.runcpu();
	mycpu.stopcpu();
	cout<<"Please enter RAM parameter.\n"<<"(volume rate ddrlevel)\n";
	cin>>d>>b>>c;
	ram myram(d,b,c);
	myram.runram();
	myram.stopram();
	return 0;
}

