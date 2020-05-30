#pragma once
#include "framework.h"
using namespace std;


class HPTimer
{
public:
	HPTimer();
	~HPTimer();


	void Reset();
	void Update();
	double GetTimeTotal();
	double GetTimeDelta();

private:

	long long startTime;
	long long lastCallToUpdate;
	long long currentCallToUpdate;
	long long freqency;

};

