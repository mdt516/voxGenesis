

#include "oscillatorData.h"

void oscillatorData::setWaveType(const int choice)
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

void oscillatorData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
	prepare(spec);
}

void oscillatorData::renderNextBlock(juce::dsp::AudioBlock<float>& block)
{
	process(block);
}

void oscillatorData::setWaveFrequency(const int midiNoteNumber)
{
	setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
}
