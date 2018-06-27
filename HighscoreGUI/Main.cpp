#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <HighScore.h>

using namespace nana;

int main()
{
	HighScore* hs = new HighScore(5);

	hs->AddScore("AAA", 300);
	hs->AddScore("BBB", 200);
	hs->AddScore("CCC", 100);
	hs->AddScore("XXX", 666);
	hs->AddScore("DHN", 9999);

	hs->ShowScores();

	//Define a form.
	form fm;

	//Define a label and display a text.
	label lab{ fm, "<bold blue size=16>Scores</>" };
	lab.format(true);
	label score1{ fm, hs->GetScore(1)->GetName() + "\t" + to_string(hs->GetScore(1)->GetScore())};
	label score2{ fm, hs->GetScore(2)->GetName() + "\t" + to_string(hs->GetScore(2)->GetScore())};
	label score3{ fm, hs->GetScore(3)->GetName() + "\t" + to_string(hs->GetScore(3)->GetScore())};
	label score4{ fm, hs->GetScore(4)->GetName() + "\t" + to_string(hs->GetScore(4)->GetScore())};
	label score5{ fm, hs->GetScore(5)->GetName() + "\t" + to_string(hs->GetScore(5)->GetScore())};


	//Define a button and answer the click event.
	button btn{ fm, "Quit" };
	btn.events().click([&fm] {
		fm.close();
	});

	//Layout management
	fm.div("vert <><<><><weight=50% title>><score1><score2><score3><score4><score5><weight=24<><button><>><>");
	fm["title"] << lab;
	fm["score1"] << score1;
	fm["score2"] << score2;
	fm["score3"] << score3;
	fm["score4"] << score4;
	fm["score5"] << score5;
	fm["button"] << btn;
	fm.collocate();

	//Show the form
	fm.show();

	//Start to event loop process, it blocks until the form is closed.
	exec();
}