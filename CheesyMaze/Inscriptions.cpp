#include "Inscriptions.h"



Inscriptions::Inscriptions()
{
}


Inscriptions::~Inscriptions()
{
}

void Inscriptions::SetFont()
{
	font.loadFromFile("fonts/KOMIKAP_.ttf");
	numberOfCompleteTriesMessage.setFont(font);
	tryMessage.setFont(font);
	firstCompleteTryMessage.setFont(font);
}

void Inscriptions::SetInscriptions()
{
	tryMessage.setString("Podejscie = 1");
	firstCompleteTryMessage.setString("Pierwsze udane przejscie = 0");
	numberOfCompleteTriesMessage.setString("Udane razy : 0");
	tryMessage.setCharacterSize(20);
	firstCompleteTryMessage.setCharacterSize(20);
	numberOfCompleteTriesMessage.setCharacterSize(20);
	tryMessage.setFillColor(Color::White);
	firstCompleteTryMessage.setFillColor(Color::White);
	numberOfCompleteTriesMessage.setFillColor(Color::White);
	tryMessage.setPosition(800, 700);
	firstCompleteTryMessage.setPosition(800, 670);
	numberOfCompleteTriesMessage.setPosition(800, 640);
}

void Inscriptions::UpgInscriptions(int a, int b, int c)
{
	stringstream ss;
	ss << "Podejscie = " << a;
	tryMessage.setString(ss.str());


	stringstream se;
	se << "Pierwsze udane przejscie = " << b;
	firstCompleteTryMessage.setString(se.str());


	stringstream sr;
	sr << "Udane razy : " << c;
	numberOfCompleteTriesMessage.setString(sr.str());
}
