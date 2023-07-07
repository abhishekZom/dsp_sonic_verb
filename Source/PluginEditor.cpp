/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Dsp_sonic_verbAudioProcessorEditor::Dsp_sonic_verbAudioProcessorEditor (Dsp_sonic_verbAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);

    // set slider object parameters
    midiVolume.setSliderStyle(juce::Slider::LinearBarVertical);
    midiVolume.setRange(0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled(true, false, this);
    midiVolume.setTextValueSuffix(" Volume");
    midiVolume.setValue(10.0);

    midiVolume.addListener(this);

    // add slider to the editor
    addAndMakeVisible(&midiVolume);
}

Dsp_sonic_verbAudioProcessorEditor::~Dsp_sonic_verbAudioProcessorEditor()
{
}

void Dsp_sonic_verbAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    audioProcessor.noteOnVel = midiVolume.getValue();
}

//==============================================================================
void Dsp_sonic_verbAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Midi Volume", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void Dsp_sonic_verbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
  midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}



