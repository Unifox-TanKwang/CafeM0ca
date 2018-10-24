/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "RoofComponent.h"
#include "WallComponent.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class HouseComponent : public Component
{
public:
	HouseComponent()
	{
		addAndMakeVisible(roof);
		addAndMakeVisible(wall);
	}
	~HouseComponent() {}
	void paint(Graphics& g) override{
	}
	void resized() override{
		roof.setBounds(0,0,getWidth(), getHeight() / 7);
		wall.setBounds(0,getHeight() / 7 + 10, getWidth(), getHeight() - 10);
	}
	inline void set_roofcol(Colour c) { roof.set_color(c); }
	inline void set_wallcol(Colour c1, Colour c2) { wall.set_color(c1, c2); }
private:
	RoofComponent roof;
	WallComponent wall;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HouseComponent)
};
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
	HouseComponent my_house;
	HouseComponent fairy_house;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
