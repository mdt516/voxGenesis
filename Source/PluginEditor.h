
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include <melatonin_inspector/melatonin_inspector.h>


class VoxGenesisAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    VoxGenesisAudioProcessorEditor (VoxGenesisAudioProcessor&);
    ~VoxGenesisAudioProcessorEditor() override;


    void paint (juce::Graphics&) override;
    void resized() override;

private:
    VoxGenesisAudioProcessor& audioProcessor;
    jcf::BufferDebugger buffdebug;
    melatonin::Inspector inspect{*this};

    juce::ComboBox oscSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelectorAttatchment;

    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackSliderAttatchment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> decaySliderAttatchment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sustainSliderAttatchment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttatchment;

    void styleSlider(juce::Slider& slider);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VoxGenesisAudioProcessorEditor)
};
