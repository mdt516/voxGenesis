

#include "customOscillator.h"

void customOscillator::setWaveType(const int choice)
{
	switch (choice)
	{
		case 0:   // sine
			initialise([](float x)
			{
				return std::sin(x);
			});
			break;

		case 1:   // saw
			initialise([](float x)
			{
				return x / juce::MathConstants<float>::pi;
			});
			break;

		case 2:   // square
			initialise([](float x)
			{
				return (x < 0.0f) ? -1.0f : 1.0f;
			});
			break;
	}
}

void customOscillator::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
	prepare(spec);
	freq.reset(spec.sampleRate, 0.05);
}

void customOscillator::renderNextBlock(juce::dsp::AudioBlock<float>& block)
{
	auto context = juce::dsp::ProcessContextReplacing<float>(block);
	process(context);
}

void customOscillator::setWaveFrequency(const int midiNoteNumber)
{
	freq.setTargetValue(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
	setFrequency(freq.getNextValue());
}
