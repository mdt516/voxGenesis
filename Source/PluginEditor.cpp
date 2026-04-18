
#include "PluginProcessor.h"
#include "PluginEditor.h"


VoxGenesisAudioProcessorEditor::VoxGenesisAudioProcessorEditor (VoxGenesisAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), adsr(p.getState())
{
    setSize (400, 300);

    addAndMakeVisible(adsr);

    oscSelectorAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(p.getState(), "_osc-select", oscSelector);
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
    adsr.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight());
}
