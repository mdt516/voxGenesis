
#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

#include "UI/adsrUI.h"
#include "UI/oscillatorUI.h"


class VoxGenesisAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
	VoxGenesisAudioProcessorEditor(VoxGenesisAudioProcessor&);
	~VoxGenesisAudioProcessorEditor() override;


	void paint(juce::Graphics&) override;
	void resized() override;

private:
	VoxGenesisAudioProcessor& audioProcessor;

	adsrUI adsr_panel;
	oscillatorUI osc_panel;
	juce::Component main_window;

	melatonin::Inspector ui_inspector{*this};

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoxGenesisAudioProcessorEditor)
};
