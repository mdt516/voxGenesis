
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

#include "UI/adsr-ui.h"


class VoxGenesisAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    VoxGenesisAudioProcessorEditor (VoxGenesisAudioProcessor&);
    ~VoxGenesisAudioProcessorEditor() override;


    void paint (juce::Graphics&) override;
    void resized() override;

private:
    VoxGenesisAudioProcessor& audioProcessor;

    juce::ComboBox oscSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelectorAttatchment;

    adsr_ui adsr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VoxGenesisAudioProcessorEditor)
};
