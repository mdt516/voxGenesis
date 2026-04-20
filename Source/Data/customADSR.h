
#pragma once
#include <JuceHeader.h>

class customADSR : public juce::ADSR
{
public:
    void updateADSR(const float a, const float d, const float s, const float r);

private:
    juce::ADSR::Parameters adsr_params;
};