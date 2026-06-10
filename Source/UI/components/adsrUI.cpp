
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
    // border around the ADSR panel
    g.setColour(juce::Colours::grey);
    g.drawRect(getLocalBounds(), 1);
}

void adsrUI::resized()
{
    const int PANEL_WIDTH = 80;
    const int PANEL_HEIGHT = 80;

    juce::FlexBox fb;
    if (getWidth() > getHeight())         // landscape mode
    {
        fb.flexDirection = juce::FlexBox::Direction::row;
    }
    else                                 // portrait mode
    {
        fb.flexDirection = juce::FlexBox::Direction::column;
    }
    fb.justifyContent = juce::FlexBox::JustifyContent::spaceAround;

    // add panel flexItems
    juce::FlexItem attackPanelFlexItem(PANEL_WIDTH, PANEL_HEIGHT, a_panel);
    juce::FlexItem decayPanelFlexItem(PANEL_WIDTH, PANEL_HEIGHT, d_panel);
    juce::FlexItem sustainPanelFlexItem(PANEL_WIDTH, PANEL_HEIGHT, s_panel);
    juce::FlexItem releasePanelFlexItem(PANEL_WIDTH, PANEL_HEIGHT, r_panel);
    fb.items.addArray({attackPanelFlexItem, decayPanelFlexItem, sustainPanelFlexItem, releasePanelFlexItem});

    attackPanelFlexItem.flexGrow = 1;
    decayPanelFlexItem.flexGrow = 1;
    sustainPanelFlexItem.flexGrow = 1;
    releasePanelFlexItem.flexGrow = 1;

    attackPanelFlexItem.flexShrink = 1;
    decayPanelFlexItem.flexShrink = 1;
    sustainPanelFlexItem.flexShrink = 1;
    releasePanelFlexItem.flexShrink = 1;

    fb.performLayout(getLocalBounds());
}