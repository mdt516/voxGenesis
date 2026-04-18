

#include "adsrData.h"

void adsrData::updateADSR(const float a, const float d, const float s, const float r)
{
	adsr_params.attack = a;
	adsr_params.decay = d;
	adsr_params.sustain = s;
	adsr_params.release = r;

	setParameters(adsr_params);
}