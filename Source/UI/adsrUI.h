#pragma once

#include <JuceHeader.h>


class adsrUI  : public juce::Component
{
public:
    adsrUI(juce::AudioProcessorValueTreeState& apvts);
    ~adsrUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackSliderAttatchment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> decaySliderAttatchment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sustainSliderAttatchment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttatchment;

    void styleSlider(juce::Slider& slider);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (adsrUI)
};
