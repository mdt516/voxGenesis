
#include <JuceHeader.h>
#include "adsrUI.h"


adsrUI::adsrUI(juce::AudioProcessorValueTreeState& apvts)
{
    attackSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_attack", attackSlider);
    decaySliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_decay", decaySlider);
    sustainSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_sustain", sustainSlider);
    releaseSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_release", releaseSlider);

    addAndMakeVisible(attackSlider);
    addAndMakeVisible(decaySlider);
    addAndMakeVisible(sustainSlider);
    addAndMakeVisible(releaseSlider);
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
    int textBoxWidth = 50;
    int textBoxHeight = 30;

    juce::FlexBox fb;
    if (getWidth() > getHeight())
    {
        fb.flexDirection = juce::FlexBox::Direction::row;
        attackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
        decaySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
        sustainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
        releaseSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);

        attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, textBoxWidth, textBoxHeight);
        decaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, textBoxWidth, textBoxHeight);
        sustainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, textBoxWidth, textBoxHeight);
        releaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, textBoxWidth, textBoxHeight);
    }
    else
    {
        fb.flexDirection = juce::FlexBox::Direction::column;
        attackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
        decaySlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
        sustainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
        releaseSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);

        attackSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, textBoxWidth, textBoxHeight);
        decaySlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, textBoxWidth, textBoxHeight);
        sustainSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, textBoxWidth, textBoxHeight);
        releaseSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, textBoxWidth, textBoxHeight);
    }
    fb.alignItems = juce::FlexBox::AlignItems::stretch;

    juce::FlexItem attack_fi(80, 80, attackSlider);
    juce::FlexItem decay_fi(80, 80, decaySlider);
    juce::FlexItem sustain_fi(80, 80, sustainSlider);
    juce::FlexItem release_fi(80, 80, releaseSlider);
    fb.items.addArray({attack_fi, decay_fi, sustain_fi, release_fi});

    attack_fi.flexGrow = 0.25;
    decay_fi.flexGrow = 0.25;
    sustain_fi.flexGrow = 0.25;
    release_fi.flexGrow = 0.25;

    fb.performLayout(getLocalBounds());
}