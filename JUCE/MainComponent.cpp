/*
  ==============================================================================

    This file was auto-generated!
  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (1000, 400);
	addAndMakeVisible(my_house);
	addAndMakeVisible(fairy_house);
	my_house.set_roofcol(Colours::aqua);
	fairy_house.set_wallcol(Colours::magenta, Colours::blanchedalmond);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(Colours::orangered);
	
    g.setFont (Font (46.0f));
    g.setColour (Colours::maroon);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centredRight, true);
	g.setColour(Colours::deepskyblue);
	g.drawLine(100, 370, 400, 370, 10.0f);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	fairy_house.setBounds(100, 50, 300, 300);
	my_house.setBounds(500, 100, 200, 400);
}
