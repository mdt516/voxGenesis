#pragma once

#include <JuceHeader.h>

class customLookAndFeel : public juce::LookAndFeel_V4
{
public:
	customLookAndFeel();
	~customLookAndFeel();

	//void drawLinearSliderBackground(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, 
	//								juce::Slider::SliderStyle style, juce::Slider& s) override;

	void drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos,
						  juce::Slider::SliderStyle style, juce::Slider& s) override;

private:
};