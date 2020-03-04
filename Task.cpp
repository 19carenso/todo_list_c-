#include <iostream>
#include <fstream>
#include <ctime>
#include "Task.h"
#include <fstream>
using namespace std;

Task::Task(std::string title, std::string description, int priority) :  m_title(title), m_description(description), m_priority(priority), m_over_task(0)
        {
            m_creation_date = time(0);

            m_status = "open";

            m_percentage = 0;


            ifstream identification("Number_of_Tasks.txt",ios::in); // On va garder un compte de toutes les tâches dans ce fichier afin de donner correctement des identifiants distincts deux à deux
            if(identification)
            {
                int new_id;
                //identification.seekg(0,ios::beg);
                //cout << identification.tellg() << endl;
                identification >> new_id;
                //cout << new_id << endl;
                new_id++;
                //cout << new_id << endl;
                m_id = new_id;
                identification.close();
            }

            ofstream incrementation("Number_of_Tasks.txt", ios::out | ios::trunc);
            if(incrementation)
            {  
                incrementation << m_id ;
                incrementation.close();
            }

            ofstream fichier("All_Tasks.txt", ios::out | ios::app); //il contiendra le titre, la description, le statut et le niveau de priorité de toutes les tâches, afin de pouvir faire des listing un peu globaux, il contiendra les sous tâches comme les tâches et ne fera donc pas la distinction entre les deux.
            if(fichier)
                {
                    fichier << m_id << ' ' << m_title << ' '  << m_status << ' ' << m_priority << endl;
                    fichier.close();
                }

            string m_id_string = to_string(m_id);
            m_backup_file = m_id_string + ".txt";
            m_commentary_file = m_id_string + "_commentaries" + ".txt";

            ofstream commentaries(m_commentary_file.c_str(), ios::out | ios::app);
            if (commentaries)
                {
                    commentaries << m_description << endl;
                    commentaries.close();
                }
        }

void Task::end_task()
{
 m_status = "closed";
 m_closing_date = time(0);
}

void Task::change_priority(int n)
{
    m_priority = n;
}

void Task::advencement()
{
    cout << "La tâche " << '"' << m_title << '"' << " est avancée à " << m_percentage << "%." << endl;
}

void Task::change_over_task(Task* new_over_task)
{
    m_over_task = new_over_task;
}

void Task::create_under_task(int id, string title, string description, int priority)
{
    m_under_tasks.push_back(new Task(title, description, priority));
    m_under_tasks.back()->change_over_task(this);
}

