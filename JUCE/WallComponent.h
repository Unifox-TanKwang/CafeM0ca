/*
  ==============================================================================

    WallComponent.h
    Created: 24 Oct 2018 5:05:06pm
    Author:  cafemoca

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class WallComponent : public Component 
{
public:
	WallComponent() 
		: wall_col1(Colours::sandybrown), wall_col2(Colours::saddlebrown) { }
	~WallComponent() {}
	void paint(Graphics& g) override {
		Rectangle<int> rect(0, 0, getWidth(), getHeight());
		g.fillCheckerBoard(getLocalBounds().toFloat(),30,10, wall_col1, wall_col2);
	}
	void resized() override {}
	inline void set_color(Colour c1, Colour c2) { wall_col1 = c1; wall_col2 = c2; }
private:
	Colour wall_col1, wall_col2;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WallComponent)
};