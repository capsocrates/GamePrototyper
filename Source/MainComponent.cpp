/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

#include <boost/range/numeric.hpp>

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize(600, 400);

    const auto xml_file = juce::File("D:\\dev\\source\\SuddenMagic\\GamePrototyper\\test.xml");
    const auto xml = juce::ScopedPointer<juce::XmlElement>(juce::XmlDocument::parse(xml_file));

    forEachXmlChildElement(*xml, element)
    {
        const auto text = element->getAllSubText();
        m_xml_contents.push_back(text);
    }
}

MainContentComponent::~MainContentComponent()
{}

void MainContentComponent::paint(Graphics& g)
{
    g.fillAll(Colour(0xff001F36));

    g.setFont(Font(16.0f));
    g.setColour(Colours::white);
    const auto newline = juce::String("\n");
    const auto to_draw = boost::accumulate(
        m_xml_contents,
        juce::String(),
        [&newline](juce::String& left, const juce::String& right)
    {
        if (left.isNotEmpty())
        {
            left.append(newline, newline.length());
        }
        left.append(right, right.length());
        return left;
    }
    );
    g.drawMultiLineText(to_draw, 5, 5, getLocalBounds().getWidth() - 10);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
