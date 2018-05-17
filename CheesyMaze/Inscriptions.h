#pragma once
#include <sstream>
#include <iostream>
#include "Graphics.h"

using namespace std;
using namespace sf;

class Inscriptions
{
public:
	Inscriptions();
	~Inscriptions();
	Text tryMessage;
	Text firstCompleteTryMessage;
	Text numberOfCompleteTriesMessage;
	Font font;
	void SetFont();
	void SetInscriptions();
	void UpgInscriptions(int a, int b, int c);

};

