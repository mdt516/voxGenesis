
#include "synthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{
	return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
	osc.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));

	adsr.noteOn();
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
	adsr.noteOff();

	if (!adsr.isActive())
	{
		clearCurrentNote();
	}
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{}

void SynthVoice::prepare(double sampleRate, int samplesPerBlock, int outputChannels)
{
	// set up specs
	juce::dsp::ProcessSpec spec;
	spec.maximumBlockSize = samplesPerBlock;
	spec.sampleRate = sampleRate;
	spec.numChannels = outputChannels;

	// set up adsr env
	adsr.setSampleRate(sampleRate);

	// prepare components
	osc.prepare(spec);
	gain.prepare(spec);

	gain.setGainLinear(0.02f);


	// hard-coded adsr values, subject to change
	adsr_params.attack = 0.8f;
	adsr_params.decay = 0.8f;
	adsr_params.sustain = 1.0f;
	adsr_params.release = 1.5f;

	adsr.setParameters(adsr_params);
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	if (!isVoiceActive())
	{
		return;
	}

	// set synthBuffer size to outputBuffer size and clear it
	synthBuffer.setSize(outputBuffer.getNumChannels(), outputBuffer.getNumSamples(), false, false, true);
	synthBuffer.clear();

	juce::dsp::AudioBlock<float> audioBlock(synthBuffer);

	// add osc gain, and adsr processing to synthBuffer
	osc.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
	gain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
	adsr.applyEnvelopeToBuffer(synthBuffer, startSample, numSamples);


	// add info from synthBuffer into outputbuffer to wrap everything up in a neat bow
	for (int i = 0; i < outputBuffer.getNumChannels(); i++)
	{
		outputBuffer.addFrom(i, startSample, synthBuffer, i, 0, numSamples);

		if (!adsr.isActive())
		{
			clearCurrentNote();
		}
	}
}
