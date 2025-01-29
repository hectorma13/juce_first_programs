/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática
  Desarrollo en JUCE Framework (2024-2025)

  @file MainComponent.h
  @author Héctor Martín Álvarez alu0101714059@ull.edu.es
  @date 29/01/2025
  @brief This file contains the basic startup code for a JUCE application.
  @bug There are no known bugs.
  @see https://juce.com/learn/documentation/
*/
#include <JuceHeader.h>
#include "MainComponent.h"

class FirstProjectApplication : public juce::JUCEApplication {
 public:
  FirstProjectApplication() {}
  const juce::String getApplicationName() override {
    return ProjectInfo::projectName;
  }
  const juce::String getApplicationVersion() override {
    return ProjectInfo::versionString;
  }
  bool moreThanOneInstanceAllowed() override {
    return true;
  }
  void initialise(const juce::String& commandLine) override {
    mainWindow.reset(new MainWindow(getApplicationName()));
  }
  void shutdown() override {
    mainWindow = nullptr;
  }
  void systemRequestedQuit() override {
    quit();
  }
  void anotherInstanceStarted(const juce::String& commandLine) override {
  }
  class MainWindow : public juce::DocumentWindow {
   public:
    MainWindow(juce::String name)
        : DocumentWindow(name,
                         juce::Desktop::getInstance().getDefaultLookAndFeel()
                             .findColour(juce::ResizableWindow::backgroundColourId),
                         DocumentWindow::allButtons) {
      setUsingNativeTitleBar(true);
      setContentOwned(new MainComponent(), true);

#if JUCE_IOS || JUCE_ANDROID
      setFullScreen(true);
#else
      setResizable(true, true);
      centreWithSize(getWidth(), getHeight());
#endif
      setVisible(true);
    }
    void closeButtonPressed() override {
      JUCEApplication::getInstance()->systemRequestedQuit();
    }
   private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
  };
 private:
  std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION(FirstProjectApplication)
