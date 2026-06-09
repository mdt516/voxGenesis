
#include "PluginEditor.h"
#include "PluginProcessor.h"


VoxGenesisAudioProcessorEditor::VoxGenesisAudioProcessorEditor(VoxGenesisAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p), adsr_panel(p.getState()), osc_panel(p.getState(), "_osc1-wave-type")
{
	setSize(400, 400);
	setResizable(true, false);

	addAndMakeVisible(adsr_panel);
	addAndMakeVisible(osc_panel);

	ui_inspector.setVisible(true);
}

VoxGenesisAudioProcessorEditor::~VoxGenesisAudioProcessorEditor()
{}


void VoxGenesisAudioProcessorEditor::paint(juce::Graphics& g)
{
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void VoxGenesisAudioProcessorEditor::resized()
{
	juce::FlexBox fb;
	fb.flexDirection = juce::FlexBox::Direction::column;

	juce::FlexItem oscillator_fi(100, 30, osc_panel);
	juce::FlexItem adsr_fi(200, 300, adsr_panel);

	oscillator_fi.margin = 5;
	adsr_fi.margin = 5;

	fb.items.addArray({oscillator_fi, adsr_fi});
	fb.performLayout(getLocalBounds().reduced(10));
}
