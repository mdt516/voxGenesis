
#include <JuceHeader.h>
#include "oscillatorUI.h"


oscillatorUI::oscillatorUI(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorID)
{
    juce::StringArray waveTypes{"sine", "saw", "square"};
    waveSelector.addItemList(waveTypes, 1);
    addAndMakeVisible(waveSelector);

    waveSelectorAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectorID, waveSelector);
}

oscillatorUI::~oscillatorUI()
{
}

void oscillatorUI::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (14.0f));
}

void oscillatorUI::resized()
{
    waveSelector.setBounds(0, 0, 90, 20);
}
