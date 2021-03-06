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
		cout<<"My RAM volume is "<<volume<<"."<<endl;
		cout<<"My RAM rate is "<<rate<<"."<<endl;	
		cout<<"My RAM Levele is DDR"<<(int)ddr<<"."<<endl;
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

class rom{

	int volume,rpm;
	
	public:

	rom (int vol,int r):volume(vol),rpm(r){
		cout<<"Make a rom!\n";
	};
	~rom(){
		cout<<"Lose a rom!\n";
	};
	void setrom (int vol,int r){
		volume=vol;
		rpm=r;
	};
	void showrom (){
		cout<<"My ROM volume is "<<volume<<"."<<endl;
		cout<<"My ROM rpm is "<<rpm<<"."<<endl;	
	};
	int getvolume (){
		return volume;
	};
	float getrpm (){
		return rpm;
	};
	void stoprom ();
	void runrom ();
};
	void rom::runrom (){
		showrom();
		cout<<"ROM is working!\n";
	};
	void rom::stoprom (){
		cout<<"ROM is stoping!\n";
	};

class computer {
	cpu c;
	ram r;
	rom o;
	
	public:

	computer (cpu cc,ram rc,rom oc):c(cc),r(rc),o(oc){
		cout<<"MAKE a computer!\n";
	};
	~computer (){
		cout<<"LOSE a computer!\n";
	};
	void showcomputer (){
		c.showcpu();
		r.showram();
		o.showrom();
	};
	void runcomputer (){
		showcomputer();
		cout<<"Computer is working!\n";
	};
	void stopcomputer (){
		cout<<"Computer is stoping!\n";
	};	
};


int main()
{
	float cpuvol,cpurate,ramrate;
	int cpule,ramle,romrpm,ramvol,romvol;
	cout<<"Please enter CPU parameter.\n"<<"(voltage rate Level)\n";
	cin>>cpuvol>>cpurate>>cpule;
	cpu mycpu(cpuvol,cpurate,cpule);
	mycpu.runcpu();
	mycpu.stopcpu();
	cout<<"Please enter RAM parameter.\n"<<"(volume rate DDRlevel)\n";
	cin>>ramvol>>ramrate>>ramle;
	ram myram(ramvol,ramrate,ramle);
	myram.runram();
	myram.stopram();
	cout<<"Please enter ROM parometer.\n"<<"(volume rpm\n)";
	cin>>romvol>>romrpm;
	rom myrom(romvol,romrpm);
	myrom.runrom();
	myrom.stoprom();
	cout<<"Computer ready!";
	computer mycomputer(mycpu,myram,myrom);
	mycomputer.runcomputer();
	mycomputer.stopcomputer();
	return 0;
}

