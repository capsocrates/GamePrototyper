/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include <boost/optional.hpp>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
struct trait
{
    trait() = delete;
    std::string name;
    boost::optional<std::vector<std::string>> requirements;
    boost::optional<std::vector<std::string>> keywords;
    std::string effect;
};

class MainContentComponent   : public Component
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();

private:
    juce::TextButton load_xml;
    std::vector<trait> elements;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
