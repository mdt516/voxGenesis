#pragma once

#include <JuceHeader.h>
#include "../customLookAndFeel.h"


class adsrUI : public juce::Component
{
public:
	adsrUI(juce::AudioProcessorValueTreeState& apvts);
	~adsrUI() override;

	void paint(juce::Graphics&) override;
	void resized() override;

private:
	static inline customLookAndFeel laf;

	static const int NUM_TEXT_BOX_WIDTH = 60;
	static const int NUM_TEXT_BOX_HEIGHT = 30;

	static const int LABEL_BOX_WIDTH = 30;
	static const int LABEL_BOX_HEIGHT = 50;

	static const int SLIDER_WIDTH = 60;
	static const int SLIDER_HEIGHT = 180;

	struct attackPanel : public juce::Component
	{
		attackPanel()
		{
			attackLabel.setText("Attack", juce::NotificationType::dontSendNotification);
			attackLabel.setJustificationType(juce::Justification::centred);

			attackSlider.setLookAndFeel(&laf);

			addAndMakeVisible(attackSlider);
			addAndMakeVisible(attackLabel);
		}

		void resized() override
		{
			juce::FlexBox fb;
			if (getParentComponent()->getWidth() > getParentComponent()->getHeight())      // landscape mode
			{
				attackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
				attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, NUM_TEXT_BOX_WIDTH, NUM_TEXT_BOX_HEIGHT);
			}
			else                                                                           // portrait mode
			{
				attackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
				attackSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, NUM_TEXT_BOX_WIDTH, NUM_TEXT_BOX_HEIGHT);
			}
			fb.flexDirection = juce::FlexBox::Direction::column;
			fb.justifyContent = juce::FlexBox::JustifyContent::spaceAround;

			juce::FlexItem sliderItem(SLIDER_WIDTH, SLIDER_HEIGHT, attackSlider);
			juce::FlexItem labelItem(LABEL_BOX_WIDTH, LABEL_BOX_HEIGHT, attackLabel);
			fb.items.addArray({sliderItem, labelItem});

			fb.performLayout(getLocalBounds());
		}

		juce::Slider attackSlider;
		juce::Label attackLabel;
	};

	struct decayPanel : public juce::Component
	{
		decayPanel()
		{
			decayLabel.setText("Decay", juce::NotificationType::dontSendNotification);
			decayLabel.setJustificationType(juce::Justification::centred);

			addAndMakeVisible(decaySlider);
			addAndMakeVisible(decayLabel);
		}

		void resized() override
		{
			juce::FlexBox fb;
			if (getParentComponent()->getWidth() > getParentComponent()->getHeight())
			{
				decaySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
				decaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, NUM_TEXT_BOX_WIDTH, NUM_TEXT_BOX_HEIGHT);
			}
			else
			{
				decaySlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
				decaySlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, NUM_TEXT_BOX_WIDTH, NUM_TEXT_BOX_HEIGHT);
			}
			fb.flexDirection = juce::FlexBox::Direction::column;
			fb.justifyContent = juce::FlexBox::JustifyContent::spaceAround;

			juce::FlexItem sliderItem(SLIDER_WIDTH, SLIDER_HEIGHT, decaySlider);
			juce::FlexItem labelItem(LABEL_BOX_WIDTH, LABEL_BOX_HEIGHT, decayLabel);
			fb.items.addArray({sliderItem, labelItem});

			fb.performLayout(getLocalBounds());
		}

		juce::Slider decaySlider;
		juce::Label decayLabel;
	};

	struct sustainPanel : public juce::Component
	{
		sustainPanel()
		{
			sustainLabel.setText("Sustain", juce::NotificationType::dontSendNotification);
			sustainLabel.setJustificationType(juce::Justification::centred);

			addAndMakeVisible(sustainSlider);
			addAndMakeVisible(sustainLabel);
		}

		void resized() override
		{
			juce::FlexBox fb;
			if (getParentComponent()->getWidth() > getParentComponent()->getHeight())
			{
				sustainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
				sustainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, NUM_TEXT_BOX_WIDTH, NUM_TEXT_BOX_HEIGHT);
			}
			else
			{
				sustainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
				sustainSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, NUM_TEXT_BOX_WIDTH, NUM_TEXT_BOX_HEIGHT);
			}
			fb.flexDirection = juce::FlexBox::Direction::column;
			fb.justifyContent = juce::FlexBox::JustifyContent::spaceAround;

			juce::FlexItem sliderItem(SLIDER_WIDTH, SLIDER_HEIGHT, sustainSlider);
			juce::FlexItem labelItem(LABEL_BOX_WIDTH, LABEL_BOX_HEIGHT, sustainLabel);
			fb.items.addArray({sliderItem, labelItem});

			fb.performLayout(getLocalBounds());
		}

		juce::Slider sustainSlider;
		juce::Label sustainLabel;
	};

	struct releasePanel : public juce::Component
	{
		releasePanel()
		{
			releaseLabel.setText("Release", juce::NotificationType::dontSendNotification);
			releaseLabel.setJustificationType(juce::Justification::centred);

			addAndMakeVisible(releaseSlider);
			addAndMakeVisible(releaseLabel);
		}

		void resized() override
		{
			juce::FlexBox fb;
			if (getParentComponent()->getWidth() > getParentComponent()->getHeight())
			{
				releaseSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
				releaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, NUM_TEXT_BOX_WIDTH, NUM_TEXT_BOX_HEIGHT);
			}
			else
			{
				releaseSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
				releaseSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, NUM_TEXT_BOX_WIDTH, NUM_TEXT_BOX_HEIGHT);
			}
			fb.flexDirection = juce::FlexBox::Direction::column;
			fb.justifyContent = juce::FlexBox::JustifyContent::spaceAround;

			juce::FlexItem sliderItem(SLIDER_WIDTH, SLIDER_HEIGHT, releaseSlider);
			juce::FlexItem labelItem(LABEL_BOX_WIDTH, LABEL_BOX_HEIGHT, releaseLabel);
			fb.items.addArray({sliderItem, labelItem});

			fb.performLayout(getLocalBounds());
		}

		juce::Slider releaseSlider;
		juce::Label releaseLabel;
	};

	// panel objects
	attackPanel a_panel;
	decayPanel d_panel;
	sustainPanel s_panel;
	releasePanel r_panel;

	// slider attatchments
	std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackSliderAttatchment;
	std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> decaySliderAttatchment;
	std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sustainSliderAttatchment;
	std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttatchment;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(adsrUI)
};
