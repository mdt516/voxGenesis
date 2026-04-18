
#pragma once

#include <JuceHeader.h>


class oscillatorUI : public juce::Component
{
public:
	oscillatorUI(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorID);
	~oscillatorUI() override;

	void paint(juce::Graphics&) override;
	void resized() override;

private:
	juce::ComboBox waveSelector;
	std::unique_ptr <juce::AudioProcessorValueTreeState::ComboBoxAttachment> waveSelectorAttatchment;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(oscillatorUI)
};
