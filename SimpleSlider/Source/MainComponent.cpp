/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática
  Desarrollo en JUCE Framework (2024-2025)

  @file MainComponent.cpp
  @author Héctor Martín Álvarez alu0101714059@ull.edu.es
  @date 29/01/2025
  @brief MainComponent class implementation
  @bug There are no known bugs.
  @see https://juce.com/learn/documentation/
*/
#include "MainComponent.h"

MainComponent::MainComponent() {
  slider_1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
  slider_1.setTextBoxStyle(juce::Slider::TextBoxAbove, true, 50, 25);
  slider_1.setRange(0.0f, 1.0f, 0.1f);
  slider_1.setValue(0.5);
  addAndMakeVisible(slider_1);
  setSize(800, 600);
  if (juce::RuntimePermissions::isRequired(juce::RuntimePermissions::recordAudio)
      && !juce::RuntimePermissions::isGranted(juce::RuntimePermissions::recordAudio)) {
    juce::RuntimePermissions::request(juce::RuntimePermissions::recordAudio,
                                      [&](bool granted) { setAudioChannels(granted ? 2 : 0, 2); });
  } else {
    setAudioChannels(2, 2);
  }
}
MainComponent::~MainComponent() {
  shutdownAudio();
}
void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
}
void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) {
  bufferToFill.clearActiveBufferRegion();
}
void MainComponent::releaseResources() {
}
void MainComponent::paint(juce::Graphics& g) {
  g.fillAll(juce::Colours::black);
}
void MainComponent::resized() {
  slider_1.setBounds(getWidth() / 2 - 200, getHeight() / 2 - 100, 400, 200);
}
