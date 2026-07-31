
#include "PluginEditor.h"
#include "PluginProcessor.h"

#define XML

VoxGenesisAudioProcessorEditor::VoxGenesisAudioProcessorEditor(VoxGenesisAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p)
{
	#ifndef XML
	auto makeLayout = []()
	{
		return juce::ValueTree{
			"ComboBox",
			{
				{ "id", "combo" },
				{ "width", 80 },
				{ "height", 80 },
			},
		};
	};
	#endif


	#pragma region loadLayout

	#ifdef XML 
	auto layoutFile = juce::File("E:/juce/voxGenesis/Source/UI/layout.xml");

	std::unique_ptr<juce::XmlElement> xml;
	if (layoutFile.existsAsFile())
	{
		xml = juce::XmlDocument::parse(layoutFile);
	}
	else
	{
		xml = juce::XmlDocument::parse(BinaryData::layout_xml);
	}

	view = juce::ValueTree::fromXml(*xml);
	#endif

	#ifndef XML
	view = makeLayout();
	#endif

	rootItem = interpreter.interpret(view, &audioProcessor);

	auto mainComponent = rootItem.get()->getComponent().get();
	setSize(mainComponent->getWidth(), mainComponent->getHeight());
	//interpreter.listenTo(*rootItem);
	#pragma endregion


	// lambda to find a given parameter and bind it to the needed attatchment
	auto bindParameter = [&](const char* widgetID, const char* paramID)
	{
		auto* item = jive::findItemWithID(*rootItem, juce::Identifier(widgetID));

		if (item == nullptr) { return; }

		auto* param = audioProcessor.getState().getParameter(paramID);

		if (auto* slider = dynamic_cast<jive::Slider*>(item))
		{
			slider->attachToParameter(param, nullptr);
		}
		else if (auto* comboBox = dynamic_cast<jive::ComboBox*>(item))
		{
			comboBox->attachToParameter(param, nullptr);
		}
	};

	// lambda to get a component for access
	auto getComponent = [&](const char* componentID)
	{
		//todo finish this
	};

	bindParameter("_attack", "_attack");
	bindParameter("_decay", "_decay");
	bindParameter("_sustain", "_sustain");
	bindParameter("_release", "_release");
	bindParameter("wave-selector", "_osc1-wave-type");


	addAndMakeVisible(mainComponent);
	setResizable(true, false);
}

VoxGenesisAudioProcessorEditor::~VoxGenesisAudioProcessorEditor()
{}



void VoxGenesisAudioProcessorEditor::resized()
{
	if (rootItem != nullptr)
	{
		auto mainComponent = rootItem.get()->getComponent().get();
		mainComponent->setBounds(getLocalBounds());
	}
}
