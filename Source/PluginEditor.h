
#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

#include <jive_layouts/jive_layouts.h>

class VoxGenesisAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
	VoxGenesisAudioProcessorEditor(VoxGenesisAudioProcessor&);
	~VoxGenesisAudioProcessorEditor() override;

	void resized() override;

private:
	VoxGenesisAudioProcessor& audioProcessor;

	jive::Interpreter interpreter;
	juce::ValueTree view;

	std::unique_ptr<jive::GuiItem> rootItem;

	melatonin::Inspector ui_inspector{*this};

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoxGenesisAudioProcessorEditor)
};
