#include <iostream>
#include <fstream>
#include <string>
#include "Task.h"

using namespace std;

int main()
{
    Task Ranger_atelier = Task("Rangement_atelier", "Ranger atelier Annemasse selon la méthode 5s", 1);

    Ranger_atelier.advencement();

    Ranger_atelier.create_under_task(2, "Laver_toilettes", "récurer et brosser", 2);


    return 0;
}