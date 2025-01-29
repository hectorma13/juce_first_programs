/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática
  Desarrollo en JUCE Framework (2024-2025)

  @file MainComponent.h
  @author Héctor Martín Álvarez alu0101714059@ull.edu.es
  @date 29/01/2025
  @brief MainComponent class declaration
  @bug There are no known bugs.
  @see https://juce.com/learn/documentation/
*/
#pragma once
#include <JuceHeader.h>

class MainComponent : public juce::AudioAppComponent {
 public:
  MainComponent();
  ~MainComponent() override;
  void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
  void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
  void releaseResources() override;
  void paint(juce::Graphics& g) override;
  void resized() override;
 private:
  // Slider object
  juce::Slider slider_1;
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
