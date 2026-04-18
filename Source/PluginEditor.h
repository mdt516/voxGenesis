
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

#include "UI/adsrUI.h"
#include "UI/oscillatorUI.h"


class VoxGenesisAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    VoxGenesisAudioProcessorEditor (VoxGenesisAudioProcessor&);
    ~VoxGenesisAudioProcessorEditor() override;


    void paint (juce::Graphics&) override;
    void resized() override;

private:
    VoxGenesisAudioProcessor& audioProcessor;

    juce::ComboBox waveType1Selector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> waveType1SelectorAttatchment;

    adsrUI adsr;
    oscillatorUI osc;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VoxGenesisAudioProcessorEditor)
};
