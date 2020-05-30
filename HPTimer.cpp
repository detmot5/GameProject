#include "HPTimer.h"



HPTimer::HPTimer() {
	LARGE_INTEGER t;
	QueryPerformanceFrequency(&t);
	freqency = t.QuadPart;
	Reset();
}




HPTimer::~HPTimer() {

}

void HPTimer::Reset() {
	LARGE_INTEGER t;
	QueryPerformanceFrequency(&t);
	startTime = t.QuadPart;
	currentCallToUpdate = t.QuadPart;
	lastCallToUpdate = t.QuadPart;


}



void HPTimer::Update() {
	lastCallToUpdate = currentCallToUpdate;
	LARGE_INTEGER t;
	QueryPerformanceCounter(&t);
	currentCallToUpdate = t.QuadPart;
}


double HPTimer::GetTimeTotal() {
	double d = static_cast<double>(currentCallToUpdate - startTime);
	return d / freqency;
}

double HPTimer::GetTimeDelta() {
	double d = static_cast<double>(currentCallToUpdate - lastCallToUpdate);
	return d / freqency;
}