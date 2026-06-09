
#include <JuceHeader.h>
#include "adsrUI.h"


adsrUI::adsrUI(juce::AudioProcessorValueTreeState& apvts)
{
    attackSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_attack", a_panel.attackSlider);
    decaySliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_decay", d_panel.decaySlider);
    sustainSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_sustain", s_panel.sustainSlider);
    releaseSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "_release", r_panel.releaseSlider);

    addAndMakeVisible(a_panel);
    addAndMakeVisible(d_panel);
    addAndMakeVisible(s_panel);
    addAndMakeVisible(r_panel);
}

adsrUI::~adsrUI()
{
}

void adsrUI::paint (juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    // border around the ADSR panel
    g.setColour(juce::Colours::grey);
    g.drawRect(getLocalBounds(), 1);
}

void adsrUI::resized()
{
    juce::FlexBox fb;
    if (getWidth() > getHeight())         // landscape mode
    {
        fb.flexDirection = juce::FlexBox::Direction::row;
    }
    else                                 // portrait mode
    {
        fb.flexDirection = juce::FlexBox::Direction::column;
    }
    fb.alignItems = juce::FlexBox::AlignItems::stretch;

    // add panel flexItems
    juce::FlexItem attackPanelFlexItem(80, 80, a_panel);
    juce::FlexItem decayPanelFlexItem(80, 80, d_panel);
    juce::FlexItem sustainPanelFlexItem(80, 80, s_panel);
    juce::FlexItem releasePanelFlexItem(80, 80, r_panel);
    fb.items.addArray({attackPanelFlexItem, decayPanelFlexItem, sustainPanelFlexItem, releasePanelFlexItem});


    fb.performLayout(getLocalBounds());
}