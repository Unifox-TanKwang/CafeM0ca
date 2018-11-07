/*
  ==============================================================================

    LoginComponent.h
    Created: 7 Nov 2018 5:12:22pm
    Author:  cafemoca

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class LoginComponent : public Component
{
public:
	LoginComponent() {
		addAndMakeVisible(id);
		id.setFont(Font(30.0f, Font::bold));
		id.setText("ID", dontSendNotification);
		id.setColour(Label::textColourId, Colours::black);
		id.setColour(Label::backgroundColourId, Colours::white);
		id.setJustificationType(Justification::centredLeft);
		id.setEditable(true);

		addAndMakeVisible(pw);
		pw.setFont(Font(30.0f, Font::bold));
		pw.setText("PW", dontSendNotification);
		pw.setColour(Label::textColourId, Colours::black);
		pw.setColour(Label::backgroundColourId, Colours::white);
		pw.setJustificationType(Justification::centredLeft);
		pw.setEditable(true);
	}
	~LoginComponent() {}
	void paint(Graphics& g) override {
		g.fillAll(Colours::black);
		g.drawRect(Rectangle<float>(0, 0, getWidth(), getHeight()), 3.0f);
	}
	void resized() override {
		int w = 3;
		id.setBounds(w, w, getWidth() - w, getHeight() / 2 - w);
		pw.setBounds(w, getHeight() / 2 + w, getWidth() - w, getHeight() / 2 - w);
	}
private:
	Label id, pw;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LoginComponent)
};
