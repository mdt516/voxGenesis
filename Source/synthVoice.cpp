
#include "synthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{
	return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
	osc.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
	osc.reset();    // reset phase

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

	gain.setGainLinear(0.08f);
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	if (!isVoiceActive())
	{
		return;
	}

	// set synthBuffer size to outputBuffer size and clear it
	synthBuffer.setSize(outputBuffer.getNumChannels(), numSamples, false, false, true);
	synthBuffer.clear();

	juce::dsp::AudioBlock<float> audioBlock(synthBuffer);

	// add osc gain, and adsr processing to synthBuffer
	osc.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
	gain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
	adsr.applyEnvelopeToBuffer(synthBuffer, 0, numSamples);


	// add info from synthBuffer into outputbuffer to wrap everything up in a neat bow
	for (int i = 0; i < outputBuffer.getNumChannels(); i++)
	{
		outputBuffer.addFrom(i, startSample, synthBuffer, i, 0, numSamples);

		if (!adsr.isActive())
		{
			clearCurrentNote();
		}
	}

	jcf::BufferDebugger::capture("output", outputBuffer.getReadPointer(0), outputBuffer.getNumSamples(), -0.4, 0.4);
}

void SynthVoice::updateADSR(const float a, const float d, const float s, const float r)
{
	adsr_params.attack = a;
	adsr_params.decay = d;
	adsr_params.sustain = s;
	adsr_params.release = r;

	adsr.setParameters(adsr_params);
}
