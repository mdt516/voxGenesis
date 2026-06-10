#include "customLookAndFeel.h"

customLookAndFeel::customLookAndFeel()
{}

customLookAndFeel::~customLookAndFeel()
{}

//void customLookAndFeel::drawLinearSliderBackground(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos,
//												   juce::Slider::SliderStyle style, juce::Slider& s)
//{
//	juce::Rectangle<float> sliderArea(x, y, width, height);
//
//	std::cerr << "test message" << std::endl;
//
//	g.setColour(juce::Colours::aliceblue);
//	g.fillRect(sliderArea);
//}

void customLookAndFeel::drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, juce::Slider::SliderStyle style, juce::Slider& s)
{
	auto sliderArea = s.getLocalBounds();


	g.setColour(juce::Colours::red);
	g.fillRect(sliderArea);
}
