
#include <JuceHeader.h>
#include "adsrUI.h"


adsrUI::adsrUI(juce::AudioProcessorValueTreeState& apvts)
{
    styleSlider(attackSlider);
    styleSlider(decaySlider);
    styleSlider(sustainSlider);
    styleSlider(releaseSlider);

    attackSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_attack", attackSlider);
    decaySliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_decay", decaySlider);
    sustainSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_sustain", sustainSlider);
    releaseSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_release", releaseSlider);
}

adsrUI::~adsrUI()
{
}

void adsrUI::paint (juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.setColour(juce::Colours::grey);
    g.drawRect(getLocalBounds(), 1);
}

void adsrUI::resized()
{
    const auto bounds = getLocalBounds().reduced(20);               // create box to put items in. not needed, but for organization
    const auto padding = 10;


    const auto sliderWidth = bounds.getWidth() / 4;
    const auto sliderHeight = bounds.getHeight();
    const auto sliderStartX = 0;
    const auto sliderStartY = 0;

    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
}

void adsrUI::styleSlider(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 80, 30);
    addAndMakeVisible(slider);
}