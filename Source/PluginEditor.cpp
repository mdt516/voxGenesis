
#include "PluginProcessor.h"
#include "PluginEditor.h"


VoxGenesisAudioProcessorEditor::VoxGenesisAudioProcessorEditor (VoxGenesisAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), adsr(p.getState()), osc(p.getState(), "_osc1-wave-type")
{
    setSize (400, 300);

    addAndMakeVisible(adsr);
    addAndMakeVisible(osc);
}

VoxGenesisAudioProcessorEditor::~VoxGenesisAudioProcessorEditor()
{
}


void VoxGenesisAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void VoxGenesisAudioProcessorEditor::resized()
{
    osc.setBounds(10, 10, 100, 30);
    adsr.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight());
}
