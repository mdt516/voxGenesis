
#pragma once

#include <JuceHeader.h>

#include "synthSound.h"
#include "../DSP/customADSR.h"
#include "../DSP/customOscillator.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
	bool canPlaySound(juce::SynthesiserSound*) override;
	void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
	void stopNote(float velocity, bool allowTailOff) override;
	void pitchWheelMoved(int newPitchWheelValue) override;
	void controllerMoved(int controllerNumber, int newControllerValue) override;

	void prepare(double sampleRate, int samplesPerBlock, int outputChannels);
	void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples) override;

	void updateADSR(const float a, const float d, const float s, const float r);

	customOscillator& getOscillator() { return osc; }
private:
	customOscillator osc;

	juce::AudioBuffer<float> synthBuffer;
	juce::dsp::Gain<float> gain;

	customADSR adsr;
};