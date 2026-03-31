
#include "PluginProcessor.h"
#include "PluginEditor.h"


VoxGenesisAudioProcessorEditor::VoxGenesisAudioProcessorEditor (VoxGenesisAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);

    attackSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.getState(), "_attack", attackSlider);
    decaySliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.getState(), "_decay", decaySlider);
    sustainSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.getState(), "_sustain", sustainSlider);
    releaseSliderAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.getState(), "_release", releaseSlider);

    oscSelectorAttatchment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(p.getState(), "_osc-select", oscSelector);

    styleSlider(attackSlider);
    styleSlider(decaySlider);
    styleSlider(sustainSlider);
    styleSlider(releaseSlider);
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
    const auto bounds = getLocalBounds().reduced(10);               // create box to put items in. not needed, but for organization
    const auto padding = 10;


    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight() / 2 - padding;
    const auto sliderStartX = 0 + padding;
    const auto sliderStartY = bounds.getHeight() / 2 - (sliderHeight / 2);

    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
}

void VoxGenesisAudioProcessorEditor::styleSlider(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 80, 30);
    addAndMakeVisible(slider);
}
