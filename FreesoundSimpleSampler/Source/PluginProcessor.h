/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FreesoundAPI.h"

//==============================================================================
/**
*/

//class FSSamplerSound : public SamplerSound 
//{
//	FSSamplerSound(int sampleIndex);
//
//	bool appliesToNote(int) override { return true; }
//	bool appliesToChannel(int) override { return true; }
//
//};
//
//class FSSamplerVoice : public SamplerVoice
//{
//	FSSamplerVoice();
//
//};
//
//
//
//class SamplerAudioSource : public AudioSource
//{
//
//	SamplerAudioSource();
//	void prepareToPlay(int /*samplesPerBlockExpected*/, double sampleRate) override;
//	void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;
//
//private:
//	MidiKeyboardState& keyboardState;
//	Synthesiser sampler;
//};

class FreesoundSampler : public Synthesiser {
public:
	FreesoundSampler() { areSourcesSet = false; };
	void setSources(File tmpDownloadLocation);
	bool areSourcesSet;
private:
	AudioFormatManager audioFormatManager;
};

class FreesoundSimpleSamplerAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    FreesoundSimpleSamplerAudioProcessor();
    ~FreesoundSimpleSamplerAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //==============================================================================
    File tmpDownloadLocation;
    void newSoundsReady (Array<FSSound> sounds);

	void setSources();

private:

	std::vector<URL::DownloadTask*> downloadTasksToDelete;
	Synthesiser sampler;
	AudioFormatManager audioFormatManager;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FreesoundSimpleSamplerAudioProcessor)
};
