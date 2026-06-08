
#include "oscillatorUI.h"
#include <JuceHeader.h>


oscillatorUI::oscillatorUI(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorID)
{
	juce::StringArray waveTypes{"sine", "saw", "square"};
	waveSelector.addItemList(waveTypes, 1);

	waveSelectorAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectorID, waveSelector);

	addAndMakeVisible(waveSelector);
}

oscillatorUI::~oscillatorUI()
{}

void oscillatorUI::paint(juce::Graphics& g)
{
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));   // clear the background

	g.setColour(juce::Colours::white);
	g.setFont(juce::FontOptions(14.0f));
}

void oscillatorUI::resized()
{
	juce::FlexBox fb;
	fb.justifyContent = juce::FlexBox::JustifyContent::center;

	juce::FlexItem waveComboBox(90, 20, waveSelector);

	fb.items.add(waveComboBox);

	fb.performLayout(getLocalBounds());
}
