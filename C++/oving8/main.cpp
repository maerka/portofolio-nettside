#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
#include "oppg1-2.h"
#include "CourseCatalog.h"
#include "oppg4.h"



int main() {
	//writeToFile();
	//addLineNumbers("file");
	//letterStatistics("file");

	map<string, string> planets;
	planets["Mercury"] = "Hot planet";
	planets["Venus"] = "Atmosphere of sulfuric acid";
	planets["Earth"] = "Home";
	planets["Mars"] = "The Red Planet";
	planets["Jupiter"] = "Largest planet in our solar system";
	planets["Saturn"] = "Has rings";
	planets["Uranus"] = "Tilts on its side";
	planets["Neptune"] = "1500 mile per hour winds";
	planets["Pluto"] = "Dwarf planet";

	CourseCatalog newCatalog = CourseCatalog(planets);
	newCatalog.addCourse("PlanetX", "Yet to be discovered");
	//cout << newCatalog << endl;
	newCatalog.removeCourse("Pluto");
	//cout << newCatalog << endl;
	//cout << newCatalog.getCourse("Jupiter") << endl;

	//oppg c
	newCatalog.addCourse("PlanetX", "NASA needs our help"); //Om addCourse oppdateres med ny info avhenger av hvilken 
	//cout << newCatalog << endl;								// metode man bruker i addCourse

	// oppg4
	textStatistics("higgsBosonBluesShort");

	return 0;
}