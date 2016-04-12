/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

#include <boost/range/numeric.hpp>
#include <boost/tokenizer.hpp>

#include <sstream>

using boost_char_sep = boost::char_separator<char>;
static auto parse_requirements(std::string comma_delimited_requirements) -> std::vector<std::string>
{
    boost::tokenizer<boost_char_sep> tokens(comma_delimited_requirements, boost_char_sep(","));

    return{tokens.begin(), tokens.end()};
}

static auto parse_keywords(std::string comma_delimited_keywords) -> std::vector<std::string>
{
    boost::tokenizer<boost_char_sep> tokens(comma_delimited_keywords, boost_char_sep(","));

    return{tokens.begin(), tokens.end()};
}

auto operator<<(std::ostream& os, const trait& to_print) -> std::ostream&
{
    os << "NAME:\t" << to_print.name << "\n";
    if (to_print.requirements)
    {
        os << "REQUIRED KEYWORDS:\t";
        for (const std::string& requirement : to_print.requirements.value())
        {
            os << requirement << ",";
        }
        os << "\n";
    }
    if (to_print.keywords)
    {
        os << "KEYWORDS GAINED:\t";
        for (const std::string& keyword : to_print.keywords.value())
        {
            os << keyword << ",";
        }
        os << "\n";
    }
    os << "DESCRIPTION:\t" << to_print.effect;

    return os;
}

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize(600, 400);

    const auto xml_file = juce::File("D:\\dev\\source\\SuddenMagic\\GamePrototyper\\test.xml");
    const auto xml = juce::ScopedPointer<juce::XmlElement>(juce::XmlDocument::parse(xml_file));

    forEachXmlChildElement(*xml, element)
    {
        assert(element->hasAttribute("name"));
        assert(element->getChildByName("description") != nullptr);
        const auto dbg = element->getAllSubText();
        elements.emplace_back(
            trait{
                element->getStringAttribute("name").toStdString(),
                element->getChildByName("requirements") != nullptr ?
                boost::make_optional(parse_requirements(element->getChildByName("requirements")->getAllSubText().toStdString())) :
                boost::none,
                element->getChildByName("keywords") != nullptr ?
                boost::make_optional(parse_keywords(element->getChildByName("keywords")->getAllSubText().toStdString())) :
                boost::none,
                element->getChildByName("description")->getAllSubText().toStdString()
        }
        );
    }
}

MainContentComponent::~MainContentComponent()
{}

void MainContentComponent::paint(Graphics& g)
{
    g.fillAll(Colour(0xff001F36));

    g.setFont(Font(16.0f));
    g.setColour(Colours::white);
    const auto newline = std::string("\n");
    auto str_stream = std::stringstream();
    auto reset_str_stream = [&str_stream]()
    {
        str_stream.str("");
        str_stream.clear();
    };
    const auto to_draw = boost::accumulate(
        elements,
        std::string(),
        [&newline, &str_stream, &reset_str_stream](std::string& left, const trait& right)
    {
        if (left.empty())
        {
            left.append(newline);
        }
        str_stream << right;
        left.append(str_stream.str());
        reset_str_stream();
        return left;
    }
    );
    juce::String drawable(to_draw);
    g.drawMultiLineText(drawable, 5, 15, getLocalBounds().getWidth() - 10);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
