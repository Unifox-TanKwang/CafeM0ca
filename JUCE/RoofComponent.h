/*
  ==============================================================================

    RoofComponent.h
    Created: 24 Oct 2018 5:04:53pm
    Author:  cafemoca

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class RoofComponent : public Component
{
public:
	RoofComponent():roof_col(Colours::red) { }
	~RoofComponent() {}
	void paint(Graphics& g) override {
		g.setColour(roof_col);
		Path roof;
		roof.addTriangle(0, getHeight(), getWidth(), getHeight(), getWidth() / 2, 0);
		g.fillPath(roof);
	}
	void resized() override {}
	inline void set_color(Colour c) { roof_col = c; }
private:
	Colour roof_col;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RoofComponent)
};