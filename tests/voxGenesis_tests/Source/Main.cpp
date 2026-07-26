#define CATCH_CONFIG_RUNNER
#include <catch2/catch_all.hpp>
#include <melatonin_test_helpers/melatonin_test_helpers.h>
#include <melatonin_audio_sparklines/melatonin_audio_sparklines.h>
#include <JuceHeader.h>
#include "E:/juce/voxGenesis/Source/PluginProcessor.h"

using namespace melatonin;

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc, argv);
}

TEST_CASE("buffer is empty after clear", "[audio]")
{
    VoxGenesisAudioProcessor testProcessor;
    testProcessor.prepareToPlay(48000, 512);
    juce::AudioBuffer<float> buffer(48000, 512);
    buffer.clear();

    juce::MidiBuffer midi;
    midi.addEvent(juce::MidiMessage::noteOn(1, 60, 0.8f), 0); // trigger note

    testProcessor.processBlock(buffer, midi);

    REQUIRE_THAT(buffer, isFilled());
}