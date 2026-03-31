
#pragma once

#include "synthSound.h"
#include <JuceHeader.h>

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

private:
	juce::dsp::Oscillator<float> osc
	{
		// lambda that defines the function for calculating the waveform
		[](float x)
		{
			// sine
			//return std::sin(x);

			// saw
			return x / juce::MathConstants<float>::pi;

			// square
			//return x < 0.0f ? -1.0f : 1.0f;
		},
		200 // lookup table size
	};

	juce::AudioBuffer<float> synthBuffer;

	juce::dsp::Gain<float> gain;

	juce::ADSR adsr;
	juce::ADSR::Parameters adsr_params;
};